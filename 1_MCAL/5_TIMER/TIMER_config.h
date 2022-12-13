/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : TIMER
 *
 */ 
 

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

	/*Timer0 Config*/

	/*Set Timer0 Waveform Generation Mode
	 * Choose between
	 * 1. TIMER_NORMAL_MODE
	 * 2. TIMER_PWM_MODE
	 * 3. TIMER_CTC_MODE
	 * 4. TIMER_FAST_PWM_MODE
	 */
	#define TIMER0_WAVEFORM_GENERATION_MODE		TIMER_NORMAL_MODE

	/*Set the Required Prescaler
	 * Choose between
	 * - TIMER_NO_CLOCK_SOURCE
	 * - TIMER_NO_PRESCALER_FACTOR
	 * - TIMER_DIVISION_FACTOR_8
	 * - TIMER_DIVISION_FACTOR_64
	 * - TIMER_DIVISION_FACTOR_256
	 * - TIMER_DIVISION_FACTOR_1024
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
	 */
	#define TIMER0_PRESCALER		TIMER_DIVISION_FACTOR_8

	#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE

		/*Set the Required Preload on TIMER0 Normal Mode*/
		#define TIMER0_PRELOAD_VAL					192

		/*Set Timer0 Overflow Interrupt
		 * Choose between
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER0_OVERFLOW_INTERRUPT			ENABLE

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_PWM_MODE

		/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
		#define TIMER0_CTC_VAL						250

		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
		#define TIMER0_CTC_PWM_MODE						TIMER_SET_ON_CTC_CLR_ON_TOP

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE

		/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
		#define TIMER0_CTC_VAL						125

		/*Set Compare Match Output Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_OC_TOGGEL
		 * 3. TIMER_OC_LOW
		 * 4. TIMER_OC_HIGH
		 */
		#define TIMER0_OC0_MODE						TIMER_OC_DISCONNECTED

		/*Set Timer0 CTC Interrupt
		 * Choose between
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER0_CTC_INTERRUPT			ENABLE

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

		/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
		#define TIMER0_CTC_VAL						0

		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
		#define TIMER0_CTC_PWM_MODE						TIMER_CLR_ON_CTC_SET_ON_TOP

	#else
		#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"

	#endif

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

	/*Timer1 Config*/

	/*Set Timer1 Waveform Generation Mode
	 * Choose between
	 * 1. TIMER1_NORMAL_MODE
	 * 2. TIMER1_PWM_8_BIT_MODE
	 * 3. TIMER1_PWM_9_BIT_MODE
	 * 4. TIMER1_PWM_10_BIT_MODE
	 * 5. TIMER1_CTC_OCR1A_MODE
	 * 6. TIMER1_FAST_PWM_8_BIT_MODE
	 * 7. TIMER1_FAST_PWM_9_BIT_MODE
	 * 8. TIMER1_FAST_PWM_10_BIT_MODE
	 * 9. TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
	 * 10.TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
	 * 11.TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	 * 12.TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
	 * 13.TIMER1_CTC_ICR1_MODE
	 * 14.TIMER1_FAST_PWM_ICR1_MODE
	 * 15.TIMER1_FAST_PWM_OCR1A_MODE
	 */
	#define TIMER1_WAVEFORM_GENERATION_MODE		TIMER1_FAST_PWM_ICR1_MODE

	/*Set the Required Prescaler
	 * Choose between
	 * - TIMER_NO_CLOCK_SOURCE
	 * - TIMER_NO_PRESCALER_FACTOR
	 * - TIMER_DIVISION_FACTOR_8
	 * - TIMER_DIVISION_FACTOR_64
	 * - TIMER_DIVISION_FACTOR_256
	 * - TIMER_DIVISION_FACTOR_1024
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
	 */
	#define TIMER1_PRESCALER					TIMER_DIVISION_FACTOR_8

	/*Set Preload Value for Normal Mode*/
	#define TIMER1_PRELOAD_VAL					0

	/*Set CTCA Value*/
	#define TIMER1_CTCA_VAL						500

	/*Set CTCB Value*/
	#define TIMER1_CTCB_VAL						0

	/*Set Input Capture Value*/
	#define TIMER1_ICR1_VAL						20000

	/*Set Compare Match Output for OCR1A
	 * Choose between
	 * 		CTC mode				||	PWM & FAST PWM mode
	 *
	 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
	 * 2. TIMER_OC_TOGGEL			||
	 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_SET_ON_TOP
	 * 4. TIMER_OC_HIGH				|| TIMER_SET_ON_CTC_CLR_ON_TOP
	 */
	#define TIMER1_OCR1A_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP

	/*Set Compare Match Output for OCR1A
	 * Choose between
	 *
	 * 		CTC mode				||	PWM & FAST PWM mode
	 *
	 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
	 * 2. TIMER_OC_TOGGEL			||
	 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_SET_ON_TOP
	 * 4. TIMER_OC_HIGH				|| TIMER_SET_ON_CTC_CLR_ON_TOP
	 */
	#define TIMER1_OCR1B_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP

	/*Set Timer1 Input Capture Noise Canceler
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_NOISE_CANCELER			DISABLE

	/*Set Timer1 Input Capture Edge
	 * Choose between
	 * 1. FALLING_EDGE
	 * 2. RISING_EDGE
	 */
	#define TIMER1_ICR_EDGE				RISING_EDGE

	/*Set Timer1 Overflow Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_OVERFLOW_INTERRUPT			DISABLE

	/*Set Timer1 CTCB Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_CTCB_INTERRUPT			DISABLE

	/*Set Timer1 CTCA Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_CTCA_INTERRUPT			DISABLE

	/*Set Timer1 Input Capture Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_INTERRUPT			DISABLE

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

	/*Timer2 Config*/

	/*Set Timer2 Waveform Generation Mode
	 * Choose between
	 * 1. TIMER_NORMAL_MODE
	 * 2. TIMER_PWM_MODE
	 * 3. TIMER_CTC_MODE
	 * 4. TIMER_FAST_PWM_MODE
	 */
	#define TIMER2_WAVEFORM_GENERATION_MODE		TIMER_CTC_MODE

	/*Set the Required Prescaler
	 * Choose between
	 * - TIMER_NO_CLOCK_SOURCE
	 * - TIMER_NO_PRESCALER_FACTOR
	 * - TIMER_DIVISION_FACTOR_8
	 * - TIMER_DIVISION_FACTOR_64
	 * - TIMER_DIVISION_FACTOR_256
	 * - TIMER_DIVISION_FACTOR_1024
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
	 */
	#define TIMER2_PRESCALER		TIMER_DIVISION_FACTOR_64

	#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE

		/*Set the Required Preload on TIMER2 Normal Mode*/
		#define TIMER2_PRELOAD_VAL					192

		/*Set Timer2 Overflow Interrupt
		 * Choose between
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER2_OVERFLOW_INTERRUPT			ENABLE

	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE

		/*Set the Required Compare Match Value on TIMER2 CTC Mode*/
		#define TIMER2_CTC_VAL						250

		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
		#define TIMER2_CTC_PWM_MODE						TIMER_SET_ON_CTC_CLR_ON_TOP

	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE

		/*Set the Required Compare Match Value on TIMER2 CTC Mode*/
		#define TIMER2_CTC_VAL						125

		/*Set Compare Match Output Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_OC_TOGGEL
		 * 3. TIMER_OC_LOW
		 * 4. TIMER_OC_HIGH
		 */
		#define TIMER2_OC2_MODE						TIMER_OC_DISCONNECTED

		/*Set Timer2 CTC Interrupt
		 * Choose between
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER2_CTC_INTERRUPT			ENABLE

	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

		/*Set the Required Compare Match Value on TIMER2 CTC Mode*/
		#define TIMER2_CTC_VAL						0

		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
		 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
		 */
		#define TIMER2_CTC_PWM_MODE						TIMER_CLR_ON_CTC_SET_ON_TOP

	#else
		#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"

	#endif

	#define TIMER_u8_ICP_INIT_STATE      TIMER_u8_ICP_RAISING_EDGE

	/* WDT Prescaler select */
	/*
		$ Options :-
		1- WDT_PS_16_3_MS	   ( for 16.3 ms )
		2- WDT_PS_32_5_MS	   ( for 32.5 ms )
		3- WDT_PS_65_MS	       ( for 65   ms )
		4- WDT_PS_0_13_S	   ( for 0.13  s )
		5- WDT_PS_0_26_S	   ( for 0.26  s )
		6- WDT_PS_0_52_S	   ( for 0.52  s )
		7- WDT_PS_1_0_S	       ( for 1.0   s )
		8- WDT_PS_2_1_S	       ( for 2.1   s )

	*/
	#define WDT_PRESCALER      WDT_PS_1_0_S



#endif /* TIMER_CONFIG_H_ */
