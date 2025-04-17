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

struct Vector {
        uint64_t length;
        uint64_t capacity;
        Segment *arr;
}

// to create new instance:
struct Vector test;
test->length = 0;
test->capacity = 100;
test->arr = calloc(test->capacity, sizeof(struct *Segment));

uint64_t expand_capacity(Segment *arr) {
        if (capacity <= length) {
                capacity *= 2 + 1;
                arr = realloc(arr, capacity * sizeof(struct *Segment));
        }
        return capacity;
}

void free(Segment *arr)
{
        free(arr);

        curr_segment = arr[i];
        free(curr_segment->arr);
                 free(curr_segment);
}

#endif