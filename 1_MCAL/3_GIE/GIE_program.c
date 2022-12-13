/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GIE_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"

/*
 * Breif : This Function used to enable General Interrupt Enable (GIE)
 * Parameters : Nothing
 * return : Nothing
*/
void GIE_VoidEnable (void)
{
	SET_BIT (SREG , SREG_I) ;
}
/*
 * Breif : This Function used to disable General Interrupt Enable (GIE)
 * Parameters : Nothing
 * return : Nothing
*/
void GIE_VoidDisable (void)
{
	CLR_BIT (SREG , SREG_I) ;
}
