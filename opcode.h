/*
 *     opcode.h
 *     by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *     um
 *
 *     This file contains the definition of the opcodes.
 */

#ifndef OPCODEH
#define OPCODE_H

/* enumerate the opcodes starting from 0 */
typedef enum Um_opcode
{
        CMOV = 0,
        SLOAD,
        SSTORE,
        ADD,
        MUL,
        DIV,
        NAND,
        HALT,
        ACTIVATE,
        INACTIVATE,
        OUT,
        IN,
        LOADP,
        LV
} Um_opcode;

struct Segment {
        long long length;
        uint32_t *arr;
};

#endif