#include <stm32f10x_lib.h>
#include "adc.h"
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
	 
 
		   
//初始化ADC
//这里我们仅以规则通道为例
//我们默认将开启通道0~3																	   
void  Adc_Init(void)
{   
 
	//先初始化IO口
 	RCC->APB2ENR|=1<<2;    //使能PORTA口时钟 
	GPIOA->CRL&=0XFFF00F00;//PA0 1  3 4 anolog输入
	//通道10/11设置			 
	RCC->APB2ENR|=1<<10;    //ADC1时钟使能	  
	RCC->APB2RSTR|=1<<10;   //ADC1复位
	RCC->APB2RSTR&=~(1<<10);//复位结束	    
	RCC->CFGR&=~(3<<14);   //分频因子清零	
	//SYSCLK/DIV2=12M ADC时钟设置为12M,ADC最大时钟不能超过14M!
	//否则将导致ADC准确度下降! 
	RCC->CFGR|=2<<14;      	 

	ADC2->CR1&=0XF0FFFF;   //工作模式清零
	ADC2->CR1|=0<<16;      //独立工作模式  
	ADC2->CR1&=~(1<<8);    //非扫描模式	  
	ADC2->CR2&=~(1<<1);    //单次转换模式
	ADC2->CR2&=~(7<<17);	   
	ADC2->CR2|=7<<17;	   //软件控制转换  
	ADC2->CR2|=1<<20;      //使用用外部触发(SWSTART)!!!	必须使用一个事件来触发
	ADC2->CR2&=~(1<<11);   //右对齐	 
	ADC2->SQR1&=~(0XF<<20);
	ADC2->SQR1&=0<<20;     //1个转换在规则序列中 也就是只转换规则序列1 			   
	//设置通道0~3的采样时间
	ADC2->SMPR2&=0XFFFF0000;//通道0,1,2,3采样时间清空
	ADC2->SMPR2|=6<<12;      //通道4  239.5周期,提高采样时间可以提高精确度	  
	ADC2->SMPR2|=6<<9;      //通道3  239.5周期,提高采样时间可以提高精确度	 
//	ADC2->SMPR2|=6<<6;      //通道2  239.5周期,提高采样时间可以提高精确度	 
	ADC2->SMPR2|=6<<3;      //通道1  239.5周期,提高采样时间可以提高精确度	 
	ADC2->SMPR2|=6<<0;      //通道0  239.5周期,提高采样时间可以提高精确度	 

	ADC2->CR2|=1<<0;	    //开启AD转换器	 
	ADC2->CR2|=1<<3;        //使能复位校准  
	while(ADC2->CR2&1<<3);  //等待校准结束 			 
    //该位由软件设置并由硬件清除。在校准寄存器被初始化后该位将被清除。 		 
	ADC2->CR2|=1<<2;        //开启AD校准	   
	while(ADC2->CR2&1<<2);  //等待校准结束 该位由软件设置以开始校准，并在校准结束时由硬件清除 

}				  
//获得ADC值
//ch:通道值 0~4
u16 Get_Adc(u8 ch)   
{
	//设置转换序列	  		 
	ADC2->SQR3&=0XFFFFFFE0;//规则序列1 通道ch
	ADC2->SQR3|=ch;		  			    
	ADC2->CR2|=1<<22;       //启动规则转换通道 
	while(!(ADC2->SR&1<<1));//等待转换结束	 	   
	return ADC2->DR;		//返回adc值	
}



























