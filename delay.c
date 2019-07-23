/****************************************************************************
��ʱʱ����1us��1ms��1s���ö�ʱ��1�����ò����жϣ����õȴ��ķ�ʽ
ϵͳʱ����32M����ʱ��ʱ��Ϊ32M
�ö�ʱ��1��ģģʽ����

****************************************************************************/

#include"ioCC2530.h"
#include"variable.h"
#include"uart.h"

void Delay_us(unsigned int k)
{
  T1CC0L = 0x06;
  T1CC0H = 0x00;
  T1CTL = 0x02;//ģģʽ ����Ƶ
  while(k)
  {
    while(!(T1CNTL >= 0x04));
    k--;
  }
  T1CTL = 0x00;//�رն�ʱ��
}

void Delay_ms(unsigned int k)
{
  T1CC0L = 0xe8;
  T1CC0H = 0x03;
  T1CTL = 0x0a;//ģģʽ 32��Ƶ
  while(k)
  {
    while(!((T1CNTL >= 0xe8)&&(T1CNTH >= 0x03)));
    k--;
  }
  T1CTL = 0x00;//�رն�ʱ��
}


void Delay_s(unsigned int k)
{
  while(k)
  {
    Delay_ms(1000);
    k--;
  }
}



