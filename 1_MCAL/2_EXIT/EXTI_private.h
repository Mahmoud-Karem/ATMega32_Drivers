/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR_REG   *((volatile u8 *)0x55)
#define MCUCSR_REG  *((volatile u8 *)0x54)
#define GICR_REG    *((volatile u8 *)0x5B)
#define GIFR_REG    *((volatile u8 *)0x5A)

#define NULL 0

#endif /* EXTI_PRIVATE_H_ */
