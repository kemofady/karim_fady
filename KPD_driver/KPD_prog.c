/*****************************************************/
/* 1 - include libraries */
#include "../Dio_driver/STD_TYPES.h"
#include "BIT_MATH.h"

/* 2 - MCAL */
#include "../DIO_driver/Dio_Interface.h"

/* OWN DRIBER INCLUDE */
#include "KPD_interface.h"
#include "KPD_Private.h"
#include "KPD_cfg.h"


const u8 KPD_SwitchVal[4][4]={
		{'1','2','3','/'},
		{'4','5','6','*'},
		{'7','8','9','-'},
		{'o','0','=','+'}
};


u8 r_pins[4] ={DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3};
u8 c_pins[4] ={DIO_PIN4,DIO_PIN5,DIO_PIN6,DIO_PIN7};


void KPD_voidInit(void)
{
	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN0 , DIO_OUTPUT);
	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN1 , DIO_OUTPUT);
	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN2 , DIO_OUTPUT);
	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN3 , DIO_OUTPUT);

	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN4 , DIO_INPUT);
	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN5 , DIO_INPUT);
	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN6 , DIO_INPUT);
	Dio_voidSetPinDirection(KPD_PORT ,DIO_PIN7 , DIO_INPUT);

	Dio_voidSetPortValue(KPD_PORT , 0XFF);


}


u8 KPD_u8GETPressedKey(void){
	u8 key =0xff;       //NO key pressed

	for(u8 r=0 ;r<4;r++){
	Dio_voidSetPinValue(KPD_PORT , r_pins[r] , DIO_LOW);

	for(u8 c=0 ;c<4;c++){
		if (Dio_u8GetPinValue(KPD_PORT , c_pins[c] )== DIO_LOW){
			key = KPD_SwitchVal[r][c];
		}
		// polling  busy wait until event (No longer pressing )
		while (Dio_u8GetPinValue(KPD_PORT , c_pins[c] )== DIO_LOW ){
			}
		}

	Dio_voidSetPinValue(KPD_PORT , r_pins[r] , DIO_HIGH);
	}
	return key;
}





