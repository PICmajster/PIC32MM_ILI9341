/*
    File Name:        :  ili9341.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.10
    MPLAB             :  MPLAB X 5.10
    Created by        :  http://strefapic.blogspot.com
 */
#include "mcc_generated_files/mcc.h"
#include "delay.h"
#include <stdint.h> /*deklaracje uint8_t itp*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ili9341.h"
#include "font.h"

unsigned int bgcolor = BLACK;
unsigned int max_x, max_y;
unsigned char rotation;
int setMAX;

void sendCmd(uint8_t data)
{ // Write a command to Display
   DC_ON; 		
   SPI1_Send(data);  
   DC_OFF;
   }

void sendData(uint8_t data)
{
	DC_OFF; 		
	SPI1_Send(data); 
}

void sendData16(uint16_t data)
{
	unsigned char data1 = data>>8;
	unsigned char data2 = data&0xff;
	DC_OFF;
	SPI1_Send(data1);
	SPI1_Send(data2);
}

void ili9341_init(void)
{
	DC_OFF; 
    RESET_ON ;
	delayMs(50);
	RESET_OFF ;
    delayMs(50);
	sendCmd(ILI9341_CMD_POWER_ON_SEQ_CONTROL);
	sendData(ILI9341_CMD_IDLE_MODE_ON);
	sendData(ILI9341_CMD_MEMORY_WRITE);
	sendData(ILI9341_CMD_NOP);
	sendData(ILI9341_CMD_TEARING_EFFECT_LINE_OFF);
	sendData(0x02); 	

	sendCmd(ILI9341_CMD_POWER_CONTROL_B);
	sendData(ILI9341_CMD_NOP);
	sendData(ILI9341_CMD_POWER_CONTROL_2);
	sendData(ILI9341_CMD_PARTIAL_AREA);

	sendCmd(ILI9341_CMD_DRIVER_TIMING_CONTROL_A);
	sendData(0x85); 	
	sendData(ILI9341_CMD_NOP);
	sendData(0x78); 	

	sendCmd(ILI9341_CMD_DRIVER_TIMING_CONTROL_B);
	sendData(ILI9341_CMD_NOP);
	sendData(ILI9341_CMD_NOP);

	sendCmd(0xED);	
	sendData(0x64); 	
	sendData(0x03);	
	sendData(ILI9341_CMD_PARTIAL_MODE_ON);
	sendData(0X81); 	

	sendCmd(ILI9341_CMD_PUMP_RATIO_CONTROL);
	sendData(ILI9341_CMD_DISP_INVERSION_OFF);

	sendCmd(ILI9341_CMD_POWER_CONTROL_1);
	sendData(0x23);	

	sendCmd(ILI9341_CMD_POWER_CONTROL_2);
	sendData(ILI9341_CMD_ENTER_SLEEP_MODE);

	sendCmd(ILI9341_CMD_VCOM_CONTROL_1);
	sendData(ILI9341_CMD_READ_MEMORY_CONTINUE);
	sendData(ILI9341_CMD_DISPLAY_OFF);

	sendCmd(ILI9341_CMD_VCOM_CONTROL_2);
	sendData(0x86);	

	sendCmd(ILI9341_CMD_MEMORY_ACCESS_CONTROL);
	sendData(0x48);	

	sendCmd(ILI9341_CMD_COLMOD_PIXEL_FORMAT_SET);
	sendData(ILI9341_CMD_WRITE_CONTENT_ADAPT_BRIGHTNESS);

	sendCmd(ILI9341_CMD_FRAME_RATE_CONTROL_NORMAL);
	sendData(ILI9341_CMD_NOP);
	sendData(0x18); 	

	sendCmd(ILI9341_CMD_DISPLAY_FUNCTION_CONTROL);
	sendData(0x08); 	
	sendData(0x82);	
	sendData(0x27);	

	sendCmd(ILI9341_CMD_ENABLE_3_GAMMA_CONTROL);
	sendData(ILI9341_CMD_NOP);

	sendCmd(0x26);	
	sendData(ILI9341_CMD_SOFTWARE_RESET);

	sendCmd(ILI9341_CMD_POSITIVE_GAMMA_CORRECTION);
	sendData(0x0F); 	
	sendData(0x31);	
	sendData(ILI9341_CMD_PAGE_ADDRESS_SET);
	sendData(ILI9341_CMD_READ_DISP_PIXEL_FORMAT);
	sendData(ILI9341_CMD_READ_DISP_SIGNAL_MODE);
	sendData(0x08); 	
	sendData(0x4E); 	
	sendData(0xF1); 	
	sendData(ILI9341_CMD_VERT_SCROLL_START_ADDRESS);
	sendData(0x07); 	
	sendData(ILI9341_CMD_ENTER_SLEEP_MODE);
	sendData(0x03);	
	sendData(ILI9341_CMD_READ_DISP_SIGNAL_MODE);
	sendData(ILI9341_CMD_READ_DISP_STATUS);
	sendData(ILI9341_CMD_NOP);

	sendCmd(ILI9341_CMD_NEGATIVE_GAMMA_CORRECTION);
	sendData(ILI9341_CMD_NOP);
	sendData(ILI9341_CMD_READ_DISP_SIGNAL_MODE);
	sendData(0x14); 	
	sendData(0x03);	
	sendData(ILI9341_CMD_SLEEP_OUT);
	sendData(0x07); 	
	sendData(0x31); 	
	sendData(ILI9341_CMD_POWER_CONTROL_2);
	sendData(0x48); 	
	sendData(0x08); 	
	sendData(0x0F); 	
	sendData(ILI9341_CMD_READ_DISP_PIXEL_FORMAT);
	sendData(0x31); 	
	sendData(ILI9341_CMD_MEMORY_ACCESS_CONTROL);
	sendData(ILI9341_CMD_READ_DISP_SELF_DIAGNOSTIC);

	sendCmd(ILI9341_CMD_SLEEP_OUT);
	delayMs(120); 

	sendCmd(ILI9341_CMD_DISPLAY_ON);
	sendCmd(ILI9341_CMD_MEMORY_WRITE);
	
    setOrientation(PORTRAIT);
    bg(bgcolor);
    
}

