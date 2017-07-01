#include "timer.h"
#include "adc.h"
#include "led.h"
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
	  

//��ʱ��4�жϷ������
volatile	u32 adctemp=0x85;
extern u8 C_flag,A_flag;
extern u32 C_count,A_count;
//extern u8 mutex;	 	 
void TIM4_IRQHandler(void)
{ 		    		  			    
	if(TIM4->SR&0X0001)//����ж�
	{
	  if(C_flag==1)C_count++;
			if(A_flag==1)A_count++;	  
					    				   				     	    	
	}				   
	TIM4->SR&=~(1<<0);//����жϱ�־λ 	    
}
//ͨ�ö�ʱ���жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void Timer4_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<2;//TIM4ʱ��ʹ��    
 	TIM4->ARR=arr;  //�趨�������Զ���װֵ//�պ�1ms    
	TIM4->PSC=psc;  //Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��
	//����������Ҫͬʱ���òſ���ʹ���ж�
	TIM4->DIER|=1<<0;   //��������ж�				
		TIM4->CR1|=0x01;    //ʹ�ܶ�ʱ��4
		  							    
	
  	MY_NVIC_Init(3,3,TIM4_IRQChannel,2);//��ռ2�������ȼ�3����2									 
}
	 

//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void PWM_Init(u16 arr,u16 psc)
{	
					 
	//�˲������ֶ��޸�IO������
	RCC->APB1ENR|=1<<1;       //TIM3ʱ��ʹ��    

	
	GPIOA->CRL&=0XF0FFFFFF;//PA6���
	GPIOA->CRL|=0X0B000000;//���ù������ 	  
	GPIOA->ODR|=1<<6;//PA6���� 
	 	
	GPIOA->CRL&=0X0FFFFFFF;//PA7���
	GPIOA->CRL|=0XB0000000;//���ù������ 	  
	GPIOA->ODR|=1<<7;//PA7����
	
	RCC->APB2ENR|=1<<3;       //PBʱ��ʹ��
	GPIOB->CRL&=0XFFFFFFF0;//PB0���
	GPIOB->CRL|=0X0000000B;//���ù������ 	  
	GPIOB->ODR|=1;//PB0���� 
	 	
	GPIOB->CRL&=0XFFFFFF0F;//PB1���
	GPIOB->CRL|=0X000000B0;//���ù������ 	  
	GPIOB->ODR|=1<<1;//PB1����	

	TIM3->ARR=arr;//�趨�������Զ���װֵ 
	TIM3->PSC=psc;//Ԥ��Ƶ������Ƶ

	TIM3->CCMR1|=7<<4;  //CH1 PWM2ģʽ		 
	TIM3->CCMR1|=1<<3; //CH1Ԥװ��ʹ��	   

	TIM3->CCER|=1;   //OC1 ���ʹ��

	TIM3->CCMR1|=7<<12;  //CH2 PWM2ģʽ		 
	TIM3->CCMR1|=1<<11; //CH2Ԥװ��ʹ��	   

	TIM3->CCER|=1<<4;   //OC2 ���ʹ��
	
	TIM3->CCMR2|=7<<4;  //CH3 PWM2ģʽ		 
	TIM3->CCMR2|=1<<3; //CH3Ԥװ��ʹ��	   

	TIM3->CCER|=1<<8;   //OC3 ���ʹ��

	TIM3->CCMR2|=7<<12;  //CH4 PWM2ģʽ		 
	TIM3->CCMR2|=1<<11; //CH4Ԥװ��ʹ��	   

	TIM3->CCER|=1<<12;   //OC4 ���ʹ��	
	
	

	TIM3->CR1=0x8000;   //ARPEʹ�� 
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3 										  
}  	 













