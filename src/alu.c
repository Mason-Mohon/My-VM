#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <inttypes.h>

uint32_t registers[8] = {[0]=0, [1]=0, [2]=0, [3]=0, [4]=0, [5]=0, [6]=0, [7]=0};

void nand(int dest, uint32_t src1, uint32_t src2) {}

void or(int dest, uint32_t src1, uint32_t src2) {}

void and(int dest, uint32_t src1, uint32_t src2) {}

void nor(int dest, uint32_t src1, uint32_t src2) {}

void add(int dest, uint32_t src1, uint32_t src2) {
    uint32_t sum = registers[src1] + registers [src2];
   registers[dest] = sum;
}

void sub(int dest, uint32_t src1, uint32_t src2) {
    uint32_t dif = registers[src1] - registers [src2];
    registers[dest] = dif;
}

void xor(int dest, uint32_t src1, uint32_t src2) {}

void lsl(int dest, uint32_t src1, uint32_t src2) {}

void lsr(int dest, uint32_t src1, uint32_t src2) {}

void asr(int dest, uint32_t src1, uint32_t src2) {}

void cmp(int dest, uint32_t src1, uint32_t src2) {}

void ALU(int arg, int dest, uint32_t src1, uint32_t src2) {

    switch (arg) {

        case 0: 
            nand(dest, src1, src2);
            break;
        
        case 1:
            or(dest, src1, src2);
            break;
    };
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