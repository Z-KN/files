#include "stdio.h"
int main(){
// 	asm volatile(
// "li t0, 0x400000000;"
// "li t2, 0x44332211;"
// "sw t2, 0(t0);"
// "lw t1, 0(t0);"
// "sw t1, 4(t0);"
//     );

volatile unsigned int *ptr;
ptr=(unsigned int *)0x400000000;
*ptr=0x44332211;
// iowrite32(0x44332211, ptr);
printf("OK!\n");
}