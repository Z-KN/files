// This is for IMCsim test

#include "stdio.h"

void LoadInputs(int addr_mem){
    int addr_array = 0X0;  // start from the first line
    while(addr_array < 0X1){  // maximum for the addr
    printf("LOAD INPUT 0X%08X 0X%04X\n", addr_mem+0X200*addr_array, addr_array);
    addr_array++;
    }
}

void LoadWeights(int addr_mem){
    int addr_array = 0X0;  // start from the first line
    while(addr_array < 0X100){  // maximum for the addr
    printf("LOAD WEIGHT 0X%08X 0X%04X\n", addr_mem+0X80*addr_array, addr_array);
    addr_array++;
    }  
}

void StoreOutputs(int addr_mem){
    printf("Storing outputs succeeded at 0X%08X!\n", addr_mem);
}

int main(){
    int addr_inputs=0X00000F00;
    int addr_weights=0X0000F000;
    int addr_outputs=0X000000F0;
	LoadInputs(addr_inputs);
    LoadWeights(addr_weights);
    StoreOutputs(addr_outputs);
}
