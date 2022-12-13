/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    MAPPING.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : LIB
 *
 */ 

#include "STD_TYPE.h"
#include "MAPPING.h"

u32 MAPPING_u32GetOutput (MAPPING_CONFIG * mapping_config)
{
	u32 Local_u32OutputValue ;
	Local_u32OutputValue = ((((mapping_config->Copy_u32InputValue - mapping_config->Copy_u32InputMin) * (mapping_config->Copy_u32OutputMax - mapping_config->Copy_u32OutputMin)) / (mapping_config->Copy_u32InputMax - mapping_config->Copy_u32InputMin)) + mapping_config->Copy_u32OutputMin) ;
	return Local_u32OutputValue  ;
}
