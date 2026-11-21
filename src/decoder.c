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

struct decoded_instruction decode(uint32_t instruction_32) {
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
    uint32_t is_imm = (instruction_32 >> 28) & 0x1;
    struct decoded_instruction instruction = {
        (instruction_32 >> 29) & 0x3, 
        is_imm,
        (instruction_32 >> 24) & 0xF, 
        (instruction_32 >> 20) & 0xF, 
        (instruction_32 >> 16) & 0xF, 
        0,
        0, 
    };

    if (is_imm == 1) {
        instruction.imm_val = instruction_32 & 0xFFFF;
    }
    else {
        instruction.regB = (instruction_32 >> 8) & 0xF;
    };

    return instruction;
}

int main(void) {

}