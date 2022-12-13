/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BUZ_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : BUZ
 *
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "BUZ_interface.h"
#include "BUZ_private.h"
#include "BUZ_config.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to BUZ as output pin
* Parameters :
            => struct has the BUZ porn , pin , status
* return : void 
*/
void BUZ_voidInit( BUZ_Type BUZ_Configuration )
{
	
	DIO_enumSetPinDirection( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_OUTPUT );
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set high on BUZ pin ( BUZ on )
* Parameters :
            => struct has the BUZ porn , pin , status
* return : void 
*/
void BUZ_voidOn  ( BUZ_Type BUZ_Configuration )
{
	
	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_HIGH );
		
	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_LOW  );
		
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set low on BUZ pin ( BUZ off )
* Parameters :
             => struct has the BUZ porn , pin , status
* return : void 
*/
void BUZ_voidOff ( BUZ_Type BUZ_Configuration )
{
	
	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_LOW  );
		
	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_HIGH  );
		
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function toggle BUZ pin
* Parameters :
             => struct has the BUZ porn , pin , status
* return : void 
*/
void BUZ_voidToggle      ( BUZ_Type BUZ_Configuration )
{
	DIO_enumTogglePinValue  ( BUZ_Configuration.Port , BUZ_Configuration.Pin );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
