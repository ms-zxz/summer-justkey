#include "led.h"
#include "key.h"
#include "delay.h"
#include "sys.h"


 int main(void)
 {
 	vu8 key=0;	
	delay_init();	    	 //延时函数初始化	  
 	LED_Init();			     //LED端口初始化
	KEY_Init();              //初始化与按键连接的硬件接口
	LED0=0;					 //先点亮LED0
	while(1)
	{
 		key=KEY_Scan(0);     //得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:	//LED1翻转	 
					LED1=!LED1;
					break;
				case KEY0_PRES:	//LED0,LED1同时翻转 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}
		else delay_ms(10); 
	}	 
}

