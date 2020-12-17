/*
 * STD.h
 *
 * Created: 11/10/2020 8:31:06 PM
 *  Author: Mahmoud
 */ 


#ifndef STD_H_
#define STD_H_

typedef unsigned char uint8;
typedef signed char sint8;
/*short --->16 bit*/
/*long ---->32 bit*/
/*double ---->64 bit*/

/////////////////////*std macros*/////////////////////////
#define REG_SIZE 8
#define SIT_BIT(port,pin) (port|=(1<<pin))
#define CLR_BIT(port,pin) (port&=~(1<<pin)) 
#define READ_BIT(port,pin) ((port&(1<<pin))>>pin)
#define TOGGLE_BIT(port,pin) (port^=(1<<pin))   /* x   y  q
                                                  0   0  0
                                                  0   1  1  to change  from 0 to 1
												  1   0  1
												  1   1  0 to change from 1 to 0
												  */
#define ROR(reg,num) ((reg>>num)|(reg<<(REG_SIZE-num))) /*??? ???? ???????? ?? ???*/
#define ROL(reg,num) ((reg<<num)|(reg>>(REG_SIZE-num)))



#endif /* STD_H_ */