#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

void KEY_Init(void)                                          //IO��ʼ��
	{ 
		GPIO_InitTypeDef GPIO_InitStructure;
	 
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);  //PORTEʱ��

		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3|GPIO_Pin_4; //KEY0-KEY1
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //���ó���������
		GPIO_Init(GPIOE, &GPIO_InitStructure);                //��ʼ��GPIOE3,4
	}
															 //mode:0,��֧��������;1,֧��������;
															 //0,û���κΰ�������,1,KEY0����,2,KEY1����
u8 KEY_Scan(u8 mode)
	{	 
		static u8 key_up=1;                                  //�������ɿ���־
		if(mode)key_up=1;                                    //֧������		  
		if(key_up&&(KEY0==0||KEY1==0))
		{
			delay_ms(10);                                    //ȥ���� 
			key_up=0;
			if(KEY0==0)return KEY0_PRES;
			else if(KEY1==0)return KEY1_PRES;
		}else if(KEY0==1&&KEY1==1)key_up=1; 	    
		return 0;                                            // �ް�������
	}