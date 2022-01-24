/******************************************************************************
 * Module: UART
 * File Name: Interface_arm_uart_driver.h
 * Version: 1
 * Date: 11/1/2022
 * Description: function prototypes and variables and macro functions that can be called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

#ifndef __INTERFACE_ARM_UART_DRIVER_H__
#define __INTERFACE_ARM_UART_DRIVER_H__

/* function prototypes*/

void void_init_uart();
void void_send_byte_uart(u8 VALUE);
void void_send_string_uart(u8 VALUE[]);
u8 void_read_byte_uart();
//--------------------------------------	


/* variables */
enum us_STOP_STOP_bits_USART_CR2
{
    one_us_STOP_STOP_bits_USART_CR2,
    half_us_STOP_STOP_bits_USART_CR2,
    two_us_STOP_STOP_bits_USART_CR2,
    one_half_us_STOP_STOP_bits_USART_CR2,
}

//--------------------------------------	


/* macro function*/
#define MACRO_CLEAR_USART_SR() USART_SR_REG = 0

#define MACRO_GET_CTS_USART_SR() GETBIT(USART_SR_REG,CTS_USART_SR)
#define MACRO_CLEAR_CTS_USART_SR() CLEARBIT(USART_SR_REG,CTS_USART_SR)

#define MACRO_GET_LIN_break_detection_LBD_USART_SR() GETBIT(USART_SR_REG,LBD_USART_SR)
#define MACRO_CLEAR_LIN_break_detection_LBD_USART_SR() CLEARBIT(USART_SR_REG,LBD_USART_SR)

#define MACRO_GET_Transmit_data_register_empty_TXE_USART_SR() GETBIT(USART_SR_REG,TXE_USART_SR)

#define MACRO_GET_Transmission_complete_TC_USART_SR() GETBIT(USART_SR_REG,TC_USART_SR)

#define MACRO_GET_Read_data_register_not_empty_RXNE_USART_SR() GETBIT(USART_SR_REG,RXNE_USART_SR)

#define MACRO_GET_IDLE_line_detected_IDLE_USART_SR() GETBIT(USART_SR_REG,IDLE_USART_SR)

#define MACRO_GET_Overrun_error_ORE_USART_SR() GETBIT(USART_SR_REG,ORE_USART_SR)

#define MACRO_GET_Noise_error_flag_NE_USART_SR() GETBIT(USART_SR_REG,NE_USART_SR)

#define MACRO_GET_Framing_error_FE_USART_SR() GETBIT(USART_SR_REG,FE_USART_SR)

#define MACRO_GET_Parity_error_PE_USART_SR() GETBIT(USART_SR_REG,PE_USART_SR)

#define MACRO_WRITE_USART_Data_value_USART_DR_BYTE(VALUE) USART_Data_value_USART_DR_BYTE = VALUE
#define MACRO_READ_USART_Data_value_USART_DR_BYTE() USART_Data_value_USART_DR_BYTE

#define MACRO_CLEAR_USART_DIV_USART_BRR() USART_BRR_REG=0
#define MACRO_CONFIG_USART_DIV_Mantissa_VALUE_USART_BRR(VALUE) USART_DIV_Mantissa_USART_BRR_REG|=(VALUE<<4)
#define MACRO_CONFIG_USART_DIV_Fraction_VALUE_USART_BRR(VALUE) USART_DIV_Mantissa_USART_BRR_REG|=((VALUE/100)&0X0F)

#define MACRO_CALC_USART_DIV_Mantissa_VALUE_USART_BRR() MACRO_CONFIG_USART_DIV_Mantissa_VALUE_USART_BRR(( F_CPU ) / ( 16 * USART1_BAUD_RATE ))
#define MACRO_CALC_USART_DIV_Fraction_VALUE_USART_BRR() MACRO_CONFIG_USART_DIV_Fraction_VALUE_USART_BRR(( ( ( F_CPU * 100 ) / ( 16 * USART1_BAUD_RATE )  ) % 100 ) * 16 )

#define MACRO_DISABLE_USART_UE_USART_CR1() CLEARBIT(USART_CR1_REG,UE_USART_CR1)
#define MACRO_ENABLE_USART_UE_USART_CR1() SETBIT(USART_CR1_REG,UE_USART_CR1)

