/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
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
 * 
 * More info at: http://ww1.microchip.com/downloads/en/DeviceDoc/MCP2515-Stand-Alone-CAN-Controller-with-SPI-20001801J.pdf
 * 
 */
 
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <spi1.h>

enum registers
{
    
    TXB0D0  = 0x36,
    TXB1D0  = 0x46,
    TXB2D0  = 0x56,
    RXB0D0  = 0x66,
    RXB1D0  = 0x76,
    CANCTRL = 0x0F
    
};

// External Commands
void CAN_Write(char* data);
void CAN_Read(char* data);

void CAN_Reset();
void CAN_LoadTX(char num);
void CAN_RTS(char num);
void CAN_getRXState();
void CAN_BitModify(char address, char* data);


#endif	/* XC_HEADER_TEMPLATE_H */

