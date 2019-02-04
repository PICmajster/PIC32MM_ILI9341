/*
    File Name:        :  spi1.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.10
    MPLAB             :  MPLAB X 5.10
    Created by        :  http://strefapic.blogspot.com
 */
#include <xc.h>
#include "spi1.h"

/**
 Section: File specific functions
*/

void SPI1_Initialize (void)
{
    uint8_t rData;
    SPI1STAT = 0x0; /*Status clear*/
    SPI1BRG = 0x5; /*SPI1BRG 0 --> set 2 MHz speed*/ 
    SPI1CON2 = 0x0; /*Stops and resets the SPI1.*/
    rData=SPI1BUF; /*clears buffer*/
    SPI1CONbits.DISSDI = 1; //SDI is not used
    SPI1CONbits.MSTEN = 1; //Master mode
    SPI1CONbits.CKE = 1 ; //must be
    SPI1CONbits.ON = 1; //SPI enabled   
}

/*only send, not used receive data*/
void SPI1_Send(uint8_t data)
{
  
    SPI1BUF = data;  
    
    while(SPI1STATbits.SPIBUSY == 1) /*SPI peripheral is currently busy with some transactions*/
    {
    }
   
}