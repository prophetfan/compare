#ifndef __UART_H__
#define __UART_H__

extern void UartInitial();
extern void UartSend(unsigned char infor);
extern void UartTX_Send_String(char *Data,int len);

#endif