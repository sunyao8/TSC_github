#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
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

//LED�˿ڶ���
#define LEDP PBout(7) // PB7��Դָʾ
#define LEDR PBout(8) // PB8����ָʾ
#define LEDA PBout(9) // PB9����ָʾ
#define LEDF PBout(12)// PB12����ָʾ
#define LEDD PBout(13)// PB13�ŵ�ָʾ	

void LED_Init(void);//��ʼ��		 				    
#endif


















