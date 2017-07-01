#include "wdg.h"
//////////////////////////////////////////////////////////////////////////////////	 
//Useless power compensation controller
//Useless power compensation controller WDG
//WDG code	   

//修改日期:2012/4/29
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 栋达电子 2012-2022
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

//初始化独立看门狗
//prer:分频数:0~7(只有低3位有效!)
//分频因子=4*2^prer.但最大值只能是256!
//rlr:重装载寄存器值:低11位有效.
//时间计算(大概):Tout=((4*2^prer)*rlr)/40 (ms).
void IWDG_Init(u8 prer,u16 rlr) 
{
	IWDG->KR=0X5555;//使能对IWDG->PR和IWDG->RLR的写		 										  
  	IWDG->PR=prer;  //设置分频系数   
  	IWDG->RLR=rlr;  //从加载寄存器 IWDG->RLR  
	IWDG->KR=0XAAAA;//reload											   
  	IWDG->KR=0XCCCC;//使能看门狗	
}
//喂独立看门狗
void IWDG_Feed(void)
{
	IWDG->KR=0XAAAA;//reload											   
}








