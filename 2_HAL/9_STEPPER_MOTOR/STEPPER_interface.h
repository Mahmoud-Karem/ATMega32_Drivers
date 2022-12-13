/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STEPPER_interface.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : STEPPER_MOTOR
 *
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_

#define STEPPER_FULL_STEP    1
#define STEPPER_HALF_STEP    0

#define STEPPER_CLOCK_WISE       1
#define STEPPER_ANTI_CLOCK_WISE  0

void STEPPER_voidInit( void );
void STEPPER_voidOff ( void );
void STEPPER_voidOn  ( u8 Copy_u8StepType , u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree );


#endif /* HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_ */
