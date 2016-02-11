/*
 * main.c
 *
 *  Created on: Nov 6, 2015
 *      Author: ahmed
 */

#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include "gpio.h"
#include "UART.h"
#include "LCD.h"
#include "PWM.h"

int retDir(char *cmd);

int main() {

	usart_init();
	lcd_init();
	pwm_init();

	char data[5] = {};

	while(1) {

		usart_string(data);

		switch (retDir(data) /*direction*/) {
		case 1:
			lcd_command(0x01);
			_delay_ms(2);
			lcd_string("forward");
			ocr2 = 0;
			ocr0 = 200;
			break;
		case 2:
			lcd_command(0x01);
			_delay_ms(2);
			lcd_string("backward");
			ocr0 = 0;
			ocr2 = 200;
			break;
		case 3:
			lcd_command(0x01);
			_delay_ms(2);
			lcd_string("stopped");
			ocr0 = 0;
			ocr2 = 0;
			break;
		default:
			lcd_command(0x01);
			_delay_ms(2);
			ocr0 = 0;
			ocr2 = 0;
		}
	}
}


int retDir(char *cmd) {
	if (strcmp( cmd, "up") == 0 || strcmp( cmd, "upwn") == 0 || strcmp( cmd, "upop") == 0)
		return 1;
	else if (strcmp( cmd, "down") == 0)
		return 2;
	else if (strcmp( cmd, "stop") == 0)
		return 3;

	return 0;
}
