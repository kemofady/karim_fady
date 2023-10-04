/* library **/
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/* mcal */

#include"DIO_driver/Dio_Interface.h"

/* own  drive*/
#include"LCD_driver/LCD_interface.h"
#include "KPD_driver/KPD_interface.h"
void main()
{
	u8 local_u8key=0xff;   // not pressed
	LCD_voidinit();
	KPD_voidInit();
	u8 arr_u8password[4]={'1','2','3','4'};
	u8 arr_u8user[4]={0};
	u8 flag=0;  // if password is not correct
	u8 counter_u8incorrectpas =0;
	while(1)
	{

		for(u8 i=0;i<4;i++)
		{
		do{
			local_u8key = KPD_u8GETPressedKey();

				}while(local_u8key == 0xff);
			arr_u8user[i]=local_u8key;
			LCD_voidsenddata('*');
		}
		 LCD_voidclearscrean();
        for(u8 i=0;i<4;i++){
        	if(arr_u8password[i]==arr_u8user[i]){
        		flag=0;
        	}
        	else{
        		 LCD_voidsendstring("WRONG PASSWORD");
        		 _delay_ms(1000);
        		 LCD_voidclearscrean();
        		 flag=1;
        		 counter_u8incorrectpas++;
        		 break;
        	}
        }

        if(flag==0){
        	LCD_gotoxy(0,4);
        	LCD_voidsendstring("WELCOME");
        	_delay_ms(2000);
        }
        if(counter_u8incorrectpas==3){
        	LCD_voidsendstring("WRONG PASSWORD");
        	LCD_gotoxy(1,2);
        	LCD_voidsendstring("THREE TIMES");
        	_delay_ms(2000);
        	LCD_voidclearscrean();
        	return;
        }

        LCD_voidclearscrean();

	}


}
