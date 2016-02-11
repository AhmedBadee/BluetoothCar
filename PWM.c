/*
 * PWM.c
 *
 *  Created on: Nov 8, 2015
 *      Author: ahmed
 */

#include "gpio.h"
#include "PWM.h"

void pwm_init() {
	tccr0 = (1 << wgm00)                                                 // PWM, phase correct
			| (1 << com00) | (1 << com01)                                // Set OC0 up-counting, Clear OC0 down-counting
			| (1 << cs00) | (1 << cs02);                                 // 1024 prescaler

	ddrb |= (1 << pb3);                                                  // Set OC0 pin as output

	tccr2 = (1 << wgm20)
		    | (1 << com20) | (1 << com21)
			| (1 << cs20) | (1 << cs21) | (1 << cs22);

	ddrd |= (1 << pd7);
}
