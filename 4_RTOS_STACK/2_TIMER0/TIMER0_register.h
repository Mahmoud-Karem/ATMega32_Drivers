/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER0_register.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : RTOS Stack
 *  SWC    : TIMER0
 *
 */ 
 
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define SREG         *((volatile u8 *)0x5F)
#define TCCR0        *((volatile u8 *)0x53)
#define TCNT0        *((volatile u8 *)0x52)

#define TIMSK        *((volatile u8 *)0x59)
#define OCR0         *((volatile u8 *)0x5C)

#define TCCR1A       *((volatile u8 *)(0x4F))
#define TCCR1B       *((volatile u8 *)(0x4E))
#define TCNT1H       *((volatile u8 *)(0x4D))
#define TCNT1L       *((volatile u8 *)(0x4C))
#define TCNT1        *((volatile u16 *)(0x4C))  /* u16 for HIGH & LOW */
#define ICR1H        *((volatile u8 *)(0x47))
#define ICR1L        *((volatile u8 *)(0x46))
#define ICR1         *((volatile u16 *)(0x46))

#define OCR1AL       *((volatile u8 *)(0x4A))
#define OCR1AH       *((volatile u8 *)(0x4B))
#define OCR1A        *((volatile u16 *)(0x4A))

#define OCR1BL       *((volatile u8 *)(0x48))
#define OCR1BH       *((volatile u8 *)(0x49))
#define OCR1B        *((volatile u16 *)(0x48))

#define WDTCR        *((volatile u8 *)(0x41))


#endif /* TIMER_REGISTER_H_ */