#define MACRO_CONFIG_8_Data_bits_M_Word_length_USART_CR1() CLEARBIT(USART_CR1_REG,M_Word_length_USART_CR1)
#define MACRO_CONFIG_9_Data_bits_M_Word_length_USART_CR1() SETBIT(USART_CR1_REG,M_Word_length_USART_CR1)

#define MACRO_CONFIG_Idle_Line_WAKE_Wakeup_method_USART_CR1() CLEARBIT(USART_CR1_REG,WAKE_Wakeup_method_USART_CR1)
#define MACRO_CONFIG_Address_Mark_WAKE_Wakeup_method_USART_CR1() SETBIT(USART_CR1_REG,WAKE_Wakeup_method_USART_CR1)

#define MACRO_DISABLE_Parity_control_PCE_Parity_control_enable_USART_CR1() CLEARBIT(USART_CR1_REG,PCE_Parity_control_enable_USART_CR1)
#define MACRO_ENABLE_Parity_control_PCE_Parity_control_enable_USART_CR1() SETBIT(USART_CR1_REG,PCE_Parity_control_enable_USART_CR1)

#define MACRO_CONFIG_Even_PS_Parity_selection_USART_CR1() CLEARBIT(USART_CR1_REG,PS_Parity_selection_USART_CR1)
#define MACRO_CONFIG_Odd_PS_Parity_selection_USART_CR1() SETBIT(USART_CR1_REG,PS_Parity_selection_USART_CR1)

#define MACRO_DISABLE_PE_interrupt_PEIE_PE_interrupt_enable_USART_CR1() CLEARBIT(USART_CR1_REG,PEIE_PE_interrupt_enable_USART_CR1)
#define MACRO_ENABLE_PE_interrupt_PEIE_PE_interrupt_enable_USART_CR1() SETBIT(USART_CR1_REG,PEIE_PE_interrupt_enable_USART_CR1)

#define MACRO_DISABLE_TXE_interrupt_TXEIE_TXE_interrupt_enable_USART_CR1() CLEARBIT(USART_CR1_REG,TXEIE_TXE_interrupt_enable_USART_CR1)
#define MACRO_ENABLE_TXE_interrupt_TXEIE_TXE_interrupt_enable_USART_CR1() SETBIT(USART_CR1_REG,TXEIE_TXE_interrupt_enable_USART_CR1)

#define MACRO_DISABLE_Transmission_complete_interrupt_TCIE_Transmission_complete_interrupt_enable_USART_CR1() CLEARBIT(USART_CR1_REG,TCIE_Transmission_complete_interrupt_enable_USART_CR1)
#define MACRO_ENABLE_Transmission_complete_interrupt_TCIE_Transmission_complete_interrupt_enable_USART_CR1() SETBIT(USART_CR1_REG,TCIE_Transmission_complete_interrupt_enable_USART_CR1)

#define MACRO_DISABLE_RXNE_interrupt_RXNEIE_RXNE_interrupt_enable_USART_CR1() CLEARBIT(USART_CR1_REG,RXNEIE_RXNE_interrupt_enable_USART_CR1)
#define MACRO_ENABLE_RXNE_interrupt_RXNEIE_RXNE_interrupt_enable_USART_CR1() SETBIT(USART_CR1_REG,RXNEIE_RXNE_interrupt_enable_USART_CR1)

#define MACRO_DISABLE_IDLE_interrupt_IDLEIE_IDLE_interrupt_enable_USART_CR1() CLEARBIT(USART_CR1_REG,IDLEIE_IDLE_interrupt_enable_USART_CR1)
#define MACRO_ENABLE_IDLE_interrupt_IDLEIE_IDLE_interrupt_enable_USART_CR1() SETBIT(USART_CR1_REG,IDLEIE_IDLE_interrupt_enable_USART_CR1)

#define MACRO_DISABLE_Transmitter_TE_Transmitter_enable_USART_CR1() CLEARBIT(USART_CR1_REG,TE_Transmitter_enable_USART_CR1)
#define MACRO_ENABLE_Transmitter_TE_Transmitter_enable_USART_CR1() SETBIT(USART_CR1_REG,TE_Transmitter_enable_USART_CR1)

