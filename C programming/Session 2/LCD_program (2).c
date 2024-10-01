/******************************************************
 *Author: Mohammed Essam Eldeeb
 *Layer: HAL
 *SWC: LCD
 *version: 1.00
 ******************************************************/



#include "..\Library\STD_TYPES.h"
#include "..\Library\BIT_MATH.h"
#include <util/delay.h>

#include "..\DIO\DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_registers.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <stdlib.h>

void LCD_void_Init()
{
	/* wait for more than 30 milliseconds */
	_delay_ms(30);
	DIO_uint8_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_uint8_PIN_OUTPUT);

	DIO_uint8_SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_uint8_PIN_OUTPUT);

	DIO_uint8_SetPinDirection(LCD_CTRL_PORT, LCD_E_PIN, DIO_uint8_PIN_OUTPUT);

	DIO_uint8_SetPortDirection(LDC_DATA_PORT, DIO_uint8_PIN_OUTPUT);

	/* function set command: 2 lines and 5*8 font */
	LCD_void_SendCommand(LCD_SET_LINES_FONT);

	/* display on off control: display on, cursor off, blink off */
	LCD_void_SendCommand(LCD_SET_DIPLAY_CURSOR_BLINK);

	/* Display clear */
	LCD_void_SendCommand(LCD_CLEAR_DISPLAY);

}

void LCD_void_SendCommand(uint8 copy_uint8_command)
{
	/* set RS pin to low for command*/
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_uint8_LOW);

	/* set RW pin to low for write */
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_uint8_LOW);

	/* send command uisng data bits */
	DIO_uint8_SetPortValue(LDC_DATA_PORT, copy_uint8_command);

	/* send enable pusle */
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_uint8_HIGH);
	_delay_ms(2);
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_uint8_LOW);

}

void LCD_void_SendData(uint8 copy_uint8_data)
{
	/* set RS pin to High for Data*/
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_uint8_HIGH);

	/* set RW pin to low for write */
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_uint8_LOW);

	/* send command using data bits */
	DIO_uint8_SetPortValue(LDC_DATA_PORT, copy_uint8_data);

	/* send enable pulse */
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_uint8_HIGH);
	_delay_ms(2);
	DIO_uint8_SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_uint8_LOW);

}

void LCD_void_SendString(const char *copy_puint8_string)
{
	uint8 local_uint8_iterator = STD_LOW;
	while (copy_puint8_string[local_uint8_iterator] != '\0')
	{
		if(local_uint8_iterator == END_OF_FIRST_LINE)
		{
			LCD_void_GoToXY(SECOND_COLOMN, FIRST_ROW);
			LCD_void_SendData(copy_puint8_string[local_uint8_iterator]);
			local_uint8_iterator++;

		}
		else
		{
			LCD_void_SendData(copy_puint8_string[local_uint8_iterator]);
			local_uint8_iterator++;
		}

	}

}

void LCD_void_GoToXY(uint8 copy_uint8_xPosition, uint8 copy_uint8_yPosition)
{
	uint8 local_uint8_address;
	if(copy_uint8_xPosition == 0)
	{
		local_uint8_address = copy_uint8_yPosition + SHIFT_IN_MEMORY_IN_COLOUMN_ONE;
	}
	else if (copy_uint8_xPosition == 1)
	{
		local_uint8_address = copy_uint8_yPosition + SHIFT_IN_MEMORY_IN_COLOUMN_TWO;
	}
	LCD_void_SendCommand(local_uint8_address);
}

void LCD_void_WriteSpecialCharacter(uint8 * copy_puint8_pattern, uint8 copy_uint8_patternNumber, uint8 copy_uint8_xPosition, uint8 copy_uint8_yPosition)
{
	uint8 local_CGRamAddress = STD_LOW;
	uint8 local_uint8_iterator = STD_LOW;


	/* calculate the CG Ram address, each block is 8 bytes	 */
	local_CGRamAddress = copy_uint8_patternNumber * BLOCK_SIZE ;

	/* send CG ram address command to LCD, with setting bit 6, clearing bit 8 */
	LCD_void_SendCommand(local_CGRamAddress + SHIFT_IN_ADDRESS);

	for(local_uint8_iterator = STD_LOW; local_uint8_iterator < BLOCK_SIZE; local_uint8_iterator++)
	{
		LCD_void_SendData(copy_puint8_pattern[local_uint8_iterator]);
	}
	/* go back to DDRam to display pattern */
	LCD_void_GoToXY(copy_uint8_xPosition, copy_uint8_yPosition);

	LCD_void_SendData(copy_uint8_patternNumber);

}

void LCD_void_WriteNumber(sint32 copy_sint32_number)
{
	uint8 local_uint8_numberLength = STD_LOW;
	sint32 local_sint32_numberCopy = copy_sint32_number;
	uint8 local_uint8_singleDigit = STD_LOW;
	char *ptr = NULL;
	if (copy_sint32_number < 0)
	{
		copy_sint32_number *= CHANGE_FROM_POSITIVE_TO_NEGATIVE ;
		while(local_sint32_numberCopy)
		{
			local_sint32_numberCopy /= DIVISION_FACTOR_10 ;
			local_uint8_numberLength ++;
		}
		ptr = (char *)malloc(local_uint8_numberLength*sizeof(char));
		local_sint32_numberCopy = copy_sint32_number;
		while(local_sint32_numberCopy)
		{
			local_uint8_singleDigit =  local_sint32_numberCopy % DIVISION_FACTOR_10 ;
			local_sint32_numberCopy /= DIVISION_FACTOR_10;
			*(ptr + local_uint8_numberLength -ARRAY_OFFSET) = local_uint8_singleDigit + ASCII_OFFSET;
			local_uint8_numberLength--;
		}
		LCD_void_SendData('-');
		LCD_void_SendString(ptr);
		free(ptr);
	}
	else if(local_sint32_numberCopy == 0)
	{
		LCD_void_SendData('0');
	}
	else
	{
		while(local_sint32_numberCopy)
		{
			local_sint32_numberCopy /= DIVISION_FACTOR_10 ;
			local_uint8_numberLength ++;
		}
		ptr = (char *)malloc(local_uint8_numberLength*sizeof(char));
		local_sint32_numberCopy = copy_sint32_number;
		while(local_sint32_numberCopy)
		{
			local_uint8_singleDigit =  local_sint32_numberCopy % DIVISION_FACTOR_10 ;
			local_sint32_numberCopy /= DIVISION_FACTOR_10;
			*(ptr + local_uint8_numberLength -ARRAY_OFFSET) = local_uint8_singleDigit + ASCII_OFFSET;
			local_uint8_numberLength--;
		}
		LCD_void_SendString(ptr);
		free(ptr);
	}
}

