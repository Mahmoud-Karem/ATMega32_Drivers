/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : Timer
 *
 */ 
 

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/* Define indexes for the global pointer to func for ISR  */

	#define TIMER0_OVF_VECTOR_ID		11
	#define TIMER0_CTC_VECTOR_ID		10

	#define TIMER1_OVF_VECTOR_ID		9
	#define TIMER1_CTCB_VECTOR_ID		8
	#define TIMER1_CTCA_VECTOR_ID		7
	#define TIMER1_ICU_VECTOR_ID		6

	#define TIMER2_OVF_VECTOR_ID		5
	#define TIMER2_CTC_VECTOR_ID		4


	void TIMER0_voidInit(void) ;
	void TIMER0_voidSetPreload (u8 Copy_u8Preload) ;
	void TIMER0_voidSetCTC (u8 Copy_u8CTC) ;
	u8   TIMER0_u8GetTimerCounterValue (void) ;

	void TIMER1_voidInit(void) ;
	void TIMER1_voidSetPreload (u16 Copy_u16Preload) ;
	void TIMER1_voidSetCTCA (u16 Copy_u16CTCA) ;
	void TIMER1_voidSetCTCB (u16 Copy_u16CTCB) ;
	void TIMER1_voidSetICR1 (u16 Copy_u16ICR1) ;
	u16  TIMER1_u16GetTimerCounterValue (void) ;

	void TIMER2_voidInit(void) ;
	void TIMER2_voidSetPreload (u8 Copy_u8Preload) ;
	void TIMER2_voidSetCTC (u8 Copy_u8CTC) ;
	u8   TIMER2_u8GetTimerCounterValue (void) ;

	/*******************************/

	void TIMER_voidICUInitEnable(void);
	u8   TIMER_voidICUSetTriggerEdge(u8 Copy_u8Edge);
	void TIMER_voidICUEnableInterrupt(void);
	void TIMER_voidICUDisableInterrupt(void);
	u16  TIMER_u16GetICR(void);

	void TIMER_voidSetPWM(u16 Copy_u16CompareValue);
	u8   TIMER_u8GetPWMOnPeriod   (u16 * Copy_pu16OnPeriod);
	u8   TIMER_u8GetPWMTotalPeriod(u32 * Copy_pu32TotalPeriod);
	u8   TIMER_u8GetPWMDutyCycle  (u8  * Copy_pu8DutyCycle);
	void TIMER_voidWDTSleep(void);
	void TIMER_voidWDTEnable (void);
	void TIMER_voidWDTDisable(void);


	u8   TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID) ;




#endif /* TIMER_INTERFACE_H_ */
