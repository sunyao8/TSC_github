#include <stm32f10x_lib.h>
#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h"
#include "exti.h"	 	 
#include "timer.h"
#include "adc.h"
#include "ds18b20.h"

extern volatile	u32 adctemp; 
u8 distin_A_C(void);
u8 C_flag=0,A_flag=0;
u32 C_count=0,A_count=0;
//u8 mutex=0; 
int main(void)
{	
	u16 adcx=0,adcxm=0,flag=0;
    u8 flagtemp=1; 
    u8 flag_xu=3;
    u8 t=0;
	short temperature;

 	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化
	uart_init(72,9600);  //串口初始化 
	KEY_Init();
	LED_Init();
	PWM_Init(5400,0);
	Timer4_Init(10,7199);//2s
	EXTIX_Init();		 		//外部中断初始化	
	LEDP=0;	 //电源指示亮
	LEDF=0;
	while(KEYV_A==1&&KEYV==1)break;
	delay_ms(3000);
 flag_xu=distin_A_C();// 0为正相序

while(DS18B20_Init())
{

}

	delay_ms(1000);
if(flag_xu==1)//0 为正相序，1为反相序
 	{
   	delay_ms(1000);

	Adc_Init();

	while(1)
	{	

	if(((KEYM==0)||(KEYA==0))&&(flagtemp==1))


		{													
	
			while(flag==0)
			{		
					u16 i;
						adcxm=0;
					for(i=0;i<295;i++)
					{
					adcx=Get_Adc(ADC_CH4);				
					delay_us(50);				
						if(adcx>0X7A)	   //9A
						{
						 if(adcx>adcxm )
						  adcxm=adcx ;
						}
					}											
			if(adcxm>0X7A);	  //9A
			   {
				   if(adcxm>450)						  //模拟信号数值为1时
					 {
						u16 i;
//						 mutex=1;
					 //	EXTIX_Init();				 //	正相序系统数字量先投，模拟量后投
					 	EXTI->IMR|=1<<10;//  开启line BITx上的中断
						delay_ms(20);

						for(i=0;i<295;i++)
							{	
								adcx=Get_Adc(ADC_CH4);								
								if(adcx>=adcxm*80/100) //  *9/10
								{
								 TIM3->CCR1=490;
								 TIM3->CCR2=490;
								 flag=1;
								 LEDR=0;
								 LEDD=1;
								break;						 
								}
							  delay_us(50);
							}
						}
					if(adcxm<=450)			  	 ////模拟信号数值为0时
					{
					    u16 i;
					//	EXTIX_Init();		 		//外部中断初始化，投入数值量
//							mutex=1;				
						EXTI->IMR|=1<<10;//  开启line BITx上的中断
							for(i=0;i<295;i++)
							{	
								adcx=Get_Adc(ADC_CH4);								
								if(adcx>=adcxm*80/100)	//  *9/10
								{
								 TIM3->CCR1=490;
								 TIM3->CCR2=490;
								 flag=1;
								 LEDR=0;
								 LEDD=1;
								 break;						 
								}
							  delay_us(50);
							}
					 }
				//	adcxm=0;
				}				
			}	
							
		}							

		else  if(flag==1)
		{

		  EXTI->PR=1<<10;     //清除LINE10上的中断标志位
	 	  EXTI->IMR&=~(1<<10);//  关闭line BITx上的中断 
		  flag=0;
		  adcxm=0;
		   LEDR=1;
		   LEDD=0;

		  TIM3->CCR1=0; 
	
		  TIM3->CCR2=0;
		  TIM3->CCR3=0;
		  TIM3->CCR4=0; 
//		  	mutex=0;
		}
 
//	  	  	 if(mutex==0)
//		{	 
//		   adctemp=0;
//		 for(t=0;t<10;t++)
//		 {
//		 adctemp+=Get_Adc(ADC_CH2);
//		 delay_ms(1);
//	   }
//		adctemp=adctemp/10;
//	   adctemp=adctemp*330/4096;
//	   } 	


//	if(adctemp<0x80)		//风机开 25	 5E-55
//	LEDF=1;
//	if(adctemp<0x4C)	  //报警开   44-73.3 	  67
//	{
//	LEDA=0;
//	flagtemp=0;
//	}
//	if(adctemp>0x56)	 //报警关 	50-69	 6a
//	{
//	LEDA=1;
//	flagtemp=1;
//	}
//	if(adctemp>0x93)	//风机关 15
//	LEDF=0;


		if(t%100==0)//每100ms读取一次
		{									  
			temperature=DS18B20_Get_Temp();	
			if(temperature>500)
			{
			 LEDF=1;
			
			}
			if(temperature>750)
			{
			LEDA=0;
			flagtemp=0;			
			}
			if(temperature<650)
			{
			LEDA=1;
			flagtemp=1;			
			}
		  if(temperature<400)
			{
			 LEDF=0;
			
			}


		}			   
	 	   delay_ms(1);
		  t++;
		if(t==200)
		{
			t=0;
		}

	  }	 

}
 }

u8 distin_A_C(void)
{
  

{	 
        
	 while(1)
	 	{
		 if(KEYV_A==1)A_flag=1;
		 if(KEYV==1)C_flag=1;
		 if(A_flag==1&&C_flag==1)break;
	 	}
	 	A_flag=0;
		C_flag=0;

	  
	  if(A_count>0)
	  	{  
       // A_count=A_count*4/10;
if(A_count<=5&&A_count>=1)//5 6
	{	  A_count=0;
               C_count=0;
		  return 1;
      }

if(A_count<=10&&A_count>=6)//7 8
{	  A_count=0;
               C_count=0;
		  return 0;
      }

	  	}

/*********************************/
if(C_count>0)
      	{
   //   	C_count=C_count*4/10;
if(C_count<=5&&C_count>=1)//7 8
{
A_count=0;
C_count=0;
return 0;
}

if(C_count<=10&&C_count>=6)//5 6
{
A_count=0;
C_count=0;
return 1;
}


	  }


return 2;

 }


}


