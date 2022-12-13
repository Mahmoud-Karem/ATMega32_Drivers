/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DCMOTOR_programe.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : DC_MOTOR
 *
 */
 
#include "DIO_interface.h"
#include "STD_TYPE.h"
#include "BIT_MATH.h"

//#include "PORT_INTERFACE.h"

#include "DCMOTOR_INTERFACE.h"
#include "DCMOTOR_PRIVET.h"

uint8 DCMOTOR_uint8Control (DCMOTOR_CONFIG * DcMotor , uint8 Copy_uint8State)
{
	uint8 Local_uint8ErrorState = OK ;

	switch (Copy_uint8State)
	{
	case DCMOTOR_CW :
		 DIO_uint8SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_uint8_LOW) ;
		 DIO_uint8SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_uint8_HIGH) ;
		 break ;
	case DCMOTOR_CCW :
		 DIO_uint8SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_uint8_LOW) ;
		 DIO_uint8SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_uint8_HIGH) ;
		 break ;
	case DCMOTOR_STOP :
		 DIO_uint8SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_uint8_LOW) ;
		 DIO_uint8SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_uint8_LOW) ;
		 break ;
	default : Local_uint8ErrorState = NOK ;
	}

	return Local_uint8ErrorState ;
}
