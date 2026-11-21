#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <inttypes.h>

struct decoded_instruction {
    uint32_t mode;
    uint32_t is_imm;
    uint32_t opcode;
    uint32_t dest;
    uint32_t regA;
    uint32_t regB;
    uint32_t imm_val;
};

struct decoded_instruction decode(uint32_t instruction) {
    /* 
    0MM0OOOO DDDDAAAA 0000BBBB 00000000 
    0MM1OOOO DDDDAAAA IIIIIIII IIIIIIII
    MM = Mode
    0/1 after Mode = Immediate
    OOOO = Opcode
    DDDD = Destination Register
    AAAA = Register A
    BBBB = Register B
    I = Immediate Value
    */
    uint32_t imm_check = instruction >> 28;
    uint32_t is_imm = imm_check & 1;


    if (is_imm == 1) {

    }
}

void main() {

}