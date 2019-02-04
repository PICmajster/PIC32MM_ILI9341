/*
    File Name:        :  ili9341.h
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.10
    MPLAB             :  MPLAB X 5.10
    Created by        :  http://strefapic.blogspot.com
 */

#ifndef ILI9341_H
#define ILI9341_H
/*
     Signal LCD ---> MCU PIC32MM
   
     CS     (Chip Select)     --> Ground
     RESET                    --> RB11
     DC/RS  (Command / Data)  --> RC3
     MOSI   (Serial Data)     --> RD0
     SCK    (Serial Clock)    --> RB8
     
*/

#define DC_ON		PORTCbits.RC3 = 0;
#define DC_OFF	    PORTCbits.RC3 = 1; 
#define RESET_ON 	PORTBbits.RB11 = 0;
#define RESET_OFF 	PORTBbits.RB11 = 1; 

//LCD settings
#define	TFT_WIDTH	320
#define TFT_HEIGHT	240

#define ILI9341_PIXELS              76800U

#define MAX_X   239
#define MAX_Y   319

#define FONT_SPACE	6
#define FONT_X		8
#define FONT_Y		8

#define PORTRAIT	0
#define LANDSCAPE	1
#define PORTRAIT_REV  2
#define LANDSCAPE_REV  3

extern unsigned int max_x, max_y;
extern unsigned int bgcolor;
extern unsigned char rotation;
//extern unsigned int width , height;
extern int setMAX;

// RGB888 convert to RGB565 = 65k color
 #define RGB565(r,g,b) (((uint16_t)r & 0x00F8) << 8) | (((uint16_t)g & 0x00FC) << 3) | (((uint16_t)b & 0x00F8) >> 3) 
// RGB888 convert to RGB666 = 262k color
//#define RGB666(b,g,r) (((uint16_t)r & 0x00FC) << 8) | (((uint16_t)g & 0x00FC) << 2) | (((uint16_t)b & 0x00FC) >> 2) 

//==== STANDARD HTML/CSS/RGB COLOR NAMES BELOW =====
// Reds
#define INDIAN_RED              RGB565(205,  92,  92)
#define LIGHT_CORAL             RGB565(240, 128, 128)
#define SALMON                  RGB565(250, 128, 114)
#define DARK_SALMON             RGB565(233, 150, 122)
#define LIGHT_SALMON            RGB565(255, 160, 122)
#define CRIMSON                 RGB565(220,  20,  60)
#define RED                     RGB565(255,   0,   0)
#define FIRE_BRICK              RGB565(178,  34,  34)
#define DARK_RED                RGB565(139,   0,   0)
#define MAROON                  RGB565(128,   0,   0)

// Pinks
#define PINK                    RGB565(255, 192, 203)
#define LIGHT_PINK              RGB565(255, 182, 193)
#define HOT_PINK                RGB565(255, 105, 180)
#define DEEP_PINK               RGB565(255, 201, 147)
#define MEDIUM_VIOLET_RED       RGB565(199, 211, 133)
#define PALE_VIOLET_RED         RGB565(219, 112, 147)

// Oranges
#define LIGHT_SALMON            RGB565(255, 160, 122)
#define CORAL                   RGB565(255, 127,  80)
#define TOMATO                  RGB565(255,  99,  71)
#define ORANGE_RED              RGB565(255,  69,   0)
#define DARK_ORANGE             RGB565(255, 140,   0)
#define ORANGE                  RGB565(255, 165,   0)

// Yellows
#define GOLD                    RGB565(255, 215,   0)
#define YELLOW                  RGB565(255, 255,   0)
#define LIGHT_YELLOW            RGB565(255, 255, 244)
#define LEMON_CHIFFON           RGB565(255, 250, 205)
#define LIGHT_GOLDENROD_YELLOW 	RGB565(250, 250, 210)
#define PAPAYA_WHIP             RGB565(255, 239, 213)
#define MOCCASIN                RGB565(255, 228, 181)
#define PEACH_PUFF              RGB565(255, 218, 185)
#define PALE_GOLDENROD          RGB565(238, 232, 170)

