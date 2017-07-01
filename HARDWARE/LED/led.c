#include <stm32f10x_lib.h>	   
#include "led.h"
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

//��ʼ��PA8��PD2Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
	RCC->APB2ENR|=1<<3;    //ʹ��PORTBʱ��	   	 
		
	GPIOB->CRL&=0X0FFFFFFF;
	GPIOB->CRL|=0X30000000;//PB7 ���������Դָʾ   	 
	GPIOB->CRH&=0XFF00FF00; 
	GPIOB->CRH|=0X00330033;//PB8 9 12 13 ������� 
	GPIOB->ODR|=1<<7;      //PB7 ����  	 
    GPIOB->ODR|=1<<8;      //PB8 ����	����ָʾ
	GPIOB->ODR|=1<<9;      //PB9 ����	����ָʾ									  
	GPIOB->ODR&=~(1<<12);      //PB12 ���� ����ָʾ
    GPIOB->ODR&=~(1<<13);      //PB13 ���� �ŵ�ָʾ
}







