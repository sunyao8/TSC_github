#include "timer.h"
#include "adc.h"
#include "led.h"
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
	  

//定时器4中断服务程序
volatile	u32 adctemp=0x85;
extern u8 C_flag,A_flag;
extern u32 C_count,A_count;
//extern u8 mutex;	 	 
void TIM4_IRQHandler(void)
{ 		    		  			    
	if(TIM4->SR&0X0001)//溢出中断
	{
	  if(C_flag==1)C_count++;
			if(A_flag==1)A_count++;	  
					    				   				     	    	
	}				   
	TIM4->SR&=~(1<<0);//清除中断标志位 	    
}
//通用定时器中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void Timer4_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<2;//TIM4时钟使能    
 	TIM4->ARR=arr;  //设定计数器自动重装值//刚好1ms    
	TIM4->PSC=psc;  //预分频器7200,得到10Khz的计数时钟
	//这两个东东要同时设置才可以使用中断
	TIM4->DIER|=1<<0;   //允许更新中断				
		TIM4->CR1|=0x01;    //使能定时器4
		  							    
	
  	MY_NVIC_Init(3,3,TIM4_IRQChannel,2);//抢占2，子优先级3，组2									 
}
	 

//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void PWM_Init(u16 arr,u16 psc)
{	
					 
	//此部分需手动修改IO口设置
	RCC->APB1ENR|=1<<1;       //TIM3时钟使能    

	
	GPIOA->CRL&=0XF0FFFFFF;//PA6输出
	GPIOA->CRL|=0X0B000000;//复用功能输出 	  
	GPIOA->ODR|=1<<6;//PA6上拉 
	 	
	GPIOA->CRL&=0X0FFFFFFF;//PA7输出
	GPIOA->CRL|=0XB0000000;//复用功能输出 	  
	GPIOA->ODR|=1<<7;//PA7上拉
	
	RCC->APB2ENR|=1<<3;       //PB时钟使能
	GPIOB->CRL&=0XFFFFFFF0;//PB0输出
	GPIOB->CRL|=0X0000000B;//复用功能输出 	  
	GPIOB->ODR|=1;//PB0上拉 
	 	
	GPIOB->CRL&=0XFFFFFF0F;//PB1输出
	GPIOB->CRL|=0X000000B0;//复用功能输出 	  
	GPIOB->ODR|=1<<1;//PB1上拉	

	TIM3->ARR=arr;//设定计数器自动重装值 
	TIM3->PSC=psc;//预分频器不分频

	TIM3->CCMR1|=7<<4;  //CH1 PWM2模式		 
	TIM3->CCMR1|=1<<3; //CH1预装载使能	   

	TIM3->CCER|=1;   //OC1 输出使能

	TIM3->CCMR1|=7<<12;  //CH2 PWM2模式		 
	TIM3->CCMR1|=1<<11; //CH2预装载使能	   

	TIM3->CCER|=1<<4;   //OC2 输出使能
	
	TIM3->CCMR2|=7<<4;  //CH3 PWM2模式		 
	TIM3->CCMR2|=1<<3; //CH3预装载使能	   

	TIM3->CCER|=1<<8;   //OC3 输出使能

	TIM3->CCMR2|=7<<12;  //CH4 PWM2模式		 
	TIM3->CCMR2|=1<<11; //CH4预装载使能	   

	TIM3->CCER|=1<<12;   //OC4 输出使能	
	
	

	TIM3->CR1=0x8000;   //ARPE使能 
	TIM3->CR1|=0x01;    //使能定时器3 										  
}  	 













