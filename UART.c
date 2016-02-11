/*
 * UART.c
 *
 *  Created on: Nov 6, 2015
 *      Author: ahmed
 */

#include <util/delay.h>
#include "gpio.h"
#include "UART.h"

void usart_init() {

	ucsra = 0x00;
	ucsrb = (1 << rxen) | (1 << txen);                     // Enable Receiver and Transmitter
	ucsrc = (1 << ursel) | (1 << ucsz0) | (1 << ucsz1);    //       |  8 Bit mode
	ubrrl = 51;                                            // BaudRate = 9600
	ubrrh = 0;                                             // UBRR is 16 Bit, 8 bit in UBRRL = 00110011 = 51, 8 bit in UBRRH = 00000000 = 0
}

void usart_transmit(char data) {
	udr = data;
	while((ucsra & (1 << udre)) == 0);                     // Wait for empty transmit buffer
}

char usart_receive(void) {
	while((ucsra & (1 << rxc)) == 0);                      // Wait for received data to be completed
	return udr;
}

void usart_string(char * data) {
	char ch;
	char i = 0;

	while( (ch = usart_receive()) != 13 ) {
		data[i] = ch;
		i++;
	}
}
