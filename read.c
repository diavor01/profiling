/*
 *      exec.c
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file is responsible for reading in and storing instructions
 *      from a file stream.
 */

#include "read.h"
#include <uarray.h>

/********** read_instruction ********
 *
 * Reads an instruction from an input stream.
 * 
 * Parameters:
 *      FILE *fp: the input stream
 *
 * Return: the instruction as a 32-bit unsigned integer
 * 
 * Expects
 *      A valid input stream (with valid UM instructions)
 * 
 * Notes:
 *      May CRE indirectly if bitpacking fails.
 * **************************/
// uint32_t read_instruction(FILE *fp)
// {
//         /* Bitpack expects 64-bit unsigned values */
//         uint64_t instruction = 0;

//         /* read 4 bytes in big-endian order, bitpack into a 32-bit word */
//         for (int i = 0; i < 4; i++) {
//                 uint64_t c = (uint64_t)fgetc(fp); 
//                 instruction = Bitpack_newu(instruction, 8, 24 - i * 8, c);
//         }       

//         /* Convert to a 32-bit value */
//         return (uint32_t)instruction;

// }


struct segment {
        long long length;
        uint32_t *arr;
};


/********** store_instructions ********
 *
 * Creates a segment containing all the instructions from the input file
 * 
 * Parameters:
 *      FILE *fp:                       the input stream
 *      long long num_instructions:     the number of instructions in the input
 *                                      stream
 *
 * Returns: 
 *      A UArray_T value containing all the instructions from the input stream
 * 
 * Expects
 *      - A valid input stream (with valid instructions)
 *      - A valid number of instructions, coresponding to the actual number of 
 *      32-bit words in the input stream
 * 
 * Notes:
 *      
 * **************************/
UArray_T store_instructions(FILE *fp, long long num_instructions) 
{
        /* create new segment zero with appropriate size */
        UArray_T segment_zero = UArray_new(num_instructions, 4);

        
        
        //uint32_t instruction;
        int counter = 0;
        // uint8_t buffer[4];

        // // while (fread(&buffer, 1, 4, file) == 4) {
        // //         uint32_t instruction = (buffer[0] << 24) |
        // //                          (buffer[1] << 16) |
        // //                          (buffer[2] << 8)  |
        // //                          (buffer[3]);

        //         uint32_t instruction_copy = instruction;
        //         /* insert new instruction into the segment */
        //         uint32_t *spot = (uint32_t*)UArray_at(segment_zero, counter);
        //         *spot = instruction_copy;
        //         counter++;
        // //         printf("Read 32-bit big-endian value: %u\n", value);
        // // }

        uint8_t buffer[4];
        while (counter < num_instructions) {
                //uint32_t instruction = read_instruction(fp);

                fread(&buffer, 1, 4, fp);
                uint32_t instruction = (buffer[0] << 24) |
                                        (buffer[1] << 16) |
                                        (buffer[2] << 8)  |
                                        (buffer[3]);
                /* insert new instruction into the segment */
                uint32_t *spot = (uint32_t*)UArray_at(segment_zero, counter);
                //*spot = instruction_copy;
                *spot = instruction;
                counter++;
        }
        
        return segment_zero;
}