#ifndef _UART_H_
#define _UART_H_

#define UART0DR *((volatile unsigned int* const)((unsigned int*)0x101f1000))

void Uart_Send_String (unsigned char *P_tx_string);

#endif
