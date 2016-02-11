/*
 * LCD.h
 *
 *  Created on: Nov 6, 2015
 *      Author: ahmed
 */

#ifndef LCD_H_
#define LCD_H_

void lcd_init();
void lcd_data(char data);
void lcd_command(char cmd);
void lcd_string(char *data);

#endif /* LCD_H_ */
