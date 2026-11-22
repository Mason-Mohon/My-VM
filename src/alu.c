#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <inttypes.h>

uint32_t registers[8] = {[0]=0, [1]=0, [2]=0, [3]=0, [4]=0, [5]=0, [6]=0, [7]=0};


uint32_t ALU(int arg, uint32_t src1, uint32_t src2) {

    uint32_t output = 0;
    uint32_t argA = registers[src1];
    uint32_t argB = registers[src2];

    switch (arg) {
        case 0: /*NAND*/uint32_t nand = argA & argB; output = ~nand; break;
        case 1: /*OR*/  output = argA | argB; break;
        case 2: /*AND*/ output = argA & argB; break;
        case 3: /*NOR*/ uint32_t nor = argA | argB; output = ~nor; break;
        case 4: /*ADD*/ output = argA + argB; break;
        case 5: /*SUB*/ output = argA - argB; break;
        case 6: /*XOR*/ output = argA ^ argB; break;  
        case 7: /*LSL*/ break;
        case 8: /*LSR*/ break;
        case 9: /*ASR*/ break;
        case 10:/*CMP*/ break;              
    };

    return output
}

int main(void) {

};