/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    MAPPING.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : LIB
 *
 */ 


#ifndef MAPPING_H_
#define MAPPING_H_

	typedef struct
	{
		u32 Copy_u32InputMin ;
		u32 Copy_u32InputMax ;
		u32 Copy_u32OutputMin ;
		u32 Copy_u32OutputMax ;
		u32 Copy_u32InputValue ;
	}MAPPING_CONFIG ;

	u32 MAPPING_u32GetOutput (MAPPING_CONFIG * mapping_config) ;
	
#endif
