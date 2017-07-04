#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "timer.h"
//////////////////////////////////////////////////////////////////////////////////	 
//Useless power compensation controller
//Useless power compensation controller exti
//exti code	   

//修改日期:2012/4/29
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 栋达电子 2012-2022
//All rights reserved											  
////////////////////////////////////////////////////////////////////////////////// 	  
 

//外部中断10服务程序
 //extern u8 mutex;	 

 extern u8 flag_xu;
volatile u8 key_xb=0;
 volatile u8 flag=0;
 extern u8 mutex;
void EXTI15_10_IRQHandler(void)
{	

if(flag_xu==0)
{
	if(KEYV==1)
	{
	delay_us(1000);	
	 TIM3->CCR3=490;
	 TIM3->CCR4=490; 
	}
	  EXTI->PR=1<<10;     //清除LINE10上的中断标志位  
//     mutex=0;
}
if(flag_xu==1)
{
{	
	delay_us(1000);		
	if(KEYV==1)
	{
	 TIM3->CCR3=490;
	 TIM3->CCR4=490;
	}
   
	EXTI->PR=1<<10;     //清除LINE10上的中断标志位  
    key_xb=1; 
   mutex=0;
}
}

}
//外部中断初始化程序
//初始化PB10为中断输入.
void EXTIX_Init(void)
{
	RCC->APB2ENR|=1<<3;     //使能PORTB时钟
    
	GPIOB->CRH&=0XFFFFF0FF;//PB10设置成输入	  
	GPIOB->CRH|=0X00000800; 				   
	GPIOB->ODR|=1<<10;	   //PB10上拉
	

	Ex_NVIC_Config(GPIO_B,10,RTIR); //上升沿触发


	MY_NVIC_Init(2,1,EXTI15_10_IRQChannel,2);//抢占2，子优先级1，组2	   
}












