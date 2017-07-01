#ifndef __KEY_H
#define __KEY_H	 
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


#define KEYV PBin(10)   //PB10电压检测
#define KEYM PBin(5)   //PB5手动控制
#define KEYA PBin(6)   //PB6自动控制
#define KEYV_A PAin(4)   //PA4电压检测
	 
void KEY_Init(void);//IO初始化
					    
#endif