#define MACRO_DISABLE_Receiver_RE_Receiver_enable_USART_CR1() CLEARBIT(USART_CR1_REG,RE_Receiver_enable_USART_CR1)
#define MACRO_ENABLE_Receiver_RE_Receiver_enable_USART_CR1() SETBIT(USART_CR1_REG,RE_Receiver_enable_USART_CR1)

#define MACRO_CONFIG_active_mode_RWU_Receiver_wakeup() CLEARBIT(USART_CR1_REG,RWU_Receiver_wakeup)
#define MACRO_CONFIG_mute_mode_RWU_Receiver_wakeup() SETBIT(USART_CR1_REG,RWU_Receiver_wakeup)

#define MACRO_CONFIG_No_break_character_SBK_Send_break_USART_CR1() CLEARBIT(USART_CR1_REG,SBK_Send_break_USART_CR1)
#define MACRO_CONFIG_break_character_transmitted_SBK_Send_break_USART_CR1() SETBIT(USART_CR1_REG,SBK_Send_break_USART_CR1)

#define MACRO_DISABLE_LIN_mode_enable_USART_CR2() CLEARBIT(USART_CR2_REG,LINEN_LIN_mode_enable_USART_CR2)
#define MACRO_ENABLE_LIN_mode_enable_USART_CR2() SETBIT(USART_CR2_REG,LINEN_LIN_mode_enable_USART_CR2)

#define MACRO_SET_STOP_1_2_STOP_bits_USART_CR2() CLEARBIT(USART_CR2_REG,STOP_1_2_STOP_bits_USART_CR2)
#define MACRO_CLEAR_STOP_1_2_STOP_bits_USART_CR2() SETBIT(USART_CR2_REG,STOP_1_2_STOP_bits_USART_CR2)

#define MACRO_SET_STOP_5_STOP_bits_USART_CR2() CLEARBIT(USART_CR2_REG,STOP_5_STOP_bits_USART_CR2)
#define MACRO_CLEAR_STOP_5_STOP_bits_USART_CR2() SETBIT(USART_CR2_REG,STOP_5_STOP_bits_USART_CR2)


#define MACRO_DISABLE_CLKEN_Clock_enable_USART_CR2() CLEARBIT(USART_CR2_REG,CLKEN_Clock_enable_USART_CR2)
#define MACRO_ENABLE_CLKEN_Clock_enable_USART_CR2() SETBIT(USART_CR2_REG,CLKEN_Clock_enable_USART_CR2)

#define MACRO_CONFIG_low_CPOL_Clock_polarity_USART_CR2() CLEARBIT(USART_CR2_REG,CPOL_Clock_polarity_USART_CR2)
#define MACRO_CONFIG_high_CPOL_Clock_polarity_USART_CR2() SETBIT(USART_CR2_REG,CPOL_Clock_polarity_USART_CR2)

#define MACRO_CONFIG_first_CPHA_Clock_phase_USART_CR2() CLEARBIT(USART_CR2_REG,CPHA_Clock_phase_USART_CR2)
#define MACRO_CONFIG_second_CPHA_Clock_phase_USART_CR2() SETBIT(USART_CR2_REG,CPHA_Clock_phase_USART_CR2)

#define MACRO_CONFIG_NoT_LBCL_Last_bit_clock_pulse_USART_CR2() CLEARBIT(USART_CR2_REG,SBK_Send_break_USART_CR1)
#define MACRO_CONFIG_IS_LBCL_Last_bit_clock_pulse_USART_CR2() SETBIT(USART_CR2_REG,SBK_Send_break_USART_CR1)

#define MACRO_DISABLE_LBDIE_LIN_break_detection_interrupt_enable_USART_CR2() CLEARBIT(USART_CR2_REG,LBDIE_LIN_break_detection_interrupt_enable_USART_CR2)
#define MACRO_ENABLE_LBDIE_LIN_break_detection_interrupt_enable_USART_CR2() SETBIT(USART_CR2_REG,LBDIE_LIN_break_detection_interrupt_enable_USART_CR2)

#define MACRO_CONFIG_10_LBDL_lin_break_detection_length_USART_CR2() CLEARBIT(USART_CR2_REG,LBDL_lin_break_detection_length_USART_CR2)
#define MACRO_CONFIG_11_LBDL_lin_break_detection_length_USART_CR2() SETBIT(USART_CR2_REG,LBDL_lin_break_detection_length_USART_CR2)

