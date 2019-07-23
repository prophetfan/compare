#include"iocc2530.h"
#include"Oled.h"
#include"stdio.h"
#include"string.h"

#include "ds18b20.h"
#include "uart.h"

void Initial() //ϵͳ��ʼ��
{
  CLKCONCMD = 0x80;      //ѡ��32M����
  while(CLKCONSTA&0x40); //�ȴ������ȶ�
  UartInitial();         //���ڳ�ʼ��
  P0SEL &= 0xdf;         //DS18B20��io�ڳ�ʼ��
}

void main()
{
  unsigned int s1=1,s2=2,s3=3;//��ʪ�ȵ���ֵ�����뼴��
  char data[5]="temp="; //������ʾ��
  unsigned char str1[50]="";
  unsigned char str2[50]="";
  unsigned char str3[50]="";
  
  OLED_Init();
  Initial();
  
  while(1)
  {  
      Temp_test();   //�¶ȼ��    
      //OLED_Init();
      /*******�¶���Ϣ��ӡ ***********/
      UartTX_Send_String(data,5);
      UartSend(temp/10+48);
      UartSend(temp%10+48); 
      UartSend('\n');
      
      sprintf(str1, "temp:%d",temp);
      sprintf(str2, "hum:%d",s2);
      sprintf(str3, "Wtemp:%d",s3);
    
      OLED_P8x16Str(10,1,str1); //�����ʪ�ȵ���Ļ����10,1������Ļ����
      OLED_P8x16Str(10,3,str2); 
      OLED_P8x16Str(10,5,str3); 
      //OLED_P16x16Ch(40,4,0);
      //OLED_P16x16Ch(60,4,1);
      //delay(2000);
      //OLED_CLS();
      /*Draw_BMP(0,0,128,8,BMP);
      delay(4000);
      OLED_CLS();*/
      Delay_ms(3000); //��ʱ����ʹ�ö�ʱ����ʽ
  }
}