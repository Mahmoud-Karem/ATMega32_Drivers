/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SPI_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : SPI
 *
 */
 
#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"


/*Global variable to carry the Transmit Data*/
static u8 * SPI_pu8TData = NULL ;

/*Global variable to carry the Receive Data*/
static u8 * SPI_pu8RData = NULL ;

/*Global variable to carry the buffer size*/
static u8 SPI_u8BufferSize;

/*Global variable to indicate for the current Data index of the buffer*/
static u8 SPI_u8Index;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* SPI_pvNotificationFunc)(void)= NULL;

/*Global flag for the SPI Busy State*/
static u8 SPI_u8State= IDLE ;


//-------------------------------------------------------------------------------------------------------------------------------

void SPI_VoidInit(void)
{
	/*Data Order*/
	#if SPI_DATA_ORDER == SPI_DATA_LSB_FIRST
		SET_BIT(SPCR , SPCR_DORD) ;
	#elif SPI_DATA_ORDER == SPI_DATA_MSP_FIRST
		CLR_BIT(SPCR , SPCR_DORD) ;
	#else
		#error "wrong SPI_DATA_ORDER config"
	#endif

	/*Master/Slave Select*/
	#if SPI_MASTER_SLAVE_SELECT == SPI_MASTER
		SET_BIT(SPCR , SPCR_MSTR) ;
	#elif SPI_MASTER_SLAVE_SELECT == SPI_SLAVE
		CLR_BIT(SPCR , SPCR_MSTR) ;
	#else
		#error "wrong SPI_MASTER_SLAVE_SELECT config"
	#endif

	/*Clock Polarity*/
	#if SPI_CLOCK_POLARITY == SPI_RISING_LEADING_FALLING_TRAILING
		CLR_BIT(SPCR , SPCR_CPOL) ;
	#elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
		SET_BIT(SPCR , SPCR_CPOL) ;
	#else
		#error "wrong SPI_CLOCK_POLARITY config"
	#endif

	/*Clock Phase*/
	#if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING
		CLR_BIT(SPCR , SPCR_CPHA) ;

	#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
		SET_BIT(SPCR , SPCR_CPHA) ;
	#else
		#error "wrong SPI_CLOCK_PHASE config"
	#endif

	/*Clock Rate*/
	#if SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_2
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_4
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_8
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_16
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_32
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_64
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_128
		SET_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#else
		#error "wrong SPI_CLOCK_RATE config"
	#endif

	/*SPI Interrupt Enable*/
	#if SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_DISABLE
		CLR_BIT(SPCR , SPCR_SPIE) ;
	#elif SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_ENABLE
		SET_BIT(SPCR , SPCR_SPIE) ;
	#else
		#error "wrong SPI_INTERRUPT_ENABLE_MODE config"
	#endif

	/*SPI Enable*/
	#if SPI_ENABLE_MODE == SPI_DISABLE
		CLR_BIT(SPCR , SPCR_SPE) ;
	#elif SPI_ENABLE_MODE == SPI_ENABLE
		SET_BIT(SPCR , SPCR_SPE) ;
	#else
		#error "wrong SPI_ENABLE_MODE config"
	#endif

}




//-------------------------------------------------------------------------------------------------------------------------------
/*
	Hint : This Func For Postbuild Config
	
	The Options For The Element Of The Struct :-
	
		$ SPI_u8InterruptEnable :
			1-SPI_INTERRUPT_DISABLE
			2-SPI_INTERRUPT_ENABLE:
			
		$ SPI_u8SPIEnable :
			1-SPI_DISABLE
			2-SPI_ENABLE
			
		$ SPI_u8DataOrder :
			1-SPI_DATA_MSP_FIRST
			2-SPI_DATA_LSB_FIRST
			
		$ SPI_u8MasterSlaveSelect :
			1-SPI_MASTER
			2-SPI_SLAVE
			
		$ SPI_u8ClockPolarity :
			1-SPI_RISING_LEADING_FALLING_TRAILING
			2-SPI_FALLING_LEADING_RISING_TRAILING
			
		$ SPI_u8ClockPhase :
			1-SPI_SAMPLE_LEADING_SETUP_TRAILING
			2-SPI_SETUP_LEADING_SAMPLE_TRAILING
			
		$ SPI_u8ClockRate :
			1-SPI_FREQ_DIVIDED_BY_2
			2-SPI_FREQ_DIVIDED_BY_4
			3-SPI_FREQ_DIVIDED_BY_8
			4-SPI_FREQ_DIVIDED_BY_16
			5-SPI_FREQ_DIVIDED_BY_32
			6-SPI_FREQ_DIVIDED_BY_64
			7-SPI_FREQ_DIVIDED_BY_128
			
		
*/

