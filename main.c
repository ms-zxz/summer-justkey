#include "led.h"
#include "key.h"
#include "delay.h"
#include "sys.h"


 int main(void)
 {
 	vu8 key=0;	
	delay_init();	    	 //��ʱ������ʼ��	  
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();              //��ʼ���밴�����ӵ�Ӳ���ӿ�
	LED0=0;					 //�ȵ���LED0
	while(1)
	{
 		key=KEY_Scan(0);     //�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:	//LED1��ת	 
					LED1=!LED1;
					break;
				case KEY0_PRES:	//LED0,LED1ͬʱ��ת 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}
		else delay_ms(10); 
	}	 
}