void setX(uint16_t x0,uint16_t x1)
{
	sendCmd(ILI9341_CMD_COLUMN_ADDRESS_SET);
	sendData16(x0);
	sendData16(x1);
}

void setY(uint16_t y0,uint16_t y1)
{
	sendCmd(ILI9341_CMD_PAGE_ADDRESS_SET);
	sendData16(y0);
	sendData16(y1);
}

/* Set display rotation
 * 0 - up
 * 1 - right
 * 2 - down
 * 3 - left
 * */

void setOrientation(int8_t orientation)
{
    rotation = orientation;

    switch (orientation)
    {
        case PORTRAIT:														// up
            max_x  = TFT_HEIGHT;
            max_y = TFT_WIDTH;
            sendCmd(ILI9341_CMD_MEMORY_ACCESS_CONTROL);
            sendData(0x40 | 0x08);
            setMAX = MAX_X ;
            break;

        case LANDSCAPE:														// right
            max_x = TFT_WIDTH;
            max_y = TFT_HEIGHT;
            sendCmd(ILI9341_CMD_MEMORY_ACCESS_CONTROL);
            sendData(0x20 | 0x08);
            setMAX = MAX_Y ;
            break;

        case PORTRAIT_REV:													// down
            max_x = TFT_HEIGHT;
            max_y = TFT_WIDTH;
            sendCmd(ILI9341_CMD_MEMORY_ACCESS_CONTROL);
            sendData(0x80 | 0x08);
            setMAX = MAX_X ;
            break;

        case LANDSCAPE_REV:													//  left
            max_x = TFT_WIDTH;
            max_y = TFT_HEIGHT;
            sendCmd(ILI9341_CMD_MEMORY_ACCESS_CONTROL);
            sendData(0x40 | 0x80 | 0x20 | 0x08);
            setMAX = MAX_Y ;
            break;
    }
}

