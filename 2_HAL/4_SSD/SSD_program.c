/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Seven_Segment_Display_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : Seven_Segments
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR ;

//====================================================================================================================================================
/*
 * Breif : This Function initialize the port which connected to 7 Seg leds as output pins ( 8 Pins or Port )
 * Parameters :
            =>Copy_u8PORT --> Port Name [ SSD_PORTA ,	SSD_PORTB , SSD_PORTC , SSD_PORTD ]
 * return : void
 */
void SSD_voidInitialDataPort  (SSD_Type Copy_structConfig )
{
	DIO_enumSetPortDirection    ( Copy_structConfig.DataPort , 0xFF );
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function write Number on 7 seg [ 0 : 9 ]
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidSendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPortValue( Copy_structConfig.DataPort , Local_u8SSDNumbers[ Copy_u8Number ] );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPortValue( Copy_structConfig.DataPort , ~( Local_u8SSDNumbers[ Copy_u8Number ] ) );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function enable common pin
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidEnable    ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_LOW );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_HIGH );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function disable common pin
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidDisable   ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_HIGH );

	}
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_LOW );

	}

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

