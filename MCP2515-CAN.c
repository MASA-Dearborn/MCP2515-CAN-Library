/*
 * File:   MCP2515-CAN.c
 * Author: zaner
 *
 * Created on February 27, 2020, 2:21 PM
 */

/*
 * MCP2515 Commands
 * RESET            = $C0
 * READ             = $03 - address - data read
 * READ RX BUFFER   = $9X   X = %0nm0
 * WRITE            = $02 - address - data to write
 * LOAD TX BUFFER   = $4X   X = %0abc
 * RTS              = $8X   X = %0nnn   TBX2, TBX1, TBX0
 * READ STATUS      = $A0
 * RX STATUS        = $B0
 * BIT MODIFY       = $05
 */

#define MAX_FRAME_LENGTH 10

void writeData(char address, char* dataBuffer, char dataSize) 
{

    char dataToSend[MAX_FRAME_LENGTH]; 
    
    dataToSend[0] = 0x02;
    dataToSend[1] = address;
    
    for(char i = 2; i < dataSize + 2; i++) 
    {
        dataToSend[i] = dataBuffer[i-2];
    }
    
    SPI1_Exchange8bitBuffer(dataToSend, dataSize + 2, 0);
    
}

void readData(char address, char* dataBuffer, char dataSize)
{
    
    char dataRead[MAX_FRAME_LENGTH];
    char dataOut[MAX_FRAME_LENGTH];
    
    dataOut[0] = 0x03;
    dataOut[1] = address;
    
    SPI1_Exchange8bitBuffer(dataOut, dataSize + 2, dataRead);
    
    for(int i = 0; i < dataSize; i++) 
    {
        dataBuffer[i] = dataRead[i];
    }
    
}

#include "xc.h"

