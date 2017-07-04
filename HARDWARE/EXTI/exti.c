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

//�޸�����:2012/4/29
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������� 2012-2022
//All rights reserved											  
////////////////////////////////////////////////////////////////////////////////// 	  
 

//�ⲿ�ж�10�������
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
	  EXTI->PR=1<<10;     //���LINE10�ϵ��жϱ�־λ  
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
   
	EXTI->PR=1<<10;     //���LINE10�ϵ��жϱ�־λ  
    key_xb=1; 
   mutex=0;
}
}

}
//�ⲿ�жϳ�ʼ������
//��ʼ��PB10Ϊ�ж�����.
void EXTIX_Init(void)
{
	RCC->APB2ENR|=1<<3;     //ʹ��PORTBʱ��
    
	GPIOB->CRH&=0XFFFFF0FF;//PB10���ó�����	  
	GPIOB->CRH|=0X00000800; 				   
	GPIOB->ODR|=1<<10;	   //PB10����
	

	Ex_NVIC_Config(GPIO_B,10,RTIR); //�����ش���


	MY_NVIC_Init(2,1,EXTI15_10_IRQChannel,2);//��ռ2�������ȼ�1����2	   
}












