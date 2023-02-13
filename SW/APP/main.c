/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: Eng_Omar
 */


/*includes*/
#include <avr/io.h>
#include <string.h>
#include "lcd.h"
#include "Interrupt.h"
#include "../HAL/Timer_driver/timer0.h"
/*******************************************************/
/*Constants*/




/*******************************************************/
/*global variables*/

	uint16 looper=0;
	/*This looper variable will be used to loop on the first 11 bytes
	 *in the EEPROM and store thir values then display them on the LCD*/
	uint16 Data_Stored=0;
	/*This variable will hold the data stored in the 10 byte block in the EEPROM
	 *Byte per byte them display them */

	uint16 First_Byte_Write=1;
	uint16 First_Byte_Read=0;


/*******************************************************/

/*functions prototypes*/
void timer0_func(void);
void Set_NVM(void);
void Check_NVM(void);
int main(void)
{

	LCD_init(); /* initialize LCD */
	LCD_clearScreen(); /* clear the LCD display */
	/*call the function which will init the timer0 module with frequency of (Fcpu/8)*/
	Timer0_Normal_Mode_Init(No_Prescaler);
	Update_Ptr2appfunc(timer0_func);//Update the pointer to app function with the written function address
	LCD_displayStringRowColumn(0,1,"Display trial");
	LCD_clearScreen();
	Set_NVM();
	LCD_displayStringRowColumn(0,1,"Intial the NVM=");
	_delay_ms(2000);
	LCD_clearScreen();
	Check_NVM();
	LCD_displayStringRowColumn(0,1,"Check on NVM=");
	_delay_ms(2000);
	LCD_clearScreen();



	while(1)
	{
		if(looper==256)
		{
			LCD_displayStringRowColumn(0,1,"Looper = 256");
			_delay_ms(2000);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,1,"Looper =");
			LCD_intgerToString(looper);
			_delay_ms(2000);
		}
		else if(looper<256)
		{
			LCD_displayStringRowColumn(0,1,"Looper < 256");
			_delay_ms(2000);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,1,"Looper =");
			LCD_intgerToString(looper);
			_delay_ms(2000);
		}
		else
		{
			LCD_displayStringRowColumn(0,1,"Looper > 256");
			_delay_ms(2000);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,1,"Looper =");
			LCD_intgerToString(looper);
			_delay_ms(2000);
		}
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,1,"Add(0) =");
		LCD_intgerToString(eeprom_read_word((uint16*)0));
		_delay_ms(2000);

		LCD_clearScreen();
		LCD_displayStringRowColumn(0,1,"Add(257) =");
		LCD_intgerToString(eeprom_read_word((uint16*)257));
		_delay_ms(2000);











	}
	return 0;

}


/*************************Functions Bodies******************************/

/*This function is  used to be called to do what is required from timer0 timeout*/
void timer0_func(void)
{

}

/*This function is used intialize the NVM with all addresses equal ZERO except the first addresse  */

void Set_NVM(void)
{
	eeprom_write_word((uint16*)0,(uint16)1);
	for(uint16 i=1;i<=256;i++)
	{
		eeprom_write_word((uint16*)i,(uint16)0);
	}

}

void Check_NVM(void)
{
	Data_Stored=eeprom_read_word((uint16*)0);
	if(Data_Stored==(uint16)1)
	{
		looper=1;
	}
	for(uint16 i=1;i<=256;i++)
	{
		Data_Stored=eeprom_read_word((uint16*)i);
		if(Data_Stored==(uint16)0)
		{
			looper++;
		}
	}
}
