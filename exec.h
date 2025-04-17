/*
 *      exec.h
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file contains the definitions of the functions responsible for 
 *      executing the instructions.
 */

#ifndef EXEC_H
#define EXEC_H

#include "stdio.h"
#include "stdlib.h"
//#include <uarray.h>
#include <seq.h>
#include <stdint.h>
#include <assert.h>
#include "stdbool.h"
#include "exec.h"
#include "opcode.h"
//#include "decode.h"


// void execute_LV(uint8_t A, uint32_t val);
// void execute_CMOV(uint8_t A, uint8_t B, uint8_t C);
// void execute_SLOAD(uint8_t A, uint8_t B, uint8_t C);
// void execute_SSTORE(uint8_t A, uint8_t B, uint8_t C);
// void execute_OUT(uint8_t C);
// void execute_HALT();
// void execute_INPUT(uint8_t C);
// void execute_ADD(uint8_t A, uint8_t B, uint8_t C);
// void execute_MUL(uint8_t A, uint8_t B, uint8_t C);
// void execute_DIV(uint8_t A, uint8_t B, uint8_t C);
// void execute_NAND(uint8_t A, uint8_t B, uint8_t C);
// void execute_ACTIVATE(uint8_t B, uint8_t C);
// void execute_INACTIVATE(uint8_t C);
// void execute_LOADP(uint8_t B, uint8_t C, int *pc);
// void initialize_program(UArray_T segment_zero);
void execute_instructions(struct Segment *segment_zero);

#endif
