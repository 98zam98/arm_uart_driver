/******************************************************************************
 * Module: UART
 * File Name: Program_arm_uart_driver.c
 * Version: 1
 * Date: 11/1/2022
 * Description: function prototypes and variables and macro functions that can be called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

/* Private */

//--------------------------------------
#define THRESHOLD_VALUE 9000000UL

/* Interface*/
;
void void_init_uart()
{
    MACRO_ENABLE_PERPH_RCC(RCC_APB2ENR_OFFSET, RCC_APB2ENR_AFIOEN_Alternate_function_IO_clock_enable);
    MACRO_ENABLE_PERPH_RCC(RCC_APB2ENR_OFFSET, RCC_APB2ENR_IOPAEN_IO_port_A_clock_enable);
    MACRO_ENABLE_PERPH_RCC(RCC_APB2ENR_OFFSET, RCC_APB2ENR_USART1EN_USART1_clock_enable);

    void_init_output_push_pull_AFIO(A_u2_value_GPIOx_PORTS, 9, OUTPUT_50_MHz_u2_value_GPIOx_PORTS);
    void_init_Input_floating_GPIO(A_u2_value_GPIOx_PORTS, 10);

    //br   ea6 for 36
    MACRO_CLEAR_USART_DIV_USART_BRR();
    //USART_BRR_REG=0x341;
    MACRO_CALC_USART_DIV_Mantissa_VALUE_USART_BRR();
    MACRO_CALC_USART_DIV_Fraction_VALUE_USART_BRR();

    // user config
    MACRO_CONFIG_8_Data_bits_M_Word_length_USART_CR1();

    // user config
    MACRO_DISABLE_Parity_control_PCE_Parity_control_enable_USART_CR1();

    // user config
    MACRO_CLEAR_STOP_1_2_STOP_bits_USART_CR2();
    MACRO_CLEAR_STOP_5_STOP_bits_USART_CR2();

    //enable rx
    MACRO_ENABLE_Receiver_RE_Receiver_enable_USART_CR1();

    //enable tx
    MACRO_ENABLE_Transmitter_TE_Transmitter_enable_USART_CR1();

    //enable usart
    MACRO_ENABLE_USART_UE_USART_CR1();

    MACRO_CLEAR_USART_SR();
}

void void_send_byte_uart(u8 VALUE)
{
    u32 LOC_TimeOut = 0;

    while ((MACRO_GET_Transmission_complete_TC_USART_SR()) == 0 && (LOC_TimeOut < THRESHOLD_VALUE))
    {
        LOC_TimeOut++;
    }

    if (LOC_TimeOut != THRESHOLD_VALUE)
    {
        MACRO_WRITE_USART_Data_value_USART_DR_BYTE(VALUE);
    }
}

void void_send_string_uart(u8 VALUE[])
{
    u8 i = 0;
    while (VALUE[i] == '\0')
    {
        void_send_byte_uart(VALUE[i]);
        i++;
    }
}

u8 void_read_byte_uart()
{

    u32 LOC_TimeOut = 0;

    u32 LOC_u8Data = 0;
    while ((MACRO_GET_Read_data_register_not_empty_RXNE_USART_SR()) == 0 && (LOC_TimeOut < THRESHOLD_VALUE))
    {
        LOC_TimeOut++;
    }
    if (LOC_TimeOut == THRESHOLD_VALUE)
    {
        LOC_u8Data = 0xffff;
    }
    else
    {

        LOC_u8Data = MACRO_READ_USART_Data_value_USART_DR_BYTE();
    }
    return LOC_u8Data;
}

//MACRO_GET_Read_data_register_not_empty_RXNE_USART_SR()
//--------------------------------------
