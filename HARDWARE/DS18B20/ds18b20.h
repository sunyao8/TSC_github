#ifndef __DS18B20_H
#define __DS18B20_H 
#include "sys.h"   
//////////////////////////////////////////////////////////////////////////////////	 
//Useless power compensation controller
//Useless power compensation controller ds18b20
//ds18b20 code	   

//修改日期:2015/5/18
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 栋达电子 2012-2022
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////


//IO方向设置
#define DS18B20_IO_IN()  {GPIOA->CRL&=0XFFFFF0FF;GPIOA->CRL|=8<<8;}
#define DS18B20_IO_OUT() {GPIOA->CRL&=0XFFFFF0FF;GPIOA->CRL|=3<<8;}
////IO操作函数											   
#define	DS18B20_DQ_OUT PAout(2) //数据端口	PA2 
#define	DS18B20_DQ_IN  PAin(2)  //数据端口	PA2 
   	
u8 DS18B20_Init(void);			//初始化DS18B20
short DS18B20_Get_Temp(void);	//获取温度
void DS18B20_Start(void);		//开始温度转换
void DS18B20_Write_Byte(u8 dat);//写入一个字节
u8 DS18B20_Read_Byte(void);		//读出一个字节
u8 DS18B20_Read_Bit(void);		//读出一个位
u8 DS18B20_Check(void);			//检测是否存在DS18B20
void DS18B20_Rst(void);			//复位DS18B20    
#endif















