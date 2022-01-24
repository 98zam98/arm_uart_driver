/******************************************************************************
 * Module: UART
 * File Name: Hardware_arm_uart_driver.h
 * Version: 1
 * Date: 11/1/2022
 * Description: registers or connection with their macros and data types
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/
#ifndef __HARDWARE_ARM_UART_DRIVER_H__
#define __HARDWARE_ARM_UART_DRIVER_H__

/* UART*/


#define UART_BASE 0x40013800

/* USART_SR start */
#define USART_SR_OFFSET 0x00
#define USART_SR_BASE (UART_BASE + USART_SR_OFFSET)
#define USART_SR_REG (*(volatile u32 *)USART_SR_BASE)

/*
Bits 31:10 Reserved, forced by hardware to 0.
*/

#define CTS_USART_SR 9
/* 
Bit 9 CTS: CTS flag
This bit is set by hardware when the CTS input toggles, if the CTSE bit is set. It is cleared by
software (by writing it to 0). An interrupt is generated if CTSIE=1 in the USART_CR3
register.
0: No change occurred on the CTS status line
1: A change occurred on the CTS status line
This bit is not available for UART4 & UART5.

*/
#define LBD_USART_SR 8
/* 
Bit 8 LBD: LIN break detection flag
This bit is set by hardware when the LIN break is detected. It is cleared by software (by
writing it to 0). An interrupt is generated if LBDIE = 1 in the USART_CR2 register.
0: LIN Break not detected
1: LIN break detected
Note: An interrupt is generated when LBD=1 if LBDIE=1

*/
#define TXE_USART_SR 7
/* 
Bit 7 TXE: Transmit data register empty
This bit is set by hardware when the content of the TDR register has been transferred into
the shift register. An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register. It
is cleared by a write to the USART_DR register.
0: Data is not transferred to the shift register
1: Data is transferred to the shift register)
Note: This bit is used during single buffer transmission.

*/
#define TC_USART_SR 6
/* 
Bit 6 TC: Transmission complete
This bit is set by hardware if the transmission of a frame containing data is complete and if
TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by a
software sequence (a read from the USART_SR register followed by a write to the
USART_DR register). The TC bit can also be cleared by writing a '0' to it. This clearing
sequence is recommended only for multibuffer communication.
0: Transmission is not complete
1: Transmission is complete

*/

#define RXNE_USART_SR 5
/* 
Bit 5 RXNE: Read data register not empty
This bit is set by hardware when the content of the RDR shift register has been transferred to
the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
writing a zero to it. This clearing sequence is recommended only for multibuffer
communication.
0: Data is not received
1: Received data is ready to be read


*/
#define IDLE_USART_SR 4

/* 
Bit 4 IDLE: IDLE line detected
This bit is set by hardware when an Idle Line is detected. An interrupt is generated if the
IDLEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the
USART_SR register followed by a read to the USART_DR register).
0: No Idle Line is detected
1: Idle Line is detected
Note: The IDLE bit will not be set again until the RXNE bit has been set itself (i.e. a new idle
line occurs).

*/
#define ORE_USART_SR 3

/* 
Bit 3 ORE: Overrun error
This bit is set by hardware when the word currently being received in the shift register is
ready to be transferred into the RDR register while RXNE=1. An interrupt is generated if
RXNEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the
USART_SR register followed by a read to the USART_DR register).
0: No Overrun error
1: Overrun error is detected
Note: When this bit is set, the RDR register content will not be lost but the shift register will be
overwritten. An interrupt is generated on ORE flag in case of Multi Buffer
communication if the EIE bit is set.

*/
#define NE_USART_SR 2

/* 
Bit 2 NE: Noise error flag
This bit is set by hardware when noise is detected on a received frame. It is cleared by a
software sequence (an read to the USART_SR register followed by a read to the
USART_DR register).
0: No noise is detected
1: Noise is detected
Note: This bit does not generate interrupt as it appears at the same time as the RXNE bit
which itself generates an interrupting interrupt is generated on NE flag in case of Multi
Buffer communication if the EIE bit is set.

*/
#define FE_USART_SR 1

