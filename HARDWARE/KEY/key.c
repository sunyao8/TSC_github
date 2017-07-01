#include <stm32f10x_lib.h>
#include "key.h"
#include "delay.h"
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
void KEY_Init(void)
{
	RCC->APB2ENR|=1<<3;     //使能PORTB时钟
	RCC->APB2ENR|=1<<2;     //使能PORTA时钟

	GPIOB->CRL&=0XF00FFFFF;//PB5设置成输入手动控制	  
	GPIOB->CRL|=0X08800000;//PB6设置成输入自动控制 

	GPIOB->CRH&=0XFFFFF0FF;//PB10设置成输入电压检测	  
	GPIOB->CRH|=0X00000800;   


	GPIOA->CRL&=0XFFF0FFFF;//PA4设置成输入电压检查	  
	GPIOA->CRL|=0X00080000; 	
	 				   
	GPIOB->ODR|=1<<10;	   //PB10上拉
	GPIOB->ODR|=1<<6;	   //PB6上拉
	GPIOB->ODR|=1<<5;	   //PB5上拉
		GPIOA->ODR|=1<<4;	   //PA4上拉

} 



















