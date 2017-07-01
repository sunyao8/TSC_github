#ifndef __ADC_H
#define __ADC_H	
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


#define ADC_CH0  0 //通道0
#define ADC_CH1  1 //通道1
#define ADC_CH2  2 //通道2
#define ADC_CH3  3 //通道3
#define ADC_CH4  4 //通道4
	   

void Adc_Init(void);
u16  Get_Adc(u8 ch);  
 
#endif 















