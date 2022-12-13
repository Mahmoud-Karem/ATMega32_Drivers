/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER0_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : RTOS Stack
 *  SWC    : TIMER0
 *
 */ 
 
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*  TCCR0 Bits */
#define TCCR0_FOC0              7
#define TCCR0_WGM00             6
#define TCCR0_COM01             5
#define TCCR0_COM00             4
#define TCCR0_WGM01             3
#define TCCR0_CS02              2
#define TCCR0_CS01				1
#define TCCR0_CS00				0


/*  TCCR1A Bits */
#define TCCR1A_COM1A1            7
#define TCCR1A_COM1A0            6
#define TCCR1A_COM1B1            5
#define TCCR1A_COM1B0            4
#define TCCR1A_FOC1A             3
#define TCCR1A_FOC1B             2
#define TCCR1A_WGM11			 1
#define TCCR1A_WGM10			 0

/*  TCCR1B Bits */
#define TCCR1B_ICNC1             7
#define TCCR1B_ICES1             6
#define TCCR1B_WGM13             4
#define TCCR1B_WGM12             3
#define TCCR1B_CS12              2
#define TCCR1B_CS11			     1
#define TCCR1B_CS10			     0


/* TIMSK Bits */
#define TIMSK_TOIE0             0
#define TIMSK_OCIE0             1
#define TIMSK_TOIE1             2
#define TIMSK_OCIE1B            3
#define TIMSK_OCIE1A            4
#define TIMSK_TICIE             5


/* Config for Timer Enable */
/* Timer  */
#define TIMER_u8_INIT_STATE_ENABLE           0
#define TIMER_u8_INIT_STATE_DISABLE          1


/* Config For Timers Mode */
/* Timer 0 Modes */
#define TIMER0_NORMAL_MODE       0
#define TIMER0_PHASE_CORRECT_PWM 1
#define TIMER0_CTC_MODE          2
#define TIMER0_FAST_PWM          3

/* Config For Timer 1 Modes */
/* Timer 1 Modes */
#define TIMER1_NORMAL_MODE       0
#define TIMER1_FAST_PWM_ICR1_TOP 14

/* Config for Timers Int Enable */
#define TIMER_INTERRUPT_ENABLE   0
#define TIMER_INTERRUPT_DISABLE  1


/* Config For Prescaler  */
#define 	TIMER_CLOCK_NO_CLOCK					0b11111000 /* This Value also could use for bit masking */
#define		TIMER_CLOCK_NO_PRESCHALER				1
#define		TIMER_CLOCK_8_PRESCHALER				2
#define		TIMER_CLOCK_64_PRESCHALER				3
#define		TIMER_CLOCK_256_PRESCHALER				4
#define		TIMER_CLOCK_1024_PRESCHALER			    5
#define		TIMER_CLOCK_EXTERNAL_FALLING_EDGE		6
#define		TIMER_CLOCK_EXTERNAL_RISING_EDGE		7


/* MACROS for OC Pin */
#define TIMER_u8_OCX_DISCONNECTED                   0
#define TIMER_u8_OCX_TOGGELE                        1
#define TIMER_u8_OCX_SET                            2
#define TIMER_u8_OCX_CLEAR                          3


#define TIMER_u8_ICP_FALLING_EDGE                   0
#define TIMER_u8_ICP_RAISING_EDGE                   1


/* WDTCR Bits */
#define		WDTCR_WDTOE 			4
#define		WDTCR_WDE				3
#define		WDTCR_WDP2				2
#define		WDTCR_WDP1				1
#define		WDTCR_WDP0				0

/* WDT Prescaler select  */
#define		WDT_PS_MASKING				0b11111000
#define		WDT_PS_16_3_MS				0
#define		WDT_PS_32_5_MS	    		1
#define		WDT_PS_65_MS	    		2
#define		WDT_PS_0_13_S				3
#define		WDT_PS_0_26_S				4
#define		WDT_PS_0_52_S				5
#define		WDT_PS_1_0_S				6
#define		WDT_PS_2_1_S				7



#endif /* TIMER_PRIVATE_H_ */
