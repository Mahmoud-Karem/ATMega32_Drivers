/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER0_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : RTOS Stack
 *  SWC    : TIMER0
 *
 */ 
 

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*<<<<<<<<<<<<<<<<<<   TIMER0 CONFIG  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* Timer 0 Mode Config */
/* Options = TIMER0_NORMAL_MODE
             TIMER0_PHASE_CORRECT_PWM
             TIMER0_CTC_MODE
             TIMER0_FAST_PWM          */

#define TIMER0_MODE              TIMER0_CTC_MODE

/* Timer 0 Interrupt Enable */
/* options = TIMER_INTERRUPT_ENABLE
             TIMER_INTERRUPT_DISABLE */
#define TIMER0_OVF_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE
#define TIMER0_CTC_INTERRUPT_INIT    TIMER_INTERRUPT_ENABLE


/**********************************************************************/


#define TIMER0_u8_PRELOAD_VALUE             64
#define TIMER0_u32_NUMBER_OF_OVF            3907
#define TIMER_u8_OCR0_INIT_VALUE            125

/* Config for Timer Driver */

/* Timers Enable options
 * options : TIMER_u8_INIT_STATE_ENABLE
             TIMER_u8_INIT_STATE_DISABLE         */

#define TIMER0_INIT_STATE              TIMER_u8_INIT_STATE_ENABLE

/* Timer  Prescaler values */
/* options = TIMER_CLOCK_NO_CLOCK
             TIMER_CLOCK_NO_PRESCHALER
             TIMER_CLOCK_8_PRESCHALER
             TIMER_CLOCK_64_PRESCHALER
             TIMER_CLOCK_256_PRESCHALER
             TIMER_CLOCK_1024_PRESCHALER
             TIMER_CLOCK_EXTERNAL_FALLING_EDGE
             TIMER_CLOCK_EXTERNAL_RISING_EDGE	 */
#define TIMER0_CLOCK_SOURCE          TIMER_CLOCK_64_PRESCHALER
#define TIMER1_CLOCK_SOURCE          TIMER_CLOCK_8_PRESCHALER


/* OCX pin Config Macros */
/* Options :TIMER_u8_OCX_DISCONNECTED
            TIMER_u8_OCX_TOGGELE
            TIMER_u8_OCX_SET
            TIMER_u8_OCX_CLEAR        */
#define TIMER_u8_OC0_PIN_MODE        TIMER_u8_OCX_CLEAR




#endif /* TIMER_CONFIG_H_ */
