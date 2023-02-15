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

/*****************Definations****************************/
//#define First_Code      0
/*This Macro will be used to activate the set EEPROM function to make each byte in the EEprom equal 0xff*/





/*******************************************************/
/*******************************************************/
/*Constants*/




/*******************************************************/
/*global variables*/
#ifdef  First_Code
	uint16 looper=0;
	/*This looper variable will be used to loop on the first 11 bytes
	 *in the EEPROM and store thir values then display them on the LCD*/
	uint16 Data_Stored=0;
	/*This variable will hold the data stored in the 10 byte block in the EEPROM
	 *Byte per byte them display them */
#endif


/*******************************************************/

/*functions prototypes*/
void timer0_func(void);
#ifdef  First_Code
void Set_NVM_To_Max(void);
void Check_NVM(void);
#endif
int main(void)
{

	LCD_init(); /* initialize LCD */
	LCD_clearScreen(); /* clear the LCD display */
	/*call the function which will init the timer0 module with frequency of (Fcpu/8)*/
	Timer0_Normal_Mode_Init(No_Prescaler);
	Update_Ptr2appfunc(timer0_func);//Update the pointer to app function with the written function address

#ifdef  First_Code
	LCD_displayStringRowColumn(0,1,"Display trial");
	Set_NVM_To_Max();
	LCD_displayStringRowColumn(0,1,"Intial the NVM=");
	_delay_ms(2000);
	LCD_clearScreen();
#endif

#ifdef  First_Code
	Check_NVM();
	LCD_displayStringRowColumn(0,1,"Check on NVM=");
	_delay_ms(2000);
	LCD_clearScreen();
#endif




	while(1)
	{








#ifdef First_Code
		if(looper==512)
		{
			LCD_displayStringRowColumn(0,1,"Looper = 512");
			_delay_ms(2000);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,1,"Looper =");
			LCD_intgerToString(looper);
			_delay_ms(2000);
		}
		else if(looper<512)
		{
			LCD_displayStringRowColumn(0,1,"Looper < 512");
			_delay_ms(2000);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,1,"Looper =");
			LCD_intgerToString(looper);
			_delay_ms(2000);
		}
		else
		{
			LCD_displayStringRowColumn(0,1,"Looper > 512");
			_delay_ms(2000);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,1,"Looper =");
			LCD_intgerToString(looper);
			_delay_ms(2000);
		}
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,1,"Add(0) =");
		LCD_intgerToString(eeprom_read_byte((uint8*)0));
		_delay_ms(2000);

		LCD_clearScreen();
		LCD_displayStringRowColumn(0,1,"Add(512) =");
		LCD_intgerToString(eeprom_read_byte((uint8*)512));
		_delay_ms(2000);
#endif

	}
	return 0;

}


/*************************Functions Bodies******************************/

/*This function is  used to be called to do what is required from timer0 timeout*/
void timer0_func(void)
{

}
#ifdef  First_Code
/*This function is used intialize the NVM with all addresses equal ZERO except the first addresse  */

void Set_NVM_To_Max(void)
{
	for(uint16 i=0;i<512;i++)
	{
		eeprom_write_byte((uint8*)i,(uint8)0xff);
	}

}

void Check_NVM(void)
{

	for(uint16 i=0;i<512;i++)
	{
		Data_Stored=eeprom_read_byte((uint8*)i);
		if(Data_Stored==(uint8)0xff)
		{
			looper++;
		}
	}
}
#endif