/* 
Bit 1 FE: Framing error
This bit is set by hardware when a de-synchronization, excessive noise or a break character
is detected. It is cleared by a software sequence (an read to the USART_SR register
followed by a read to the USART_DR register).
0: No Framing error is detected
1: Framing error or break character is detected
Note: This bit does not generate interrupt as it appears at the same time as the RXNE bit
which itself generates an interrupt. If the word currently being transferred causes both
frame error and overrun error, it will be transferred and only the ORE bit will be set.
An interrupt is generated on FE flag in case of Multi Buffer communication if the EIE bit
is set.

*/
#define PE_USART_SR 0

/* 
Bit 0 PE: Parity error
This bit is set by hardware when a parity error occurs in receiver mode. It is cleared by a
software sequence (a read to the status register followed by a read to the USART_DR data
register). The software must wait for the RXNE flag to be set before clearing the PE bit.
An interrupt is generated if PEIE = 1 in the USART_CR1 register.
0: No parity error
1: Parity error
*/
/* USART_SR end */
//--------------------------------------



/* USART_DR start */
#define USART_DR_OFFSET 0x04
#define USART_DR_BASE (UART_BASE + USART_DR_OFFSET)
#define USART_DR_REG (*(volatile u32 *)USART_DR_BASE)
#define USART_Data_value_USART_DR_BYTE (*(volatile u8 *)USART_DR_BASE)


/*
Bits 31:9 Reserved, forced by hardware to 0.

*/
/* 
Bits 8:0 DR[8:0]: Data value
Contains the Received or Transmitted data character, depending on whether it is read from
or written to.
The Data register performs a double function (read and write) since it is composed of two
registers, one for transmission (TDR) and one for reception (RDR)
The TDR register provides the parallel interface between the internal bus and the output
shift register (see Figure 1).
The RDR register provides the parallel interface between the input shift register and the
internal bus.
When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
because it is replaced by the parity.
When receiving with the parity enabled, the value read in the MSB bit is the received parity
bit.
*/
/* USART_DR end */
//--------------------------------------



/* USART_BRR start */
#define USART_BRR_OFFSET 0x08
#define USART_BRR_BASE (UART_BASE + USART_BRR_OFFSET)
#define USART_BRR_REG (*(volatile u32 *)USART_BRR_BASE)

/*
Bits 31:16 Reserved, forced by hardware to 0.

*/
#define USART_DIV_Mantissa_USART_BRR_REG (*(volatile u16 *)USART_BRR_BASE)
// config after fraction
/* 
Bits 15:4 DIV_Mantissa[11:0]: mantissa of USARTDIV
These 12 bits define the mantissa of the USART Divider (USARTDIV)

*/
#define USART_DIV_Fraction_USART_BRR_REG (*(volatile u8 *)USART_BRR_BASE)
// config before mantissa
/* 
Bits 3:0 DIV_Fraction[3:0]: fraction of USARTDIV
These 4 bits define the fraction of the USART Divider (USARTDIV)
*/
/* USART_BRR end */
//--------------------------------------



/* USART_CR1 start */
#define USART_CR1_OFFSET 0x0C
#define USART_CR1_BASE (UART_BASE + USART_CR1_OFFSET)
#define USART_CR1_REG (*(volatile u32 *)USART_CR1_BASE)

/*
Bits 31:14 Reserved, forced by hardware to 0.

*/
#define UE_USART_CR1 13
/* 
Bit 13 UE: USART enable
When this bit is cleared the USART prescalers and outputs are stopped and the end of the
current
byte transfer in order to reduce power consumption. This bit is set and cleared by software.
0: USART prescaler and outputs disabled
1: USART enabled

*/
#define M_Word_length_USART_CR1 12

/* 
Bit 12 M: Word length
This bit determines the word length. It is set or cleared by software.
0: 1 Start bit, 8 Data bits, n Stop bit
1: 1 Start bit, 9 Data bits, n Stop bit
Note: The M bit must not be modified during a data transfer (both transmission and reception)

*/
#define WAKE_Wakeup_method_USART_CR1 11

/* 
Bit 11 WAKE: Wakeup method
This bit determines the USART wakeup method, it is set or cleared by software.
0: Idle Line
1: Address Mark

*/
#define PCE_Parity_control_enable_USART_CR1 10
/* 
Bit 10 PCE: Parity control enable
This bit selects the hardware parity control (generation and detection). When the parity
control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
if M=0) and parity is checked on the received data. This bit is set and cleared by software.
Once it is set, PCE is active after the current byte (in reception and in transmission).
0: Parity control disabled
1: Parity control enabled

*/
#define PS_Parity_selection_USART_CR1 9