void hline(unsigned int x0, unsigned int y0, unsigned int length, unsigned int color)
{
		setX(x0,x0 + length);
		setY(y0,y0);
		sendCmd(ILI9341_CMD_MEMORY_WRITE);
		int i=0;
		for(i=0; i<length; i++)
			sendData16(color);
 }

void vline(unsigned int x0, unsigned int y0, unsigned int length, unsigned int color)
{
		setX(x0,x0);
		setY(y0,y0+length);
		sendCmd(ILI9341_CMD_MEMORY_WRITE);
		int i=0;
		for(i=0; i<length; i++)
			sendData16(color);
}

void fillRectangle(unsigned int x0, unsigned int y0, unsigned int length, unsigned int width, unsigned int color)
{
	int i;
    for(i=0;i<width;i++)
		hline(x0,y0+i,length,color);
}

void bg(uint16_t color)
{
	fillRectangle(0,0,max_x,max_y,color);
}

void setXY(uint16_t x0, uint16_t y0)
{
	setX(x0, x0);
	setY(y0, y0);
	sendCmd(ILI9341_CMD_MEMORY_WRITE);
}

void pixel(uint16_t x0, uint16_t y0, uint16_t color)
{
	if ((x0 > max_x) || (y0 > max_y)) return; // Nothing if out of the screen	
    setXY(x0, y0);
	sendData16(color);
}

void line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, unsigned int color)
{
	int x = x1-x0;
	int y = y1-y0;
	int dx = abs(x), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y), sy = y0<y1 ? 1 : -1;
	int err = dx+dy, e2;			// error value e_xy
	for (;;)
	{
		pixel(x0,y0,color);
		e2 = 2*err;
		if (e2 >= dy)			// e_xy+e_x > 0
		{
			if (x0 == x1)
				break;
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)	 		// e_xy+e_y < 0
		{
			if (y0 == y1) break;
			err += dx;
			y0 += sy;
		}
	}
}


void rectangle(unsigned int x0, unsigned int y0, unsigned int length, unsigned int width, unsigned int color)
{
	hline(x0, y0, length, color);
	hline(x0, y0+width, length, color);
	vline(x0, y0, width, color);
	vline(x0+length, y0, width, color);
}

void circle(int x0, int y0, int r, unsigned int color)
{
	int x = -r, y = 0, err = 2-2*r, e2;
	do
	{
		pixel(x0-x, y0+y,color);
		pixel(x0+x, y0+y,color);
		pixel(x0+x, y0-y,color);
		pixel(x0-x, y0-y,color);
		e2 = err;
		if (e2 <= y)
		{
			err += ++y*2+1;
			if (-x == y && e2 <= x)
				e2 = 0;
		}
		if (e2 > x)
			err += ++x*2+1;
	} while (x <= 0);
}

void fillCircle(int x0, int y0, int r, unsigned int color)
{
	int x = -r, y = 0, err = 2-2*r, e2;
	do
	{
		vline(x0-x, y0-y, 2*y, color);
		vline(x0+x, y0-y, 2*y, color);

		e2 = err;
		if (e2 <= y)
		{
			err += ++y*2+1;
			if (-x == y && e2 <= x) e2 = 0;
		}
		if (e2 > x)
			err += ++x*2+1;
	} while (x <= 0);
}

