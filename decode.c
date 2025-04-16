/*
 *      decode.c
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file is responsible for extracting the relevant information from
 *      a UM instruction for later execution.
 */

#include "opcode.h"
#include "decode.h"

/********** decode_instruction ********
 *
 * Extracts the opcode, registers, and value information from the instruction
 * 
 * Parameters:
 *      uint32_t instruction: a 32-bit instruction
 *      uint8_t *A: 8-bit int pointer that may update to hold register A
 *      uint8_t *B: 8-bit int pointer that may update to hold register B
 *      uint8_t *C: 8-bit int pointer that may update to hold register C
 *      uint8_t *opcode: 8-bit int pointer that will update to hold the opcode
 *      uint32_t *val: 32-bit int pointer that may update to hold a value
 *
 * Returns: none
 *
 * Expects
 *      none of the input pointers are NULL
 * 
 * Notes:
 *      Will CRE if any of the input pointers are NULL
 *      May CRE if bitpacking fails
 * **************************/
void decode_instruction(uint32_t instruction, uint8_t *A, uint8_t *B, 
                        uint8_t *C, uint8_t *opcode, uint32_t *val)
{       
        assert(A != NULL && B != NULL && C != NULL);
        assert(opcode != NULL && val != NULL);

        /* the first 4 bits (msb) represent the operation code */
        *opcode = (uint32_t)Bitpack_getu((uint64_t)instruction, 4, 28);

        /* for 3-register functions, get each register */
        if (*opcode != LV) {

                *A = (uint8_t)Bitpack_getu(instruction, 3, 6);
                *B = (uint8_t)Bitpack_getu(instruction, 3, 3);
                *C = (uint8_t)Bitpack_getu(instruction, 3, 0);
        } else {
                /* for load val, get the register and the value to input */
                *A = (uint8_t)Bitpack_getu(instruction, 3, 25);
                *val = (uint32_t)Bitpack_getu(instruction, 25, 0);
        }
}