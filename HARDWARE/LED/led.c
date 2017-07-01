#include <stm32f10x_lib.h>	   
#include "led.h"
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

//初始化PA8和PD2为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
	RCC->APB2ENR|=1<<3;    //使能PORTB时钟	   	 
		
	GPIOB->CRL&=0X0FFFFFFF;
	GPIOB->CRL|=0X30000000;//PB7 推挽输出电源指示   	 
	GPIOB->CRH&=0XFF00FF00; 
	GPIOB->CRH|=0X00330033;//PB8 9 12 13 推挽输出 
	GPIOB->ODR|=1<<7;      //PB7 上拉  	 
    GPIOB->ODR|=1<<8;      //PB8 上拉	运行指示
	GPIOB->ODR|=1<<9;      //PB9 上拉	报警指示									  
	GPIOB->ODR&=~(1<<12);      //PB12 下拉 风扇指示
    GPIOB->ODR&=~(1<<13);      //PB13 下拉 门灯指示
}