// Greens
#define GREEN_YELLOW            RGB565(173, 255,  47)
#define CHARTREUSE              RGB565(127, 255,    )
#define LAWN_GREEN              RGB565(124, 255,   0)
#define LIME                    RGB565(  0, 255,   0)
#define LIME_GREEN              RGB565( 50, 205,  50)
#define PALE_GREEN              RGB565(152, 251, 152)
#define LIGHT_GREEN             RGB565(144, 238, 144)
#define MEDIUM_SPRING_GREEN 	RGB565(  0, 250, 154)
#define SPRING_GREEN            RGB565(  0, 255, 127)
#define MEDIUM_SEA_GREEN        RGB565( 60, 179, 113)
#define SEA_GREEN               RGB565( 46, 139,  87)
#define FOREST_GREEN            RGB565( 34, 139,  34)
#define GREEN                   RGB565(  0, 128,   0)
#define DARK_GREEN              RGB565(  0, 100,   0)
#define YELLOW_GREEN            RGB565(154, 205,  50)
#define OLIVE_DRAB              RGB565(107, 142,  35)
#define OLIVE                   RGB565(128, 128,   0)
#define DARK_OLIVE_GREEN        RGB565( 85, 107,  47)
#define MEDIUM_AQUAMARINE       RGB565(102, 205, 170)
#define DARK_SEA_GREEN          RGB565(143, 188, 143)
#define LIGHT_SEA_GREEN         RGB565( 32, 178, 170)

// Blues/Cyans
#define AQUA                    RGB565(  0, 255, 255)
#define CYAN                    RGB565(  0, 255, 255)
#define LIGHT_CYAN              RGB565(224, 255, 255)
#define DARK_CYAN               RGB565(  0, 139, 139)
#define TEAL                    RGB565(  0, 128, 128)
#define PALE_TURQUOISE          RGB565(175, 238, 238)
#define AQUAMARINE              RGB565(127, 255, 212)
#define TURQUOISE               RGB565( 64, 224, 208)
#define MEDIUM_TURQUOISE        RGB565( 72, 209, 204)
#define DARK_TURQUOISE          RGB565(  0, 206, 209)
#define CADET_BLUE              RGB565( 95, 158, 160)
#define STEEL_BLUE              RGB565( 70, 130, 180)
#define LIGHT_STEEL_BLUE        RGB565(176, 196, 222)
#define POWDER_BLUE             RGB565(176, 224, 230)
#define LIGHT_BLUE              RGB565(173, 216, 230)
#define SKY_BLUE                RGB565(135, 206, 235)
#define LIGHT_SKY_BLUE          RGB565(135, 206, 250)
#define DEEP_SKY_BLUE           RGB565(  0, 191, 255)
#define DODGER_BLUE             RGB565( 30, 144, 255)
#define CORNFLOWER_BLUE         RGB565(100, 149, 237)
#define MEDIUM_SLATE_BLUE       RGB565(123, 104, 238)
#define ROYAL_BLUE              RGB565( 65, 105, 225)
#define BLUE                    RGB565(  0,   0, 255)
#define MEDIUM_BLUE             RGB565(  0,   0, 205)
#define DARK_BLUE               RGB565(  0,   0, 139)
#define NAVY                    RGB565(  0,   0, 128)
#define MIDNIGHT_BLUE           RGB565( 25,  25, 112)

// Purples
#define LAVENDER                RGB565(230, 230, 250
#define THISTLE                 RGB565(216, 191, 216)
#define PLUM                    RGB565(221, 160, 221)
#define VIOLET                  RGB565(238, 130, 238)
#define ORCHID                  RGB565(218, 112, 214)
#define FUCHSIA                 RGB565(255,   0, 255)
#define MAGENTA                 RGB565(255,   0, 255)
#define MEDIUM_ORCHID           RGB565(186,  85, 211)
#define MEDIUM_PURPLE           RGB565(147, 112, 219)
#define AMETHYST                RGB565(153, 102, 204)
#define BLUE_VIOLET             RGB565(138,  43, 226)
#define DARK_VIOLET             RGB565(148,   0, 211)
#define DARK_ORCHID             RGB565(153,  50, 204)
#define DARK_MAGENTA            RGB565(139,   0, 139)
#define PURPLE                  RGB565(128,   0, 128)
#define INDIGO                  RGB565( 75,   0, 130)
#define SLATE_BLUE              RGB565(106,  90, 205)
#define DARK_SLATE_BLUE         RGB565( 72,  61, 139)
#define MEDIUM_SLATE_BLUE       RGB565(123, 104, 238)

