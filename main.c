/*****************************************************************************
  FileName:        main.c
  Processor:       PIC32MM0256GPM048
  Compiler:        XC32 ver 2.10
  IDE :            MPLABX-IDE 5.10
  Created by:      http://strefapic.blogspot.com
 ******************************************************************************/
/*----------------------------------------------------------------------------*/
/* ILI9341 2.2 " 320x240  SPI                                                 */
/*----------------------------------------------------------------------------*/
// ** Sample application for PIC32MM **
//    
//	  Required connections for LCD ILI9163:
//    Signal LCD ---> MCU PIC32MM
//     CS     (Chip Select)     --> Ground
//     RESET                    --> RB11
//     DC/RS  (Command / Data)  --> RC3
//     MOSI   (Serial Data)     --> RD0
//     SCK    (Serial Clock)    --> RB8
//     LED                      --> +3.3V
//******************************************************************************
#include "mcc_generated_files/system.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "ili9341.h"
#include "heros.h"

int main(void)
{
    /* initialize the device */
    SYSTEM_Initialize();
    ili9341_init();
    setOrientation(LANDSCAPE); //PORTRAIT, LANSCAPE, PORTRAIT_REV, LANDSCAPE_REV
    
    //hline(10, 40, 50, YELLOW);
    //pixel(30,30,RED);
    //fillRectangle(10, 10, 60, 60, BLUE);
    //hline(50, 50, 150, WHITE);
    //circle(120, 120, 50, YELLOW);
    //putChar('A', 40, 20,3, YELLOW);
      putString("PIC32MM", 180, 30, 3, RED);
      putString("ILI9341", 205, 80, 2, ORANGE); 
      putString("strefapic.blogspot.com", 20, 200, 2,YELLOW); 
    //putInteger(1643,60, 120,3,YELLOW);
    //putFloat(124.7, 30, 37, 3, YELLOW);
    //block(30, 30, 6, 2, YELLOW);
    //barGraf(30, 160, 6, 20, 2, YELLOW, BLUE);
      eqGraf("Volume ", 30, 160, 4, 2, GREEN, RED);
      DrawBitmapRGB565(heros, 160, 128, 0, 0);
    //drawRoundRect(180, 30, 40,60, 15, YELLOW);
    //fillRoundRect(180, 30, 40, 60, 15, YELLOW);
    
    while (1)
    {
        
    }
   
}


