#ifndef __KEY_H
#define __KEY_H	 
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


#define KEYV PBin(10)   //PB10��ѹ���
#define KEYM PBin(5)   //PB5�ֶ�����
#define KEYA PBin(6)   //PB6�Զ�����
#define KEYV_A PAin(4)   //PA4��ѹ���
	 
void KEY_Init(void);//IO��ʼ��
					    
#endif
