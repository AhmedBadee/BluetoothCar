/*
 * gpio.h
 *
 *  Created on: Nov 7, 2015
 *      Author: ahmed
 */

#include <avr/io.h>

#ifndef GPIO_H_
#define GPIO_H_

/********* I/O *********/
#define porta PORTA
#define portb PORTB
#define portc PORTC
#define portd PORTD

#define ddra DDRA
#define ddrb DDRB
#define ddrc DDRC
#define ddrd DDRD

#define pina PINA
#define pinb PINB
#define pinc PINC
#define pind PIND

#define pb3 PB3
#define pd7 PD7


/********* LCD *********/
#define RS 0
#define RW 1
#define EN 2


/********* UART ********/
#define ubrrl UBRRL
#define ubrrh UBRRH
#define ucsra UCSRA
#define ucsrb UCSRB
#define ucsrc UCSRC
#define rxen RXEN
#define txen TXEN
#define ursel URSEL
#define ucsz0 UCSZ0
#define ucsz1 UCSZ1

#define udre UDRE
#define udr UDR

#define rxc RXC


/********* PWM *********/
//     Timer 0
#define tccr0 TCCR0
#define wgm00 WGM00
#define com00 COM00
#define com01 COM01
#define cs00 CS00
#define cs02 CS02
#define ocr0 OCR0


//     Timer 2
#define tccr2 TCCR2
#define wgm20 WGM20
#define com20 COM20
#define com21 COM21
#define cs20 CS20
#define cs21 CS21
#define cs22 CS22
#define ocr2 OCR2


#endif /* GPIO_H_ */