// Browns
#define KHAKI                   RGB565(240, 230, 140)
#define DARK_KHAKI              RGB565(189, 183, 107)
#define CORNSILK                RGB565(255, 248, 220)
#define BLANCHED_ALMOND         RGB565(255, 235, 205)
#define BISQUE                  RGB565(255, 228, 196)
#define NAVAJO_WHITE            RGB565(255, 222, 173)
#define WHEAT                   RGB565(245, 222, 179)
#define BURLY_WOOD              RGB565(222, 184, 135)
#define TAN                     RGB565(210, 180, 140)
#define ROSY_BROWN              RGB565(188, 143, 143)
#define SANDY_BROWN             RGB565(244, 164,  96)
#define GOLDENROD               RGB565(218, 165,  32)
#define DARK_GOLDENROD          RGB565(184, 134,  11)
#define PERU                    RGB565(205, 133,  63)
#define CHOCOLATE               RGB565(210, 105,  30)
#define SADDLE_BROWN            RGB565(139,  69,  19)
#define SIENNA                  RGB565(160,  82,  45)
#define BROWN                   RGB565(165,  42,  42)

// Whites
#define WHITE                   RGB565(255, 255, 255)
#define SNOW                    RGB565(255, 250, 250)
#define HONEYDEW                RGB565(240, 255, 240)
#define MINT_CREAM              RGB565(245, 255, 250)
#define AZURE                   RGB565(240, 255, 255)
#define ALICE_BLUE              RGB565(240, 248, 255)
#define GHOST_WHITE             RGB565(248, 248, 255)
#define WHITE_SMOKE             RGB565(245, 245, 245)
#define SEASHELL                RGB565(255, 245, 238)
#define BEIGE                   RGB565(245, 245, 220)
#define OLD_LACE                RGB565(253, 245, 230)
#define FLORAL_WHITE            RGB565(255, 250, 240)
#define IVORY                   RGB565(255, 255, 240)
#define ANTIQUE_WHITE           RGB565(250, 235, 215)
#define LINEN                   RGB565(250, 240, 230)
#define LAVENDER_BLUSH          RGB565(255, 240, 245)
#define MISTY_ROSE              RGB565(255, 228, 225)

// Grays and Black
#define WHISPER                 RGB565(239, 230, 230)
#define GAINSBORO               RGB565(220, 220, 220)
#define LIGHT_GRAY              RGB565(211, 211, 211)
#define VERY_LIGHT_GRAY      	RGB565(205, 205, 205)
#define SILVER                  RGB565(192, 192, 192)
#define DARK_GRAY               RGB565(169, 169, 169)
#define NOBEL                   RGB565(169, 157, 157)
#define GRAY                    RGB565(128, 128, 128)
#define DIM_GRAY                RGB565(105, 105, 105)
#define ZAMBEZI                 RGB565( 96,  96,  96)
#define LIGHT_SLATE_GRAY        RGB565(119, 136, 153)
#define SLATE_GRAY              RGB565(112, 128, 144)
#define DARK_SLATE_GRAY         RGB565( 47,  79,  79)
#define ECLIPSE                 RGB565( 64,  64,  64)
#define NERO                    RGB565( 32,  32,  32)
#define BLACK                   RGB565(  0,   0,   0)

