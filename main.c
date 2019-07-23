#include"iocc2530.h"
#include"Oled.h"
#include"stdio.h"
#include"string.h"

#include "ds18b20.h"
#include "uart.h"

void Initial() //系统初始化
{
  CLKCONCMD = 0x80;      //选择32M振荡器
  while(CLKCONSTA&0x40); //等待晶振稳定
  UartInitial();         //串口初始化
  P0SEL &= 0xdf;         //DS18B20的io口初始化
}

void main()
{
  unsigned int s1=1,s2=2,s3=3;//温湿度的数值，传入即可
  char data[5]="temp="; //串口提示符
  unsigned char str1[50]="";
  unsigned char str2[50]="";
  unsigned char str3[50]="";
  
  OLED_Init();
  Initial();
  
  while(1)
  {  
      Temp_test();   //温度检测    
      //OLED_Init();
      /*******温度信息打印 ***********/
      UartTX_Send_String(data,5);
      UartSend(temp/10+48);
      UartSend(temp%10+48); 
      UartSend('\n');
      
      sprintf(str1, "temp:%d",temp);
      sprintf(str2, "hum:%d",s2);
      sprintf(str3, "Wtemp:%d",s3);
    
      OLED_P8x16Str(10,1,str1); //输出温湿度到屏幕，（10,1）是屏幕坐标
      OLED_P8x16Str(10,3,str2); 
      OLED_P8x16Str(10,5,str3); 
      //OLED_P16x16Ch(40,4,0);
      //OLED_P16x16Ch(60,4,1);
      //delay(2000);
      //OLED_CLS();
      /*Draw_BMP(0,0,128,8,BMP);
      delay(4000);
      OLED_CLS();*/
      Delay_ms(3000); //延时函数使用定时器方式
  }
}