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
#include "../mcc_generated_files/spi1.h"

enum registers
{
    
    // Transmit & Receive Data Start Registers
    TXB0D0  = 0x36,
    TXB1D0  = 0x46,
    TXB2D0  = 0x56,
    RXB0D0  = 0x66,
    RXB1D0  = 0x76,
    
   // Can Control Registers 
    CANCTRL = 0x0F,
    RXF0SIDH = 0x00,
    RXF0SIDL = 0x01,
    RXF1SIDH = 0x04,
    RXF1SIDL = 0x05,
    RXF2SIDH = 0x08,
    RXF2SIDL = 0x09,
    RXF3SIDH = 0x10,
    RXF3SIDL = 0x11,
    RXF4SIDH = 0x14,
    RXF4SIDL = 0x15,
    
    // Data Length Registers
    TXB0DLC = 0x35,
    TXB1DLC = 0x45,
    TXB2DLC = 0x55,
    RXB0DLC = 0x65,
    RXB1DLC = 0x75,
    
    // ID Registers
    RXB0SIDH = 0x61,
    RXB0SIDL = 0x60,
    RXB1SIDH = 0x71,
    RXB1SIDL = 0x70,
    TXB0SIDH = 0x31,
    TXB0SIDL = 0x30,
    TXB1SIDH = 0x41,
    TXB1SIDL = 0x40,
    TXB2SIDH = 0x51,
    TXB2SIDL = 0x50
    
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