/* Level 1 Commands (from the display Datasheet) */
#define ILI9341_CMD_NOP                             0x00
#define ILI9341_CMD_SOFTWARE_RESET                  0x01
#define ILI9341_CMD_READ_DISP_ID                    0x04
#define ILI9341_CMD_READ_DISP_STATUS                0x09
#define ILI9341_CMD_READ_DISP_POWER_MODE            0x0A
#define ILI9341_CMD_READ_DISP_MADCTRL               0x0B
#define ILI9341_CMD_READ_DISP_PIXEL_FORMAT          0x0C
#define ILI9341_CMD_READ_DISP_IMAGE_FORMAT          0x0D
#define ILI9341_CMD_READ_DISP_SIGNAL_MODE           0x0E
#define ILI9341_CMD_READ_DISP_SELF_DIAGNOSTIC       0x0F
#define ILI9341_CMD_ENTER_SLEEP_MODE                0x10
#define ILI9341_CMD_SLEEP_OUT                       0x11
#define ILI9341_CMD_PARTIAL_MODE_ON                 0x12
#define ILI9341_CMD_NORMAL_DISP_MODE_ON             0x13
#define ILI9341_CMD_DISP_INVERSION_OFF              0x20
#define ILI9341_CMD_DISP_INVERSION_ON               0x21
#define ILI9341_CMD_GAMMA_SET                       0x26
#define ILI9341_CMD_DISPLAY_OFF                     0x28
#define ILI9341_CMD_DISPLAY_ON                      0x29
#define ILI9341_CMD_COLUMN_ADDRESS_SET              0x2A
#define ILI9341_CMD_PAGE_ADDRESS_SET                0x2B
#define ILI9341_CMD_MEMORY_WRITE                    0x2C
#define ILI9341_CMD_COLOR_SET                       0x2D
#define ILI9341_CMD_MEMORY_READ                     0x2E
#define ILI9341_CMD_PARTIAL_AREA                    0x30
#define ILI9341_CMD_VERT_SCROLL_DEFINITION          0x33
#define ILI9341_CMD_TEARING_EFFECT_LINE_OFF         0x34
#define ILI9341_CMD_TEARING_EFFECT_LINE_ON          0x35
#define ILI9341_CMD_MEMORY_ACCESS_CONTROL           0x36
#define ILI9341_CMD_VERT_SCROLL_START_ADDRESS       0x37
#define ILI9341_CMD_IDLE_MODE_OFF                   0x38
#define ILI9341_CMD_IDLE_MODE_ON                    0x39
#define ILI9341_CMD_COLMOD_PIXEL_FORMAT_SET         0x3A
#define ILI9341_CMD_WRITE_MEMORY_CONTINUE           0x3C
#define ILI9341_CMD_READ_MEMORY_CONTINUE            0x3E
#define ILI9341_CMD_SET_TEAR_SCANLINE               0x44
#define ILI9341_CMD_GET_SCANLINE                    0x45
#define ILI9341_CMD_WRITE_DISPLAY_BRIGHTNESS        0x51
#define ILI9341_CMD_READ_DISPLAY_BRIGHTNESS         0x52
#define ILI9341_CMD_WRITE_CTRL_DISPLAY              0x53
#define ILI9341_CMD_READ_CTRL_DISPLAY               0x54
#define ILI9341_CMD_WRITE_CONTENT_ADAPT_BRIGHTNESS	0x55
#define ILI9341_CMD_READ_CONTENT_ADAPT_BRIGHTNESS	0x56
#define ILI9341_CMD_WRITE_MIN_CAB_LEVEL             0x5E
#define ILI9341_CMD_READ_MIN_CAB_LEVEL              0x5F
#define ILI9341_CMD_READ_ID1                        0xDA
#define ILI9341_CMD_READ_ID2                        0xDB
#define ILI9341_CMD_READ_ID3                        0xDC
 