/* 
Bit 9 PS: Parity selection
This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
bit set). It is set and cleared by software. The parity will be selected after the current byte.
0: Even parity
1: Odd parity

*/
#define PEIE_PE_interrupt_enable_USART_CR1 8

/* 
Bit 8 PEIE: PE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever PE=1 in the USART_SR register

*/
#define TXEIE_TXE_interrupt_enable_USART_CR1 7
/* 
Bit 7 TXEIE: TXE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
*/
#define TCIE_Transmission_complete_interrupt_enable_USART_CR1 6
/* 

Bit 6 TCIE: Transmission complete interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever TC=1 in the USART_SR register

*/
#define RXNEIE_RXNE_interrupt_enable_USART_CR1 5
/* 
Bit 5 RXNEIE: RXNE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register

*/
#define IDLEIE_IDLE_interrupt_enable_USART_CR1 4
/* 
Bit 4 IDLEIE: IDLE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever IDLE=1 in the USART_SR register

*/
#define TE_Transmitter_enable_USART_CR1 3
/* 
Bit 3 TE: Transmitter enable
This bit enables the transmitter. It is set and cleared by software.
0: Transmitter is disabled
1: Transmitter is enabled
Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble
(idle line) after the current word, except in Smartcard mode.
2: When TE is set there is a 1 bit-time delay before the transmission starts.

*/
#define RE_Receiver_enable_USART_CR1 2
/* 
Bit 2 RE: Receiver enable
This bit enables the receiver. It is set and cleared by software.
0: Receiver is disabled
1: Receiver is enabled and begins searching for a start bit

*/
#define RWU_Receiver_wakeup 1
/* 
Bit 1 RWU: Receiver wakeup
This bit determines if the USART is in mute mode or not. It is set and cleared by software and
can be cleared by hardware when a wakeup sequence is recognized.
0: Receiver in active mode
1: Receiver in mute mode
Note: 1: Before selecting Mute mode (by setting the RWU bit) the USART must first receive a
data byte, otherwise it cannot function in Mute mode with wakeup by Idle line detection.
2: In Address Mark Detection wakeup configuration (WAKE bit=1) the RWU bit cannot
be modified by software while the RXNE bit is set.

*/
#define SBK_Send_break_USART_CR1 0
/* 
Bit 0 SBK: Send break
This bit set is used to send break characters. It can be set and cleared by software. It should
be set by software, and will be reset by hardware during the stop bit of break.
0: No break character is transmitted
1: Break character will be transmitted
*/
/* USART_CR1 end */
//--------------------------------------





/* USART_CR2 start */
#define USART_CR2_OFFSET 0x10
#define USART_CR2_BASE (UART_BASE + USART_CR2_OFFSET)
#define USART_CR2_REG (*(volatile u32 *)USART_CR2_BASE)

/*
Bits 31:15 Reserved, forced by hardware to 0.

*/
#define LINEN_LIN_mode_enable_USART_CR2 14
/* 
Bit 14 LINEN: LIN mode enable
This bit is set and cleared by software.
0: LIN mode disabled
1: LIN mode enabled
The LIN mode enables the capability to send LIN Synch Breaks (13 low bits) using the SBK
bit in the USART_CR1 register, and to detect LIN Sync breaks.

*/
#define STOP_1_2_STOP_bits_USART_CR2 13
#define STOP_5_STOP_bits_USART_CR2 12
/* 
Bits 13:12 STOP: STOP bits
These bits are used for programming the stop bits.
00: 1 Stop bit
01: 0.5 Stop bit
10: 2 Stop bits
11: 1.5 Stop bit
The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.

*/

#define CLKEN_Clock_enable_USART_CR2 11
/* 
Bit 11 CLKEN: Clock enable
This bit allows the user to enable the CK pin.
0: CK pin disabled
1: CK pin enabled
This bit is not available for UART4 & UART5.

*/

#define CPOL_Clock_polarity_USART_CR2 10
/* 

 These 3 bits (CPOL, CPHA, LBCL) should not be written while the transmitter is enabled.
Bit 10 CPOL: Clock polarity
This bit allows the user to select the polarity of the clock output on the CK pin in synchronous
mode. It works in conjunction with the CPHA bit to produce the desired clock/data
relationship
0: Steady low value on CK pin outside transmission window.
1: Steady high value on CK pin outside transmission window.
This bit is not available for UART4 & UART5.

*/