void putChar(unsigned char ascii, unsigned int x0, unsigned int y0, unsigned int size, unsigned int fgcolor)	
{
	        
    if((ascii>=32)&&(ascii<=127))	// Characters below 32 are not printable, there are 127 of them
	{
		;	// If printable do nothing
	}	
	else
	{
		// If not printable write junk
		ascii = '?'-32;		// ascii = 63-32=31
	}
	//clr(x0, y0, size);	// delete before printing
	int i;
	for (i =0; i<FONT_X; i++ )
	{
		unsigned char temp = simpleFont[ascii-32][i];	// because font.c starts at 0, not 32
		unsigned char f=0;
		for(f=0;f<8;f++)
		{
			if((temp>>f)&0x01)
				fillRectangle(x0+i*size, y0+f*size, size, size, fgcolor);
		}
	}
}

void putString(char *string, unsigned int x0, unsigned int y0, unsigned int size, unsigned int fgcolor)
{
		
    while(*string)
	{
		putChar(*string, x0, y0, size, fgcolor);
		string++;

		if(x0 < setMAX)
			x0 += FONT_SPACE*size;
	}
}

void block(unsigned int x0, unsigned int y0, unsigned int howmany, unsigned int size, unsigned int fgcolor)
{
	int j;
	for(j=0;j<howmany;j++)
	{
		int i;
		for (i =0; i<FONT_X; i++ )
		{
			unsigned char temp = simpleFont[96][i];	// block
			unsigned char f=0;
			for(f=0;f<8;f++)
			{
				if((temp>>f)&0x01)
					fillRectangle(x0+i*size, y0+f*size, size, size, fgcolor);
			}
		}
		if(x0 < setMAX)
			x0 += FONT_SPACE*size;
	}
}

void clr(unsigned int x0, unsigned int y0, unsigned int size) 
{
	fillRectangle(x0, y0, size*10, size*10, YELLOW);
}

void clrLine(unsigned int y0, unsigned int size)
{
	fillRectangle(0, y0-size, max_x, size*10, bgcolor);
}

void barGraf(unsigned int x0, unsigned int y0, unsigned int howmany, unsigned int bar_max, unsigned int size, unsigned int fgcolor, unsigned int rectangle_color)
{
	rectangle(x0, y0-size, FONT_SPACE*size*bar_max+size, FONT_Y*size+2*size-1, rectangle_color);
	block(x0, y0, howmany, size, fgcolor);
}

/*convert integer to string and view on LCD*/
unsigned char putInteger(unsigned int val,unsigned int x0, unsigned int y0,unsigned int size,unsigned int fgcolor)
    {
    char bufor[10];
    sprintf(bufor,"%i",val); /*konwersja val na string i zapis wyniku do bufora*/
    putString(bufor, x0, y0, size, fgcolor);
    }
 
/*aletrnatywa funkcji putInteger, mniej zasobów pamieci*/
//unsigned char putInteger(unsigned int long_num,unsigned int x0, unsigned int y0,unsigned int size,unsigned int fgcolor)
//{
//	unsigned char char_buffer[10] = "";
//	unsigned char i = 0;
//	unsigned char f = 0;
//  //
//	if (long_num < 0)
//	{
//		f=1;
//		putChar('-',x0, y0, size, fgcolor);
//		long_num = -long_num;
//			if(x0 < setMAX)
//				x0 += FONT_SPACE*size;
//	}
//	else if (long_num == 0)
//	{
//		f=1;
//		putChar('0',x0, y0, size, fgcolor);
//		return f;
//			if(x0 < setMAX)
//				x0 += FONT_SPACE*size;
//	}
//
//	// XXX If number has multiple digits and is written trough loop then last digit has to be deleted manually before reset 
//
//	while (long_num > 0)
//	{
//		char_buffer[i++] = long_num % 10;
//		long_num /= 10;
//	}
//
//	f = f+i;
//	for(; i > 0; i--)
//	{
//		putChar('0'+ char_buffer[i - 1],x0, y0, size, fgcolor);
//			if(x0 < setMAX)
//				x0 += FONT_SPACE*size;
//	}
//	return f;
//}

