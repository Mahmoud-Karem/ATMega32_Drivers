/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : SWITCH / BUTTON
 *
 */
 
#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H



#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

/* 
     $ Optins of State :-
	 1- SW_Int_PULL_UP
	 2- SW_Ext_PULL_UP
	 3- SW_Ext_PULL_DOWN
	 4- SW_FLOATING

 */
/*******/
#define SW_Int_PULL_UP     0
#define SW_Ext_PULL_UP     1
#define SW_Ext_PULL_DOWN   2
#define SW_FLOATING        3
/*******/



typedef struct{
	
	u8 Port;
	u8 Pin ;
	u8 Pull_State;
	
}SW_Type;

void SW_voidInit       ( SW_Type SW_Config );
u8   SW_u8GetPressed   ( SW_Type SW_Config );

#endif