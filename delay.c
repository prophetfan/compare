/****************************************************************************
延时时间有1us、1ms和1s。用定时器1，不用产生中断，采用等待的方式
系统时钟事32M，定时器时钟为32M
用定时器1，模模式运行

****************************************************************************/

#include"ioCC2530.h"
#include"variable.h"
#include"uart.h"

void Delay_us(unsigned int k)
{
  T1CC0L = 0x06;
  T1CC0H = 0x00;
  T1CTL = 0x02;//模模式 不分频
  while(k)
  {
    while(!(T1CNTL >= 0x04));
    k--;
  }
  T1CTL = 0x00;//关闭定时器
}

void Delay_ms(unsigned int k)
{
  T1CC0L = 0xe8;
  T1CC0H = 0x03;
  T1CTL = 0x0a;//模模式 32分频
  while(k)
  {
    while(!((T1CNTL >= 0xe8)&&(T1CNTH >= 0x03)));
    k--;
  }
  T1CTL = 0x00;//关闭定时器
}


void Delay_s(unsigned int k)
{
  while(k)
  {
    Delay_ms(1000);
    k--;
  }
}



