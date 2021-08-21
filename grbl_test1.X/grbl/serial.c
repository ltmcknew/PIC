/*
  serial.c - Low level functions for sending and recieving bytes via the serial port
  Part of Grbl

  This file is now for general-purpose serial handling
  e.g. for the buffers, etc. 
  See e.g. serial_avr.c for architecture-specific code

  Copyright (c) 2011-2015 Sungeun K. Jeon
  Copyright (c) 2009-2011 Simen Svale Skogsrud

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "grbl.h"



uint8_t serial_rx_buffer[RX_BUFFER_SIZE];
uint8_t serial_rx_buffer_head = 0;
volatile uint8_t serial_rx_buffer_tail = 0;

uint8_t serial_tx_buffer[TX_BUFFER_SIZE];
uint8_t serial_tx_buffer_head = 0;
volatile uint8_t serial_tx_buffer_tail = 0;


#ifdef ENABLE_XONXOFF
  volatile uint8_t flow_ctrl = XON_SENT; // Flow control state variable
#endif
  

// Returns the number of bytes used in the RX serial buffer.
uint8_t serial_get_rx_buffer_count()
{
  uint8_t rtail = serial_rx_buffer_tail; // Copy to limit multiple calls to volatile
  if (serial_rx_buffer_head >= rtail) { return(serial_rx_buffer_head-rtail); }
  return (RX_BUFFER_SIZE - (rtail-serial_rx_buffer_head));
}


// Returns the number of bytes used in the TX serial buffer.
// NOTE: Not used except for debugging and ensuring no TX bottlenecks.
uint8_t serial_get_tx_buffer_count()
{
  uint8_t ttail = serial_tx_buffer_tail; // Copy to limit multiple calls to volatile
  if (serial_tx_buffer_head >= ttail) { return(serial_tx_buffer_head-ttail); }
  return (TX_BUFFER_SIZE - (ttail-serial_tx_buffer_head));
}

// serial_init() is very architecture-specific
// so it will be defined in the associated file, e.g. serial_avr.c
// See serial.h for a list of what it generally accomplishes...
//void serial_init()

#ifdef __BYTE_IDENTICAL_TEST__
 //This is "bad-practice", to include a c-file...
 //Doing it this way assures that the code is compiled into the same space
 //as the rest of serial.c, such that when it's linked, all of the original
 //code, including serial_init() will be identically-placed in the
 //program-memory. This is for testing-purposes, to make sure this
 //abstracted-version is byte-identical to the original.
 #include CONCAT_CFILE(serial_,__MCU_ARCH__)
#endif


// Writes one byte to the TX serial buffer. Called by main program.
// TODO: Check if we can speed this up for writing strings, rather than single bytes.
void serial_write(uint8_t data) {
  // Calculate next head
  uint8_t next_head = serial_tx_buffer_head + 1;
  if (next_head == TX_BUFFER_SIZE) { next_head = 0; }

  // Wait until there is space in the buffer
  while (next_head == serial_tx_buffer_tail) { 
    // TODO: Restructure st_prep_buffer() calls to be executed here during a long print.    
    if (sys_rt_exec_state & EXEC_RESET) { return; } // Only check for abort to avoid an endless loop.
  }

  // Store data and advance head
  serial_tx_buffer[serial_tx_buffer_head] = data;
  serial_tx_buffer_head = next_head;
  
  // Enable Data Register Empty Interrupt to make sure tx-streaming is running
  //UCSR0B |=  (1 << UDRIE0); 
  SERIAL_enableTxRegEmptyInterrupt();
}


// Data Register Empty Interrupt handler
// Note that this is #defined in e.g. serial_avr.h according to the
// architecture's ISR() name, etc...
// e.g.
//  #define SERIAL_TxRegEmptyInterrupt() ISR(SERIAL_UDRE)
// Doing it this way assures that no extra instructions are wasted in
// function-calling, pushing/popping registers, etc.
SERIAL_TxRegEmptyInterrupt()
{
  uint8_t tail = serial_tx_buffer_tail; // Temporary serial_tx_buffer_tail (to optimize for volatile)
 
  //Indicate that the interrupt has been acknowledged
  // (This isn't necessary on AVRs, so will result in no-instructions)
  SERIAL_clearTxRegEmptyFlag();


  #ifdef ENABLE_XONXOFF
    if (flow_ctrl == SEND_XOFF) { 
      //UDR0 = XOFF_CHAR; 
      SERIAL_loadTxRegAndBeginTransmission( XOFF_CHAR );
      flow_ctrl = XOFF_SENT; 
    } else if (flow_ctrl == SEND_XON) { 
      //UDR0 = XON_CHAR; 
      SERIAL_loadTxRegAndBeginTransmission( XON_CHAR );
      flow_ctrl = XON_SENT; 
    } 
    else
  #endif
  { 
    // Send a byte from the buffer	
    //UDR0 = serial_tx_buffer[tail];
    SERIAL_loadTxRegAndBeginTransmission( serial_tx_buffer[tail] );

    // Update tail position
    tail++;
    if (tail == TX_BUFFER_SIZE) { tail = 0; }
  
    serial_tx_buffer_tail = tail;
  }
  
  // Turn off Data Register Empty Interrupt to stop tx-streaming if this concludes the transfer
  if (tail == serial_tx_buffer_head) 
  { 
     //UCSR0B &= ~(1 << UDRIE0); 
     SERIAL_disableTxRegEmptyInterrupt();
  }
}


// Fetches the first byte in the serial read buffer. Called by main program.
uint8_t serial_read()
{
  uint8_t tail = serial_rx_buffer_tail; // Temporary serial_rx_buffer_tail (to optimize for volatile)
  if (serial_rx_buffer_head == tail) {
    return SERIAL_NO_DATA;
  } else {
    uint8_t data = serial_rx_buffer[tail];
    
    tail++;
    if (tail == RX_BUFFER_SIZE) { tail = 0; }
    serial_rx_buffer_tail = tail;
#ifndef __IGNORE_MEH_ERRORS__
 #error "I'm not sure how this forces Tx... need to look into this."
 //e.g. where does the actual Tx-XON byte get loaded...? Into the buffer?
 //     does it inject itself?
#endif
    #ifdef ENABLE_XONXOFF
      if ((serial_get_rx_buffer_count() < RX_BUFFER_LOW) && flow_ctrl == XOFF_SENT) { 
        flow_ctrl = SEND_XON;
        UCSR0B |=  (1 << UDRIE0); // Force TX
      }
    #endif
    
    return data;
  }
}



// Serial Data Received Interrupt handler
// Note that this is #defined in e.g. serial_avr.h according to the
// architecture's ISR() name, etc...
// e.g.
//  #define SERIAL_RxDataReceivedInterrupt() ISR(SERIAL_RX)
// Doing it this way assures that no extra instructions are wasted in
// function-calling, pushing/popping registers, etc.
SERIAL_RxDataReceivedInterrupt()
{
  //uint8_t data = UDR0;
  uint8_t data = SERIAL_readRxReg();

  uint8_t next_head;
  
  //This is only necessary for some MCUs...
  // e.g. AVR #define's this as nothing but '{}'
  SERIAL_clearRxDataReceivedFlag();


  // Pick off realtime command characters directly from the serial stream. These characters are
  // not passed into the buffer, but these set system state flag bits for realtime execution.
  switch (data) {
    case CMD_STATUS_REPORT: bit_true_atomic(sys_rt_exec_state, EXEC_STATUS_REPORT); break; // Set as true
    case CMD_CYCLE_START:   bit_true_atomic(sys_rt_exec_state, EXEC_CYCLE_START); break; // Set as true
    case CMD_FEED_HOLD:     bit_true_atomic(sys_rt_exec_state, EXEC_FEED_HOLD); break; // Set as true
    case CMD_SAFETY_DOOR:   bit_true_atomic(sys_rt_exec_state, EXEC_SAFETY_DOOR); break; // Set as true
    case CMD_RESET:         mc_reset(); break; // Call motion control reset routine.
    default: // Write character to buffer    
      next_head = serial_rx_buffer_head + 1;
      if (next_head == RX_BUFFER_SIZE) { next_head = 0; }
    
      // Write data to buffer unless it is full.
      if (next_head != serial_rx_buffer_tail) {
        serial_rx_buffer[serial_rx_buffer_head] = data;
        serial_rx_buffer_head = next_head;    
        
#ifndef __IGNORE_MEH_ERRORS__
 #error "I'm not sure how this forces Tx... need to look into this."
 //e.g. where does the actual Tx-XON byte get loaded...? Into the buffer?
 //     does it inject itself?
#endif
        #ifdef ENABLE_XONXOFF
          if ((serial_get_rx_buffer_count() >= RX_BUFFER_FULL) && flow_ctrl == XON_SENT) {
            flow_ctrl = SEND_XOFF;
            UCSR0B |=  (1 << UDRIE0); // Force TX
          } 
        #endif
        
      }
      //TODO: else alarm on overflow?
  }
}


void serial_reset_read_buffer() 
{
  serial_rx_buffer_tail = serial_rx_buffer_head;

  #ifdef ENABLE_XONXOFF
    flow_ctrl = XON_SENT;
  #endif
}