#define MACRO_DISABLE_CTSIE_CTS_interrupt_enable_USART_CR3() CLEARBIT(USART_CR3_REG,CTSIE_CTS_interrupt_enable_USART_CR3)
#define MACRO_ENABLE_CTSIE_CTS_interrupt_enable_USART_CR3() SETBIT(USART_CR3_REG,CTSIE_CTS_interrupt_enable_USART_CR3)

#define MACRO_DISABLE_CTSE_CTS_enable_USART_CR3() CLEARBIT(USART_CR3_REG,CTSE_CTS_enable_USART_CR3)
#define MACRO_ENABLE_CTSE_CTS_enable_USART_CR3() SETBIT(USART_CR3_REG,CTSE_CTS_enable_USART_CR3)

#define MACRO_DISABLE_RTSE_RTS_enable_USART_CR3() CLEARBIT(USART_CR3_REG,RTSE_RTS_enable_USART_CR3)
#define MACRO_ENABLE_RTSE_RTS_enable_USART_CR3() SETBIT(USART_CR3_REG,RTSE_RTS_enable_USART_CR3)

#define MACRO_DISABLE_DMAT_DMA_enable_transmitter_USART_CR3() CLEARBIT(USART_CR3_REG,DMAT_DMA_enable_transmitter_USART_CR3)
#define MACRO_ENABLE_DMAT_DMA_enable_transmitter_USART_CR3() SETBIT(USART_CR3_REG,SBK_Send_break_UDMAT_DMA_enable_transmitter_USART_CR3SART_CR1)

#define MACRO_DISABLE_DMAR_DMA_enable_receiver_USART_CR3() CLEARBIT(USART_CR3_REG,DMAR_DMA_enable_receiver_USART_CR3)
#define MACRO_ENABLE_DMAR_DMA_enable_receiver_USART_CR3() SETBIT(USART_CR3_REG,DMAR_DMA_enable_receiver_USART_CR3)

#define MACRO_DISABLE_SCEN_Smartcard_mode_enable_USART_CR3() CLEARBIT(USART_CR3_REG,SCEN_Smartcard_mode_enable_USART_CR3)
#define MACRO_ENABLE_SCEN_Smartcard_mode_enable_USART_CR3() SETBIT(USART_CR3_REG,SCEN_Smartcard_mode_enable_USART_CR3)

#define MACRO_CONFIG_IF_PARITY_DIS_NACK_Smartcard_NACK_enable_USART_CR3() CLEARBIT(USART_CR3_REG,NACK_Smartcard_NACK_enable_USART_CR3)
#define MACRO_CONFIG_IF_PARITY_EN_NACK_Smartcard_NACK_enable_USART_CR3() SETBIT(USART_CR3_REG,NACK_Smartcard_NACK_enable_USART_CR3)

#define MACRO_DESELECT_HDSEL_Half_duplex_selection_USART_CR3() CLEARBIT(USART_CR3_REG,HDSEL_Half_duplex_selection_USART_CR3)
#define MACRO_SELECT_HDSEL_Half_duplex_selection_USART_CR3() SETBIT(USART_CR3_REG,HDSEL_Half_duplex_selection_USART_CR3)

#define MACRO_CONFIG_IrDA_Normal_mode_IRLP_USART_CR3() CLEARBIT(USART_CR3_REG,IrDA_IRLP_USART_CR3)
#define MACRO_CONFIG_IrDA_Low_power_mode_IRLP_USART_CR3() SETBIT(USART_CR3_REG,IrDA_IRLP_USART_CR3)

#define MACRO_DISABLE_IrDA_IREN_USART_CR3() CLEARBIT(USART_CR3_REG,IrDA_IREN_USART_CR3)
#define MACRO_ENABLE_IrDA_IREN_USART_CR3() SETBIT(USART_CR3_REG,IrDA_IREN_USART_CR3)

#define MACRO_DISABLE_EIE_Error_interrupt_enable_USART_CR3() CLEARBIT(USART_CR3_REG,EIE_Error_interrupt_enable_USART_CR3)
#define MACRO_ENABLE_EIE_Error_interrupt_enable_USART_CR3() SETBIT(USART_CR3_REG,EIE_Error_interrupt_enable_USART_CR3)

//--------------------------------------	


#endif /* __INTERFACE_ARM_UART_DRIVER_H__ */