u8 SPI_u8InitConfig (SPI_CONFIG * spi)
{
	u8 Local_u8ErrorState = OK ;

	if ((spi != NULL) && (spi->SPI_u8ClockPhase != NULL) && (spi->SPI_u8ClockPolarity != NULL) && (spi->SPI_u8ClockRate != NULL) && (spi->SPI_u8DataOrder != NULL) && (spi->SPI_u8InterruptEnable != NULL) && (spi->SPI_u8MasterSlaveSelect != NULL) && (spi->SPI_u8SPIEnable != NULL))
	{
		switch (spi->SPI_u8ClockPhase)
		{
		case SPI_SAMPLE_LEADING_SETUP_TRAILING: CLR_BIT(SPCR , SPCR_CPHA) ; break ;
		case SPI_SETUP_LEADING_SAMPLE_TRAILING: SET_BIT(SPCR , SPCR_CPHA) ; break ;
		default: 								Local_u8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_u8ClockPolarity)
		{
		case SPI_RISING_LEADING_FALLING_TRAILING: CLR_BIT(SPCR , SPCR_CPOL) ; break ;
		case SPI_FALLING_LEADING_RISING_TRAILING: SET_BIT(SPCR , SPCR_CPOL) ; break ;
		default:								  Local_u8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_u8ClockRate)
		{
		case SPI_FREQ_DIVIDED_BY_2:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_4:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_8:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_16:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_32:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_64:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_128:
			SET_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		default:
			Local_u8ErrorState = NOK ;
			break ;
		}
		switch (spi->SPI_u8DataOrder)
		{
		case SPI_DATA_MSP_FIRST: CLR_BIT(SPCR , SPCR_DORD) ; break ;
		case SPI_DATA_LSB_FIRST: SET_BIT(SPCR , SPCR_DORD) ; break ;
		default:				 Local_u8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_u8MasterSlaveSelect)
		{
		case SPI_MASTER: SET_BIT(SPCR , SPCR_MSTR) ; break ;
		case SPI_SLAVE:  CLR_BIT(SPCR , SPCR_MSTR) ; break ;
		default:		 Local_u8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_u8InterruptEnable)
		{
		case SPI_INTERRUPT_DISABLE: CLR_BIT(SPCR , SPCR_SPIE) ; break ;
		case SPI_INTERRUPT_ENABLE:  SET_BIT(SPCR , SPCR_SPIE) ; break ;
		default:		 			Local_u8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_u8SPIEnable)
		{
		case SPI_DISABLE: CLR_BIT(SPCR , SPCR_SPE) ; break ;
		case SPI_ENABLE:  SET_BIT(SPCR , SPCR_SPE) ; break ;
		default:		  Local_u8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

//-------------------------------------------------------------------------------------------------------------------------------

u8 SPI_u8Tranceive (u8 Copy_u8TData , u8 * Copy_u8RData)
{
	u8 Local_u8ErrorState = OK ;
	uint32 Local_uint32TimeoutCounter = 0 ;

	if (SPI_u8State == IDLE)
	{
		SPI_u8State = BUSY ;

		SPDR = Copy_u8TData ;

		while (((GET_BIT(SPSR , SPSR_SPIF)) == 0) && (Local_uint32TimeoutCounter < SPI_uint32TIMEOUT))
		{
			Local_uint32TimeoutCounter++ ;
		}
		if (Local_uint32TimeoutCounter == SPI_uint32TIMEOUT)
		{
			Local_u8ErrorState = TIMEOUT_STATE ;
		}
		else
		{
			* Copy_u8RData = SPDR ;
		}
		SPI_u8State = IDLE ;
	}
	else
	{
		Local_u8ErrorState = BUSY_STATE ;
	}

	return Local_u8ErrorState ;
}

//-------------------------------------------------------------------------------------------------------------------------------

u8 SPI_u8BufferTranceiverSynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState = OK ;
	u8 Local_u8Counter = 0 ;
	if ((Copy_u8TData != NULL) && (Copy_u8RData != NULL))
	{
		while (Local_u8Counter < Copy_u8BufferSize)
		{
			SPI_u8Tranceive(Copy_u8TData[Local_u8Counter] , &Copy_u8RData[Local_u8Counter]) ;
			Local_u8Counter++ ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

//-------------------------------------------------------------------------------------------------------------------------------

u8 SPI_u8BufferTranceiverAsynch (SPI_BUFFER * spi_buffer)
{
	u8 Local_u8ErrorState = OK ;

	if (SPI_u8State == IDLE)
	{
		if ((spi_buffer != NULL) && (spi_buffer->Copy_u8TData != NULL) && (spi_buffer->Copy_u8RData != NULL) && (spi_buffer->NotificationFuncn != NULL))
		{
			/*SPI is now Busy*/
			SPI_u8State = BUSY ;

			/*Assign the SPI data globally*/
			SPI_pu8TData = spi_buffer->Copy_u8TData ;
			SPI_pu8RData = spi_buffer->Copy_u8RData ;
			SPI_u8BufferSize = spi_buffer->Copy_u8BufferSize ;
			SPI_pvNotificationFunc = spi_buffer->NotificationFuncn ;

			/*Set Index to first element*/
			SPI_u8Index = 0 ;

			/*Transmit first Data */
			SPDR = SPI_pu8TData[SPI_u8Index] ;

			/*SPI Interrupt Enable*/
			SET_BIT(SPCR , SPCR_SPIE) ;
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER ;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_STATE ;
	}
	return Local_u8ErrorState ;
}

//-------------------------------------------------------------------------------------------------------------------------------

void __vector_12 (void)		__attribute__ ((signal)) ;
void __vector_12 (void)
{
	/*Receive Data*/
	SPI_pu8RData[SPI_u8Index] = SPDR ;

	/*Increment Data index of the buffer*/
	SPI_u8Index++ ;

	if (SPI_u8Index == SPI_u8BufferSize)
	{
		/*Buffer Complete*/

		/*SPI is now IDLE*/
		SPI_u8State = IDLE ;

		/*SPI Interrupt Disable*/
		CLR_BIT(SPCR , SPCR_SPIE) ;

		/*Call Notification Function*/
		SPI_pvNotificationFunc() ;
	}
	else
	{
		/*Buffer not Complete*/

		/*Transmit next Data*/
		SPDR = SPI_pu8TData[SPI_u8Index] ;
	}
}
