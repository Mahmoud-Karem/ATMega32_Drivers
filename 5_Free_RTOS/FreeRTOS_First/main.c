/*

 * main.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Mahmoud Karem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"

#include "FreeRTOS.h"
#include "task.h"

void LED1(void * pv);
void LED2(void * pv);
void LED3(void * pv);

void main()
{
	PORT_voidInit();
	xTaskCreate(&LED1,NULL,100,NULL,0,NULL);
	xTaskCreate(&LED2,NULL,100,NULL,1,NULL);
	xTaskCreate(&LED3,NULL,100,NULL,2,NULL);

	vTaskStartScheduler();
	while(1)
	{

	}
}

void LED1(void * pv)
{
	static u8 Local_u8LedState=0;
	while(1)
	{
		TOG_BIT(Local_u8LedState,0);
		DIO_enumSetPinValue(DIO_PORTA,DIO_PIN0,Local_u8LedState);
		vTaskDelay(1000);
	}
}
void LED2(void * pv)
{
	static u8 Local_u8LedState=0;
	while(1)
	{
		TOG_BIT(Local_u8LedState,0);
		DIO_enumSetPinValue(DIO_PORTA,DIO_PIN1,Local_u8LedState);
		vTaskDelay(2000);
	}
}
void LED3(void * pv)
{
	static u8 Local_u8LedState=0;
	while(1)
	{
		TOG_BIT(Local_u8LedState,0);
		DIO_enumSetPinValue(DIO_PORTA,DIO_PIN2,Local_u8LedState);
		vTaskDelay(3000);
	}
}

