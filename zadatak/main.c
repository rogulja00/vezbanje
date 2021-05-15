/**
 * @file	main.c
 * @brief	Zadatak
 * @author	Alekandar Rogulja
 * @date	15-05-2021
 */

#include <avr/io.h>s
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>  // biblioteka za integer tipove podataka :)
#include "../biblioteka/usart.h"

int main()
{
	usartInit(9600);
	int8_t suma;
	int8_t string[64];
	int8_t duzina;
	int8_t s_suma[64];
	while(1)
	{
		usartPutString("Unesite broj: \r\n");
		while(!usartAvailable());
		_delay_ms(150);

		usartGetString(string);

		suma = 0;
		duzina = strlen(string);

		for (int8_t i = 0; i < duzina; i++)
		{
			suma = suma + (string[i] - '0');
		}

		sprintf(s_suma, "%d\0", suma);
		usartPutString("Zbir cifara je ");
		usartPutString(s_suma);
		usartPutString("\r\n");

	}
	return 0;
}
