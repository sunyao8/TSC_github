#ifndef __ADC_H
#define __ADC_H	
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


#define ADC_CH0  0 //ͨ��0
#define ADC_CH1  1 //ͨ��1
#define ADC_CH2  2 //ͨ��2
#define ADC_CH3  3 //ͨ��3
#define ADC_CH4  4 //ͨ��4
	   

void Adc_Init(void);
u16  Get_Adc(u8 ch);  
 
#endif 















