/*
 * drivers V1.c
 *
 * Created: 9/20/2021 1:33:51 PM
 * Author : Karim Essam
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/USART/USART_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/DIO/DIO_interface.h"

int main(void)
{
    /* Replace with your application code */
	USART_voidInit(TRANSMIT_RECIEVE , ASYNCRONOUS , EIGHT_BITS , DISAPLED , TWO_STOP_BIT , 2400);
	LCD_voidInit();
	/*
	SPI_voidInit(MASTER_MODE , MSB , LEADING_IS_RISING , LEADING_IS_SAMPLE , SPI_PRESCALAR_16);
	for (u8 i = 0 ; i < 10 ; i++)
	{
		SPI_voidMasterTransmit(i);
		_delay_ms(100);
	}
	*/
	u8 string[10];
	u8 i = 0;
    while (1) 
    {
		u8 data = USART_u8RecieveData();
		string[i++] = data;
		LCD_voidSendChar(data);
		if (data == '\r')
		{
			string[i] = NULL;
			USART_voidTransmitString(string);
		}
		
    }
}

