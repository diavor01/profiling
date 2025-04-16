/*
 *      decode.h
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file contains the declaration of the decode_intsruction function,
 *      which extracts the relevant information from a UM instruction for 
 *      later execution. 
 */

#ifndef DECODE_H
#define DECODE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <uarray.h>
#include <assert.h>
#include <bitpack.h>

void decode_instruction(uint32_t instruction, uint8_t *A, uint8_t *B, 
                        uint8_t *C, uint8_t *opcode, uint32_t *val);

#endif