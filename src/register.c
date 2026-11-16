#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

uint32_t registers[8] = {[0]=0, [1]=0, [2]=0, [3]=0, [4]=0, [5]=0, [6]=0, [7]=0};

int main(void) {
    registers[3] = 42;
    registers[5] = registers[3];

    int i = 0;
    for (i = 0; i<8; i++) {
        printf("Value: %d\n",registers[i]);
    }
}