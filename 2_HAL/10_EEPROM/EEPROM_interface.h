/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EEPROM_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : ُExternal EEPROM
 *
 */
 
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);

#endif
