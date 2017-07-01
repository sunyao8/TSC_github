#include <stm32f10x_lib.h>
#include "key.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//Useless power compensation controller
//Useless power compensation controller pwm
//pwm code	   

//�޸�����:2012/4/29
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������� 2012-2022
//All rights reserved											  
////////////////////////////////////////////////////////////////////////////////// 
void KEY_Init(void)
{
	RCC->APB2ENR|=1<<3;     //ʹ��PORTBʱ��
	RCC->APB2ENR|=1<<2;     //ʹ��PORTAʱ��

	GPIOB->CRL&=0XF00FFFFF;//PB5���ó������ֶ�����	  
	GPIOB->CRL|=0X08800000;//PB6���ó������Զ����� 

	GPIOB->CRH&=0XFFFFF0FF;//PB10���ó������ѹ���	  
	GPIOB->CRH|=0X00000800;   


	GPIOA->CRL&=0XFFF0FFFF;//PA4���ó������ѹ���	  
	GPIOA->CRL|=0X00080000; 	
	 				   
	GPIOB->ODR|=1<<10;	   //PB10����
	GPIOB->ODR|=1<<6;	   //PB6����
	GPIOB->ODR|=1<<5;	   //PB5����
		GPIOA->ODR|=1<<4;	   //PA4����

} 



















