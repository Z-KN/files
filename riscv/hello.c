#include <stdio.h>
#include <string.h>
// #define UART_BASE 0x3ffffffb24
#define UART_BASE 0x4000000000
int main(void)
{
    // unsigned int c=0xff00;
 	// volatile unsigned int *ptr = (volatile unsigned int *) (UART_BASE+0);
    // int value =33;

// *test = 0x3;
    // memcpy(&value+1, &value,4);
    // printf("value+4::%d\n",*(&value+3));  
    // memcpy((void*)(UART_BASE), &value, 4);
    // printf("c addr::%p\n",&c);  
    // printf("value addr=%p\n",&value);
    // ptr=;
    // *ptr=0x1122;
    // printf("ptr::%p\n, v=%x\n",ptr, *ptr);  
	printf("Hello, World!\n");
    return 0;
}
