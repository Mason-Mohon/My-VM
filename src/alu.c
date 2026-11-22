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
        case 7: /*LSL*/ output = argA << argB; break;
        case 8: /*LSR*/ output = argA >> argB; break;
        case 9: /*ASR*/ 
            if ((argB % 32) == 0) {output = argA; break;}
            else {
                uint32_t sign = (argA >> 31) & 0x1; 
                uint32_t shift = argA >> (argB & 0x1F);
                uint32_t fill = 0;
                if (sign == 1) {fill = 0xFFFFFFFF << (32 - (argB & 0x1F));};
                output = shift | fill;
                break;
            }
        case 10:/*CMP*/ 
            if (argB == argA) {output = 1;}
            else if ((argA >> 31) == 0) {if (argA < argB) {output = 2;} else {output = 0;};}
            else {if (argA < argB) {output = 3;} else {output = 0;};};
            /*TODO: store output in flags register for jumps on comparison*/
            /*TODO: rest of comparisons and encoding rules*/
            break;              
    };

    return output;
}

int main(void) {

};