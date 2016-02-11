/*
 * UART.h
 *
 *  Created on: Nov 6, 2015
 *      Author: ahmed
 */

#ifndef UART_H_
#define UART_H_

void usart_init();
void usart_transmit(char data);
char usart_receive(void);
void usart_string(char * data);

#endif /* UART_H_ */