#define CPHA_Clock_phase_USART_CR2 9
/* 
Bit 9 CPHA: Clock phase
This bit allows the user to select the phase of the clock output on the CK pin in synchronous
mode. It works in conjunction with the CPOL bit to produce the desired clock/data
relationship (see figures 290 to 291)
0: The first clock transition is the first data capture edge.
1: The second clock transition is the first data capture edge.
This bit is not available for UART4 & UART5

*/

#define LBCL_Last_bit_clock_pulse_USART_CR2 8
/* 
Bit 8 LBCL: Last bit clock pulse
This bit allows the user to select whether the clock pulse associated with the last data bit
transmitted (MSB) has to be output on the CK pin in synchronous mode.
0: The clock pulse of the last data bit is not output to the CK pin
1: The clock pulse of the last data bit is output to the CK pin
The last bit is the 8th or 9th data bit transmitted depending on the 8 or 9 bit format selected
by the M bit in the USART_CR1 register.
This bit is not available for UART4 & UART5.

*/
/* 
Bit 7 Reserved, forced by hardware to 0.

*/

#define LBDIE_LIN_break_detection_interrupt_enable_USART_CR2 6
/* 
Bit 6 LBDIE: LIN break detection interrupt enable
Break interrupt mask (break detection using break delimiter).
0: Interrupt is inhibited
1: An interrupt is generated whenever LBD=1 in the USART_SR register

*/

#define LBDL_lin_break_detection_length_USART_CR2 5
/* 
Bit 5 LBDL: lin break detection length
This bit is for selection between 11 bit or 10 bit break detection.
0: 10 bit break detection
1: 11 bit break detection

*/
/* 
Bit 4 Reserved, forced by hardware to 0.

*/
#define ADD_Address_of_the_USART_node_USART_CR2_OFFSET 0x00
#define ADD_Address_of_the_USART_node_USART_CR2_BASE (USART_CR2_BASE + ADD_Address_of_the_USART_node_USART_CR2_OFFSET)
#define ADD_Address_of_the_USART_node_USART_CR2_BYTE (*(volatile u8 *)ADD_Address_of_the_USART_node_USART_CR2_BASE)
// BEFORE OTHER BITS
/* 
Bits 3:0 ADD[3:0]: Address of the USART node
This bit-field gives the address of the USART node.
This is used in multiprocessor communication during mute mode, for wake up with address
mark detection.
*/
/* USART_CR2 end */
//--------------------------------------





/* USART_CR3 start */
#define USART_CR3_OFFSET 0x14
#define USART_CR3_BASE (UART_BASE + USART_CR3_OFFSET)
#define USART_CR3_REG (*(volatile u32 *)USART_CR3_BASE)

/*
Bits 31:11 Reserved, forced by hardware to 0.

*/

#define CTSIE_CTS_interrupt_enable_USART_CR3 10
/* 
Bit 10 CTSIE: CTS interrupt enable
0: Interrupt is inhibited
1: An interrupt is generated whenever CTS=1 in the USART_SR register
This bit is not available for UART4 & UART5.

*/

#define CTSE_CTS_enable_USART_CR3 9
/* 
Bit 9 CTSE: CTS enable
0: CTS hardware flow control disabled
1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
the CTS input is deasserted while a data is being transmitted, then the transmission is
completed before stopping. If a data is written into the data register while CTS is deasserted,
the transmission is postponed until CTS is asserted.
This bit is not available for UART4 & UART5.

*/

#define RTSE_RTS_enable_USART_CR3 8
/* 
Bit 8 RTSE: RTS enable
0: RTS hardware flow control disabled
1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
The transmission of data is expected to cease after the current character has been
transmitted. The RTS output is asserted (tied to 0) when a data can be received.
This bit is not available for UART4 & UART5.

*/

#define DMAT_DMA_enable_transmitter_USART_CR3 7
/* 
Bit 7 DMAT: DMA enable transmitter
This bit is set/reset by software
1: DMA mode is enabled for transmission
0: DMA mode is disabled for transmission
This bit is not available for UART5.

*/

#define DMAR_DMA_enable_receiver_USART_CR3 6
/* 
Bit 6 DMAR: DMA enable receiver
This bit is set/reset by software
1: DMA mode is enabled for reception
0: DMA mode is disabled for reception
This bit is not available for UART5.

*/

