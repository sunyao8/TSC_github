#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//Useless power compensation controller
//Useless power compensation controller pwm
//pwm code	   

//修改日期:2012/4/29
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 栋达电子 2012-2022
//All rights reserved											  
////////////////////////////////////////////////////////////////////////////////// 

//LED端口定义
#define LEDP PBout(7) // PB7电源指示
#define LEDR PBout(8) // PB8运行指示
#define LEDA PBout(9) // PB9报警指示
#define LEDF PBout(12)// PB12风扇指示
#define LEDD PBout(13)// PB13门灯指示	

void LED_Init(void);//初始化		 				    
#endif


















