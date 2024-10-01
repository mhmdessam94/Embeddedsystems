/******************************************************
 *Author: Mohammed Essam Eldeeb
 *Layer: HAL
 *SWC: LCD
 *version: 1.00
 ******************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


#define LDC_DATA_PORT						DIO_uint8_PORTA
#define LCD_CTRL_PORT						DIO_uint8_PORTC

#define LCD_RS_PIN							DIO_uint8_PIN0
#define LCD_RW_PIN							DIO_uint8_PIN1
#define LCD_E_PIN							DIO_uint8_PIN2



#define LCD_SET_LINES_FONT					0b00111000
#define LCD_SET_DIPLAY_CURSOR_BLINK			0b00001100
#define LCD_CLEAR_DISPLAY					0b00000001





#endif
