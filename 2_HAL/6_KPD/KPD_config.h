/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_config.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_ROW_INIT  DIO_PIN0
#define KPD_ROW_END   DIO_PIN3

#define KPD_COL_INIT  DIO_PIN4
#define KPD_COL_END   DIO_PIN7

                         /* C0   C1  C2  C3  */
u8 KPD_u8Buttons[4][4] = { {'7','8','9','/'}, /* Row0 */
						   {'4','5','6','*'}, /* Row1 */
						   {'1','2','3','-'}, /* Row2 */
						   {'?','0','=','+'}  /* Row3 */};


/*
 	 Options:-

 	 	 1-DIO_PORTA
 	 	 2-DIO_PORTB
 	 	 3-DIO_PORTC
 	 	 4-DIO_PORTD

 */

#define KPD_PORT  DIO_PORTD

/*
 Options :-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 * */

#define KPD_R0    DIO_PIN0
#define KPD_R1    DIO_PIN1
#define KPD_R2    DIO_PIN2
#define KPD_R3    DIO_PIN3

#define KPD_C0    DIO_PIN4
#define KPD_C1    DIO_PIN5
#define KPD_C2    DIO_PIN6
#define KPD_C3    DIO_PIN7

#endif /* KPD_CONFIG_H_ */
