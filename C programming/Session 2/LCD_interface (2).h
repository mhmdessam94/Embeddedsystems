/******************************************************
 *Author: Mahmoud Khaled Alnmr
 *Layer: HAL
 *SWC: LCD
 *version: 1.00
 ******************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H




void LCD_void_Init();

void LCD_void_SendCommand(uint8 copy_uint8_command);

void LCD_void_SendData(uint8 copy_uint8_data);

void LCD_void_SendString(const char *copy_puint8_string);

void LCD_void_GoToXY(uint8 copy_uint8_xPosition, uint8 copy_uint8_yPosition);

void LCD_void_WriteSpecialCharacter(uint8 * copy_puint8_pattern, uint8 copy_uint8_patternNumber, uint8 copy_uint8_xPosition, uint8 copy_uint8_yPosition);

void LCD_void_WriteNumber(sint32 copy_sint32_number);




#endif



