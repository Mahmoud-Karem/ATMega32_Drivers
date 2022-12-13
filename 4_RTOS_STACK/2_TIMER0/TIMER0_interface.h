/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER0_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : RTOS Stack
 *  SWC    : TIMER0
 *
 */ 
 

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/* Define indexes for the global pointer to func for ISR  */
#define TIMER_OVF0_INT_INDEX              0
#define TIMER_CTC0_INT_INDEX              1
#define TIMER_ICU_INT_INDEX               2

/* Functions Prototypes  */
void TIMER0_voidInit(void);
u8   TIMER_voidSetCallBack(void(*Copy_pfNotification)(void),u8 Copy_u8TimerIntIndex);


#endif /* TIMER_INTERFACE_H_ */
