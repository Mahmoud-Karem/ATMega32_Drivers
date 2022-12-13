/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_register.h / ADC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */ 
 

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/* Bit Masking Macros  */
#define ADC_PRE_MASK				0b11111000
#define ADC_CH_MASK				    0b11100000

#define ADMUX				*((volatile u8*)0x27)		//ADC multiplexer selection register
/* ADMUX Bits   */
#define ADMUX_REFS1         7							//Reference selection bit1
#define ADMUX_REFS0         6							//Reference selection bit0
#define ADMUX_ADLAR         5							//ADC left adjust result



#define ADSAR				*((volatile u8*)0x26)		//ADC control and status register A
/* ADSAR Bits   */
#define ADSAR_ADEN			7							//ADC enable
#define ADSAR_ADSC			6                           //Start conversion
#define ADSAR_ADATE		    5                           //Auto trigger enable
#define ADSAR_ADIF			4                           //Interrupt flag
#define ADSAR_ADIE			3                           //Interrupt enable
#define ADSAR_ADPS2		    2                           //Prescaler bit2
#define ADSAR_ADPS1		    1                           //Prescaler bit1
#define ADSAR_ADPS0		    0                           //Prescaler bit0


/* Data Reg  */
#define ADCH				*((volatile u8*)0x25)		//ADC high register
#define ADCL				*((volatile u8*)0x24)		//ADC Low register	
#define ADC_DATA_RE 		*((volatile u16*)0x24)		//ADC Low + High	


#define SFIOR  *((volatile u8 *)0x50)
/* SFIOR Bits   */
#define SFIOR_ADTS2			7                          //Trigger Source bit2
#define SFIOR_ADTS1	     	6                          //Trigger Source bit1
#define SFIOR_ADTS0		    5                          //Trigger Source bit0


/* Values of the global var (ADC_u8ISRSource)  */
#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1

#endif /* ADC_PRIVATE_H_ */
