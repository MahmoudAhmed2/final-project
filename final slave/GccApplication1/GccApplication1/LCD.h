/*
 * LCD.h
 *
 * Created: 11/12/2020 8:41:20 PM
 *  Author: Mahmoud
 */ 


#ifndef LCD_H_
#define LCD_H_
void SEND_FALLING_EDGE(void);
void SEND_CMD(uint8 cmd);
void LCD_INITIALIZE(void);
void MOVING_CURSOR(uint8 row ,uint8 col);
void LCD_PRINT(char *data);
void SEND_DATA(uint8 cmd);





#endif /* LCD_H_ */