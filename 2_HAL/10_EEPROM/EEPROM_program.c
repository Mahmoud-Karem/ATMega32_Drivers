/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EEPROM_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : ُExternal EEPROM
 *
 */
 
#include "STD_TYPES.h"
#include <util/delay.h>

#include "TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{
	u8 Local_u8AddressPacket;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);

	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet*/
	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((u8)Copy_u16LocationAddress);

	/*Send the data byte to the memory location*/
	TWI_MasterWriteDataByte(Copy_u8DataByte);

	/*Send stop condition*/
	TWI_SendStopCondition();

	/*Delay until the write cycle is finished*/
	_delay_ms(10);
}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress)
{
	u8 Local_u8AddressPacket, Local_u8Data;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);

	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet with write request*/
	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((u8)Copy_u16LocationAddress);

	/*Send repeated start to change write request into read request*/
	TWI_SendRepeatedStart();

	/*Send the address packet with read request*/
	TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);
	
	/*Get the data from memory*/
	TWI_MasterReadDataByte(&Local_u8Data);

	/*send the stop condition*/
	TWI_SendStopCondition();

	return Local_u8Data;
}
