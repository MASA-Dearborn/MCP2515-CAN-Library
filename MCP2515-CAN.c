/*
 * File:   MCP2515-CAN.c
 * Author: Lucas Ringe
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

#include "MCP2515-CAN.h"
#include <stdlib.h>
#define MAX_FRAME_LENGTH 8

/*
 *  Purpose: To transmit a buffer of up to 8-Bytes to the MCP2515 at a specified register address 
 *  Inputs:  The address for a register in MCP2515, a pointer to a dataBuffer, and the length of the data buffer
 */
void writeDataBuffer(uint8_t address, uint8_t* dataBuffer, uint8_t dataSize) 
{

    uint8_t dLength = dataSize + 2;
    uint8_t *dataToSend = malloc((dLength) * sizeof(uint8_t));
    
    dataToSend[0] = 0x02;
    dataToSend[1] = address;
    
    for(uint8_t i = 2; i < dLength; i++) 
    {
        dataToSend[i] = dataBuffer[i-2];
    }
    
    SPI1_Exchange8bitBuffer(dataToSend, dLength, 0);
    free(dataToSend);
    
}

void readData(uint8_t address, uint8_t* dataBuffer, uint8_t dataSize)
{
    
    uint8_t dataRead[MAX_FRAME_LENGTH];
    uint8_t dataOut[MAX_FRAME_LENGTH];
    
    dataOut[0] = 0x03;
    dataOut[1] = address;
    
    SPI1_Exchange8bitBuffer(dataOut, dataSize + 2, dataRead);
    
    for(uint8_t i = 0; i < dataSize; i++) 
    {
        dataBuffer[i] = dataRead[i];
    }
    
}

#include "xc.h"

