/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER0_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : RTOS Stack
 *  SWC    : TIMER0
 *
 */ 
 
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_register.h"

static u16 TIMER_u16OnPeriod=0,Timeru16OffPeriod=0;
static void(*TIMER_pfNotification[8])(void) = {NULL} ; /* we have 8 interrupt sources in timer  */

//----------------------------------------------------------------------------------------------------------------------------------------------------

void TIMER0_voidInit(void)
{
	#if (Timer0_INIT_STATE == TIMER_u8_INIT_STATE_DISABLE)
	
		CLR_BIT(TCCR0,TCCR0_CS02);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS00);
	#elif(Timer0_INIT_STATE == TIMER_u8_INIT_STATE_ENABLE)
			
		//Check if OVF INT is enabled
		#if (Timer0_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
			SET_BIT(TIMSK,TIMSK_TOIE0);
		#elif(Timer0_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
			CLR_BIT(TIMSK,TIMSK_TOIE0);
		#endif
		//Check if CTC INT is enabled
		#if (Timer0_CTC_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
			SET_BIT(TIMSK,TIMSK_OCIE0);
		#elif(Timer0_CTC_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
			CLR_BIT(TIMSK,TIMSK_OCIE0);
		#endif
		
		//Choose The Mode of the Timer and the prescaler
		
		#if (Timer0_MODE == Timer0_FAST_PWM)
			OCR0 = TIMER_u8_OCR0_INIT_VALUE;
			//Set Fast Pwm Mode
			SET_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
			
		#elif Timer0_MODE == Timer0_PHASE_CORRECT_PWM
			OCR0 = TIMER_u8_OCR0_INIT_VALUE;
			//Set Phase Correct Pwm mode
			SET_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
			
		#elif Timer0_INIT_STATE == Timer0_NORMAL_MODE
			TCNT0 = Timer0_u8_PRELOAD_VALUE;
			//Set Phase Correct Normal mode
			CLR_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
			
		#elif Timer0_INIT_STATE == Timer0_CTC_MODE
			OCR0 = TIMER_u8_OCR0_INIT_VALUE; /* compare match value */
			//Set Phase Correct Pwm mode
			SET_BIT(TCCR0,TCCR0_WGM01);
			CLR_BIT(TCCR0,TCCR0_WGM00);
			
		#endif
		
		/* OC0 pin Config Modes */
		#if TIMER_u8_OC0_PIN_MODE == TIMER_u8_OCX_CLEAR
			/* CLR on Comp , SET on Top */
			SET_BIT(TCCR0,TCCR0_COM01);
			CLR_BIT(TCCR0,TCCR0_COM00);
		#elif TIMER_u8_OC0_PIN_MODE == TIMER_u8_OCX_SET
			/* SET on Comp , CLR on Top */
			SET_BIT(TCCR0,TCCR0_COM01);
			SET_BIT(TCCR0,TCCR0_COM00);
		#endif
		
		/* Select the Prescaler value to start the Timer to count */
		/*
			Hint : The Prescaler works as the Enable of the timer
			So it is the Last
		*/
			TCCR0 &= TIMER_CLOCK_NO_CLOCK; //0b11111000
			TCCR0 |= Timer0_CLOCK_SOURCE;
			
	#endif
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

u8 TIMER_voidSetCallBack(void(*Copy_pfNotification)(void),u8 Copy_u8TimerIntIndex)
{
	Local_u8ErrorStatus = OK ;
	
	if (Copy_pfNotification != NULL)
	{
		TIMER_pfNotification[Copy_u8TimerIntIndex] = Copy_pfNotification;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER ;
	}
	return Local_u8ErrorStatus;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

/* ISR Function for Timer0 CTC */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	/* Hint : I will make the counter in the App layer
	
	static u32 Local_u8Counter = 0;
	Local_u8Counter++;
	if(Local_u8Counter == 10000)
	{
		Local_u8Counter=0;

	} */
	if ( TIMER_pfNotification[TIMER_CTC0_INT_INDEX] != NULL)
	{
		TIMER_pfNotification[TIMER_CTC0_INT_INDEX]();
	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
