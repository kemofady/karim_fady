/* library **/
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/* mcal */

#include"../DIO_driver/Dio_Interface.h"

/* own  drive*/
#include"LCD_cfg.h"
#include"LCD_interface.h"





void LCD_voidinit(){
	Dio_voidSetPortDirection(LCD_DATA_PORT,DIO_OUTPUT);
	Dio_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_OUTPUT);
	Dio_voidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_OUTPUT);
	Dio_voidSetPinDirection(LCD_E_PORT,LCD_E_PIN,DIO_OUTPUT);



	_delay_ms(40);
	LCD_voidsendcommand(0b00111000);
	_delay_ms(1);
	LCD_voidsendcommand(0b00001100);
	_delay_ms(1);
	LCD_voidsendcommand(0b00000001);
	_delay_ms(2);
	LCD_voidsendcommand(0b00000110);
}


void LCD_voidsendcommand(u8 cpy_u8command){
	Dio_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	Dio_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	Dio_voidSetPortValue(LCD_DATA_PORT,cpy_u8command);
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);
}
void LCD_voidsenddata(u8 cpy_u8data){
	Dio_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_HIGH);
	Dio_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	Dio_voidSetPortValue(LCD_DATA_PORT,cpy_u8data);
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	Dio_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);
}




void LCD_voidsendstring(u8* str){
	u8 index;
	for (index=0 ; str[index]!='\0';index++) // '\0' It expresses to NULL the end of string
	{
		LCD_voidsenddata(str[index]);
	}

}
void LCD_voidsendnumber(u8* str){
	u8 index;
	for (index=0 ; str[index]!='\0';index++) // '\0' It expresses to NULL the end of string
	{
		LCD_voidsenddata(str[index]);
	}

}






void LCD_gotoxy(u8 cpy_u8x,u8 cpy_u8y){
u16 address=(cpy_u8x*64)+cpy_u8y+128 ;
LCD_voidsendcommand(address);
}


void LCD_voidpattern(u8 cpy_u8blocknum,u8* cpy_u8patternarr){
	u8 adress= 64 + (8*cpy_u8blocknum);
	LCD_voidsendcommand(adress);
	for(u8 i=0;i<9;i++){
		LCD_voidsenddata(cpy_u8patternarr[i]);

	}
	LCD_voidsendcommand(0x02);   //command to return back home
}

void  LCD_voidnameinsinusoidal(){
	u8 row=1;
	u8 column=0;
	for(column=0;column<12;column++){
		row^=1;  //To be placed once by 1 and once by 0
		LCD_gotoxy(row,column);
		LCD_voidsendstring("karim");
		_delay_ms(250);
		LCD_voidsendcommand(0x01);   // clear name
	}
}

void LCD_voidclearscrean(){
	LCD_voidsendcommand(0x01);
}