/*convert float to string and view on LCD*/
unsigned char putFloat(float floatNumber, unsigned int x0, unsigned int y0, unsigned int size, unsigned int fgcolor)
    {
    char bufor[10];
    sprintf(bufor,"%2.1f",floatNumber); /*konwersja val na string i zapis wyniku do bufora, jedno miejsce po przecinku jesli chcesz dwa miejsca to 1f zamie? na 2f*/
    putString(bufor, x0, y0, size, fgcolor);
    }

/*aletrnatywa funkcji putFloat, mniej zasobów pamieci*/
//unsigned char putFloat(float floatNumber, unsigned int x0, unsigned int y0, unsigned int size, unsigned int fgcolor)
//{
//	unsigned char decimal=1;
//	unsigned int temp=0;
//	float decy=0.0;
//	float rounding = 0.5;
//	unsigned char f=0;
//    unsigned char i;
//	if(floatNumber<0.0)
//	{
//		putChar('-',x0, y0, size, fgcolor);
//		floatNumber = -floatNumber;
//		if(x0 < setMAX)
//			x0 += FONT_SPACE*size;
//		f =1;
//	}
//	
//    for (i=0; i<decimal; ++i)
//		rounding /= 10.0;
//	floatNumber += rounding;
//
//	temp = (unsigned int)floatNumber;
//	unsigned char howlong=putInteger(temp,x0, y0, size, fgcolor);
//	f += howlong;
//	if((x0+8*size*howlong) < setMAX)
//		x0+=FONT_SPACE*size*howlong;
//	if(decimal>0)
//	{
//		putChar('.',x0, y0, size, fgcolor);
//		if(x0 < setMAX)
//			x0 += FONT_SPACE*size;
//		f +=1;
//	}
//	decy = floatNumber-temp;	// decimal part,
//	for(i=0;i<decimal;i++)
//	{
//		decy *=10;	// for the next decimal
//		temp = decy;	// get the decimal
//		putInteger(temp,x0, y0, size, fgcolor);
//		floatNumber = -floatNumber;
//			if(x0 < setMAX)
//				x0 += FONT_SPACE*size;
//		decy -= temp;
//	}
//	f += decimal;
//	return f;
//}

void eqGraf(char *string, unsigned int x0, unsigned int y0, unsigned int howmany, unsigned int size, unsigned int fgcolor, unsigned int rectangle_color)
{
	putString(string,x0,y0,size,fgcolor);

	unsigned int bar_max = 10;	
	unsigned int duzy = strlen(string)*size*FONT_SPACE;
	unsigned int nx0 = x0 + duzy;	// Shift for the length of string"
	
	barGraf(nx0, y0, howmany, bar_max, size, fgcolor, rectangle_color);

	unsigned int duzy2 = duzy + FONT_SPACE*size*bar_max+4*size;
	unsigned int nnx0 = x0 + duzy2;
	putInteger(howmany,nnx0,y0,size,fgcolor);
}

void arc(int x, int y, int r, int startAngle, int endAngle, int thickness, unsigned int color)
{
        int rDelta = -(thickness/2);
        int px, py, cx, cy; 
        int i,d;
        startAngle -= 90; 
        endAngle   -= 90; 
    
        if (startAngle!=endAngle)
        {   
                for (i=0; i<thickness; i++)
                {   
                        px = x + cos((startAngle*3.14)/180) * (r+rDelta+i);
                        py = y + sin((startAngle*3.14)/180) * (r+rDelta+i);
                        for (d=startAngle+1; d<endAngle+1; d++)
                        {   
                                cx = x + cos((d*3.14)/180) * (r+rDelta+i);
                                cy = y + sin((d*3.14)/180) * (r+rDelta+i);
				line(px, py, cx, cy, color);
                                px = cx; 
                                py = cy; 
                        }   
                }   
        }   
        else
        {   
                px = x + cos((startAngle*3.14)/180) * (r+rDelta);
                py = y + sin((startAngle*3.14)/180) * (r+rDelta);
                cx = x + cos((startAngle*3.14)/180) * (r-rDelta);
                cy = y + sin((startAngle*3.14)/180) * (r-rDelta);
		line(px, py, cx, cy, color);
        }   
}

