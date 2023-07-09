#include "uart.h"
unsigned char string_buffer[100]="learn-in-depth:<Mohammed Ibrahim>";

void main(void)
{
	Uart_Send_String(string_buffer);
}