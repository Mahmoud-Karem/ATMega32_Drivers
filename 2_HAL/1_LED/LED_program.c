/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LED_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : LED
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to led as output pin
* Parameters :
            => struct has the led port , pin , status
* return : void 
*/
void LED_voidInit( LED_Type LED_Configuration )
{
	
	DIO_enumSetPinDirection( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_OUTPUT );
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set high on led pin ( led on )
* Parameters :
            => struct has the led port , pin , status
* return : void 
*/
void LED_voidOn  ( LED_Type LED_Configuration )
{
	
	if( LED_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH );
		
	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );
		
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set low on led pin ( led off )
* Parameters :
             => struct has the led port , pin , status
* return : void 
*/
void LED_voidOff ( LED_Type LED_Configuration )
{
	
	if( LED_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );
		
	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH  );
		
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function toggle led pin
* Parameters :
             => struct has the led port , pin , status
* return : void 
*/
void LED_voidToggle      ( LED_Type LED_Configuration )
{
	DIO_enumTogglePinValue  ( LED_Configuration.Port , LED_Configuration.Pin );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
