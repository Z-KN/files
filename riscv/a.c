#include "stdio.h"
int main(){
	int *s=0X10000000;
	for (int i=0;i<64;i++){
		*(s+i)=i;

	}
	return 0;
}

