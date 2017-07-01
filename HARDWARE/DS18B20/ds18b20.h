#ifndef __DS18B20_H
#define __DS18B20_H 
#include "sys.h"   
//////////////////////////////////////////////////////////////////////////////////	 
//Useless power compensation controller
//Useless power compensation controller ds18b20
//ds18b20 code	   

//�޸�����:2015/5/18
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������� 2012-2022
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////


//IO��������
#define DS18B20_IO_IN()  {GPIOA->CRL&=0XFFFFF0FF;GPIOA->CRL|=8<<8;}
#define DS18B20_IO_OUT() {GPIOA->CRL&=0XFFFFF0FF;GPIOA->CRL|=3<<8;}
////IO��������											   
#define	DS18B20_DQ_OUT PAout(2) //���ݶ˿�	PA2 
#define	DS18B20_DQ_IN  PAin(2)  //���ݶ˿�	PA2 
   	
u8 DS18B20_Init(void);			//��ʼ��DS18B20
short DS18B20_Get_Temp(void);	//��ȡ�¶�
void DS18B20_Start(void);		//��ʼ�¶�ת��
void DS18B20_Write_Byte(u8 dat);//д��һ���ֽ�
u8 DS18B20_Read_Byte(void);		//����һ���ֽ�
u8 DS18B20_Read_Bit(void);		//����һ��λ
u8 DS18B20_Check(void);			//����Ƿ����DS18B20
void DS18B20_Rst(void);			//��λDS18B20    
#endif