void title(char *string, unsigned int size, unsigned int fgcolor, unsigned int bgcolor)
{
	unsigned int x0 = max_x/2 - (strlen(string)*size*FONT_SPACE)/2;
	unsigned int y0 = 0.5*size*FONT_SPACE;
	fillRectangle(0,0,max_x,2*size*FONT_SPACE,bgcolor);
	putString(string,x0,y0,size,fgcolor);
}


/* Set current drawing window */
void setWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    if ((x0 > max_x) || (y0 > max_y) || (x1 > max_x) || (y1 > max_y)) return;	// Nothing if out of the screen
        
    sendCmd(ILI9341_CMD_COLUMN_ADDRESS_SET);
    sendData(x0 >> 8);
    sendData(x0);
    sendData(x1 >> 8);
    sendData(x1);
    sendCmd(ILI9341_CMD_PAGE_ADDRESS_SET);
    sendData(y0 >> 8);
    sendData(y0);
    sendData(y1 >> 8);
    sendData(y1);
    sendCmd(ILI9341_CMD_MEMORY_WRITE);
}


void DrawBitmapRGB565(const uint16_t *Imagedata, uint16_t width, uint16_t height, uint8_t x, uint8_t y)
{
       
    uint16_t count;
    uint16_t rgb;
    
    setWindow(x, y, x + width - 1, y + height - 1);

/*Plot the bitmap data RGB656 16bit*/
    		for(count = width * height; count != 0; count--) //Write horizontal line
    		{
    			rgb = *Imagedata;
    			Imagedata++;
   			sendData16(rgb);

    		}

}



void drawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color) {
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x4) {
      pixel(x0 + x, y0 + y, color);
      pixel(x0 + y, y0 + x, color);
    }
    if (cornername & 0x2) {
      pixel(x0 + x, y0 - y, color);
      pixel(x0 + y, y0 - x, color);
    }
    if (cornername & 0x8) {
      pixel(x0 - y, y0 + x, color);
      pixel(x0 - x, y0 + y, color);
    }
    if (cornername & 0x1) {
      pixel(x0 - y, y0 - x, color);
      pixel(x0 - x, y0 - y, color);
    }
  }
}


// Draw a rounded rectangle
void drawRoundRect(int16_t x, int16_t y, int16_t w,int16_t h, int16_t r, uint16_t color) {
  // smarter version
  hline(x+r  , y    , w-2*r, color); // Top
  hline(x+r  , y+h-1, w-2*r, color); // Bottom
  vline(x    , y+r  , h-2*r, color); // Left
  vline(x+w-1, y+r  , h-2*r, color); // Right
  // draw four corners
  drawCircleHelper(x+r    , y+r    , r, 1, color);
  drawCircleHelper(x+w-r-1, y+r    , r, 2, color);
  drawCircleHelper(x+w-r-1, y+h-r-1, r, 4, color);
  drawCircleHelper(x+r    , y+h-r-1, r, 8, color);
}

// Used to do circles and roundrects
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) {

  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;

    if (cornername & 0x1) {
      vline(x0+x, y0-y, 2*y+1+delta, color);
      vline(x0+y, y0-x, 2*x+1+delta, color);
    }
    if (cornername & 0x2) {
      vline(x0-x, y0-y, 2*y+1+delta, color);
      vline(x0-y, y0-x, 2*x+1+delta, color);
    }
  }
}

// Fill a rounded rectangle
void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color) {
  // smarter version
  fillRectangle(x+r, y, w-2*r, h, color);

  // draw four corners
  fillCircleHelper(x+w-r-1, y+r, r, 1, h-2*r-1, color);
  fillCircleHelper(x+r    , y+r, r, 2, h-2*r-1, color);
}
