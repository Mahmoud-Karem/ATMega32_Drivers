/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    USART_config.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : USART
 *
 */
 
/*File Gard*/
#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*Set System Frequency*/
#define SYSTEM_FREQUENCY				8000000UL

/*Set Baud Rate*/
#define USART_BAUD_RATE					9600UL

/*Set System Speed
 * choose between
 * 1. USART_X1
 * 2. USART_X2  (Double Speed Mode)
 */
#define USART_SYSTEM_SPEED				USART_X1

/*Set Timeout for Your functions*/
#define USART_u32TIMEOUT	         	10000UL

/*Set Multi-Processor Communication mode
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define USART_MPCM						DISABLE

/*Set RX Complete Interrupt Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define USART_RX_COMPLETE_INTERRUPT		DISABLE

/*Set TX Complete Interrupt Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define USART_TX_COMPLETE_INTERRUPT		DISABLE

/*Set UDR Empty Interrupt Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define USART_UDR_EMPTY_INTERRUPT		DISABLE

/*Set Receiver Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define USART_RECEIVER_ENABLE		ENABLE

/*Set Transmitter Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define USART_TRANSMITTER_ENABLE		ENABLE

/*Set USART Mode Select
 * choose between
 * 1. ASYNCHRONOUS
 * 2. SYNCHRONOUS
 */
#define USART_MODE					ASYNCHRONOUS

/*Set Parity Mode
 * choose between
 * 1. DISABLE
 * 2. EVEN_PARITY
 * 3. ODD_PARITY
 */
#define USART_PARITY_MODE			DISABLE

/*Set Stop bit
 * choose between
 * 1. STOP_BIT_1
 * 2. STOP_BIT_2
 */
#define USART_STOP_BIT				STOP_BIT_1

/*Set Data Size
 * choose between
 * 1. DATA_SIZE_5_BIT
 * 2. DATA_SIZE_6_BIT
 * 3. DATA_SIZE_7_BIT
 * 4. DATA_SIZE_8_BIT
 * 5. DATA_SIZE_9_BIT
 */
#define USART_DATA_SIZE				DATA_SIZE_8_BIT

/*Set Clock Polarity (for SYNCHRONOUS mode only)
 * choose between
 * 1. XCK_RISING_TX_XCH_FALLING_RX
 * 2. XCK_RISING_RX_XCH_FALLING_TX
 */
#define USART_CLOCK_POLARITY		XCK_RISING_TX_XCH_FALLING_RX
	
#endif
