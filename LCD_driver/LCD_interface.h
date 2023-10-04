
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


void LCD_voidinit();
void LCD_voidsendcommand(u8 cpy_u8command);
void LCD_voidsenddata(u8 cpy_u8data);
void LCD_gotoxy(u8 cpy_u8x,u8 cpy_u8y);
void LCD_voidsendstring(u8* str);
void LCD_voidsendnumber(u8* str);
void LCD_voidpattern(u8 cpy_u8blocknum,u8* cpy_u8patternarr);
void  LCD_voidnameinsinusoidal();
void LCD_voidclearscrean();

#endif