/* Level 2 Commands (from the display Datasheet) */
#define ILI9341_CMD_RGB_SIGNAL_CONTROL              0xB0
#define ILI9341_CMD_FRAME_RATE_CONTROL_NORMAL		0xB1
#define ILI9341_CMD_FRAME_RATE_CONTROL_IDLE_8COLOR	0xB2
#define ILI9341_CMD_FRAME_RATE_CONTROL_PARTIAL		0xB3
#define ILI9341_CMD_DISPLAY_INVERSION_CONTROL		0xB4
#define ILI9341_CMD_BLANKING_PORCH_CONTROL          0xB5
#define ILI9341_CMD_DISPLAY_FUNCTION_CONTROL		0xB6
#define ILI9341_CMD_ENTRY_MODE_SET                  0xB7
#define ILI9341_CMD_BACKLIGHT_CONTROL_1             0xB8
#define ILI9341_CMD_BACKLIGHT_CONTROL_2             0xB9
#define ILI9341_CMD_BACKLIGHT_CONTROL_3             0xBA
#define ILI9341_CMD_BACKLIGHT_CONTROL_4             0xBB
#define ILI9341_CMD_BACKLIGHT_CONTROL_5             0xBC
#define ILI9341_CMD_BACKLIGHT_CONTROL_6             0xBD
#define ILI9341_CMD_BACKLIGHT_CONTROL_7             0xBE
#define ILI9341_CMD_BACKLIGHT_CONTROL_8             0xBF
#define ILI9341_CMD_POWER_CONTROL_1                 0xC0
#define ILI9341_CMD_POWER_CONTROL_2                 0xC1
#define ILI9341_CMD_VCOM_CONTROL_1                  0xC5
#define ILI9341_CMD_VCOM_CONTROL_2                  0xC7
#define ILI9341_CMD_POWER_ON_SEQ_CONTROL            0xCB
#define ILI9341_CMD_POWER_CONTROL_A                 0xCD
#define ILI9341_CMD_POWER_CONTROL_B                 0xCF
#define ILI9341_CMD_NVMEM_WRITE                     0xD0
#define ILI9341_CMD_NVMEM_PROTECTION_KEY            0xD1
#define ILI9341_CMD_NVMEM_STATUS_READ               0xD2
#define ILI9341_CMD_READ_ID4                        0xD3
#define ILI9341_CMD_POSITIVE_GAMMA_CORRECTION		0xE0
#define ILI9341_CMD_NEGATIVE_GAMMA_CORRECTION		0xE1
#define ILI9341_CMD_DIGITAL_GAMMA_CONTROL_1         0xE2
#define ILI9341_CMD_DIGITAL_GAMMA_CONTROL_2         0xE3
#define ILI9341_CMD_DRIVER_TIMING_CONTROL_A         0xE8
#define ILI9341_CMD_DRIVER_TIMING_CONTROL_B         0xEA
#define ILI9341_CMD_ENABLE_3_GAMMA_CONTROL          0xF2
#define ILI9341_CMD_INTERFACE_CONTROL               0xF6
#define ILI9341_CMD_PUMP_RATIO_CONTROL              0xF7


void sendCmd(uint8_t data);
void sendData(uint8_t data);
void sendData16(uint16_t data);
void ili9341_init(void);
void setX(uint16_t x0,uint16_t x1);
void setY(uint16_t y0,uint16_t y1);
void setOrientation(int8_t orientation);
void bg(uint16_t color);
void fillRectangle(unsigned int x0, unsigned int y0, unsigned int length, unsigned int width, unsigned int color);
void hline(unsigned int x0, unsigned int y0, unsigned int length, unsigned int color);
void setXY(uint16_t x0, uint16_t y0);
void pixel(uint16_t x0, uint16_t y0, uint16_t color);
void line(unsigned int x0,unsigned int y0,unsigned int x1, unsigned int y1, unsigned int color);
void vline(unsigned int x0, unsigned int y0, unsigned int length, unsigned int color);
void rectangle(unsigned int x0, unsigned int y0, unsigned int length, unsigned int width, unsigned int color);
void circle(int x0, int y0, int r, unsigned int color);
void fillCircle(int x0, int y0, int r, unsigned int color);
void putChar(unsigned char ascii, unsigned int x0, unsigned int y0,unsigned int size, unsigned int fgcolor);
void putString(char *argstring, unsigned int x0, unsigned int y0, unsigned int size,unsigned int fgcolor);
void block(unsigned int x0, unsigned int y0, unsigned int howmany, unsigned int size, unsigned int fgcolor);
void clr(unsigned int x0, unsigned int y0, unsigned int size);
void clrLine(unsigned int y0, unsigned int size);
void barGraf(unsigned int x0, unsigned int y0, unsigned int howmany, unsigned int bar_max, unsigned int size, unsigned int fgcolor, unsigned int rectangle_color);
unsigned char putInteger(unsigned int val,unsigned int x0, unsigned int y0,unsigned int size,unsigned int fgcolor);
unsigned char putFloat(float floatNumber, unsigned int x0, unsigned int y0, unsigned int size, unsigned int fgcolor);
void eqGraf(char *string, unsigned int x0, unsigned int y0, unsigned int howmany, unsigned int size, unsigned int fgcolor, unsigned int rectangle_color);
void arc(int x, int y, int r, int startAngle, int endAngle, int thickness, unsigned int color);
void title(char *string, unsigned int size, unsigned int fgcolor, unsigned int bgcolor);
void setWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void DrawBitmapRGB565(const uint16_t *Imagedata, uint16_t width, uint16_t height, uint8_t x, uint8_t y);
void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
void drawCircleHelper( int16_t x0, int16_t y0,int16_t r, uint8_t cornername, uint16_t color);
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);

#endif	