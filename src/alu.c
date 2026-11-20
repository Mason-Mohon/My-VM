#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <inttypes.h>

uint32_t registers[8] = {[0]=0, [1]=0, [2]=0, [3]=0, [4]=0, [5]=0, [6]=0, [7]=0};

void add(int dest, int src1, int src2) {
    uint32_t sum = registers[src1] + registers [src2];
   registers[dest] = sum;
}

void sub(int dest, int src1, int src2) {
    uint32_t dif = registers[src1] - registers [src2];
    registers[dest] = dif;
}

int main(void) {

    registers[1] = 0xFFFFFFFF;
    registers[2] = 1;
    add(3, 1, 2 );
    printf("Addition value: %u\n",registers[3]);

    registers[1] = 0;
    sub(4, 1, 2 );
    printf("Subtraction value: %u\n", registers[4]);
};