#define SCEN_Smartcard_mode_enable_USART_CR3 5
/* 
Bit 5 SCEN: Smartcard mode enable
This bit is used for enabling Smartcard mode.
0: Smartcard Mode disabled
1: Smartcard Mode enabled
This bit is not available for UART4 & UART5.

*/

#define NACK_Smartcard_NACK_enable_USART_CR3 4
/* 
Bit 4 NACK: Smartcard NACK enable
0: NACK transmission in case of parity error is disabled
1: NACK transmission during parity error is enabled
This bit is not available for UART4 & UART5.

*/

#define HDSEL_Half_duplex_selection_USART_CR3 3
/* 
Bit 3 HDSEL: Half-duplex selection
Selection of Single-wire Half-duplex mode
0: Half duplex mode is not selected
1: Half duplex mode is selected

*/

#define IrDA_IRLP_USART_CR3 2
/* 
Bit 2 IRLP: IrDA low-power
This bit is used for selecting between normal and low-power IrDA modes
0: Normal mode
1: Low-power mode

*/

#define IrDA_IREN_USART_CR3 1
/* 
Bit 1 IREN: IrDA mode enable
This bit is set and cleared by software.
0: IrDA disabled
1: IrDA enabled

*/

#define EIE_Error_interrupt_enable_USART_CR3 0
/* 
Bit 0 EIE: Error interrupt enable
Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing
error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in
case of Multi Buffer Communication (DMAR=1 in the USART_CR3 register).
0: Interrupt is inhibited
1: An interrupt is generated whenever DMAR=1 in the USART_CR3 register and FE=1 or
ORE=1 or NE=1 in the USART_SR register
*/
/* USART_CR3 end */
//--------------------------------------



/* USART_GTPR start */
#define USART_GTPR_OFFSET 0x18
#define USART_GTPR_BASE (UART_BASE + USART_GTPR_OFFSET)
#define USART_GTPR_REG (*(volatile u32 *)USART_GTPR_BASE)

/*
Bits 31:16 Reserved, forced by hardware to 0.

*/
#define GT_Guard_time_value_USART_GTPR_OFFSET 8
#define GT_Guard_time_value_USART_GTPR_BASE (USART_GTPR_BASE + GT_Guard_time_value_USART_GTPR_OFFSET)
#define GT_Guard_time_value_USART_GTPR_OFFSET_BYTE (*(volatile u8 *)GT_Guard_time_value_USART_GTPR_BASE)
/* 
Bits 15:8 GT[7:0]: Guard time value
This bit-field gives the Guard time value in terms of number of baud clocks.
This is used in Smartcard mode. The Transmission Complete flag is set after this guard time
value.
This bit is not available for UART4 & UART5.

*/
#define PSC_Prescaler_value_USART_GTPR_OFFSET 0x00
#define PSC_Prescaler_value_USART_GTPR_BASE (USART_GTPR_BASE + PSC_Prescaler_value_USART_GTPR_OFFSET)
#define PSC_Prescaler_value_USART_GTPR_BYTE (*(volatile u8 *)PSC_Prescaler_value_USART_GTPR_BASE)
/* 
Bits 7:0 PSC[7:0]: Prescaler value
– In IrDA Low-power mode:
PSC[7:0] = IrDA Low-Power Baud Rate
Used for programming the prescaler for dividing the system clock to achieve the low-power
frequency:
The source clock is divided by the value given in the register (8 significant bits):
00000000: Reserved - do not program this value
00000001: divides the source clock by 1
00000010: divides the source clock by 2
...
– In normal IrDA mode: PSC must be set to 00000001.
– In Smartcard mode:

PSC[4:0]: Prescaler value
Used for programming the prescaler for dividing the system clock to provide the smartcard
clock.
The value given in the register (5 significant bits) is multiplied by 2 to give the division factor
of the source clock frequency:
00000: Reserved - do not program this value
00001: divides the source clock by 2
00010: divides the source clock by 4
00011: divides the source clock by 6
...
Note: Bits [7:5] have no effect if Smartcard mode is used.
This bit is not available for UART4 & UART5
*/
/* USART_GTPR end */
//--------------------------------------

//--------------------------------------	


#endif /* __HARDWARE_ARM_UART_DRIVER_H__ */