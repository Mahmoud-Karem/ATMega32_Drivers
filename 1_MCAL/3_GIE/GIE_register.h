/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GIE_register.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */
#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

	#define SREG			*((volatile u8*) 0X5F)	/* Status Register */
	#define SREG_I			7							/* Global Interrupt Enable Bit */

#endif /* GIE_REGISTER_H_ */
