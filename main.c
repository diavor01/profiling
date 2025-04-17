/*
 *      main.c
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file is the main driver file of the program, which handles 
 *      control flow.
 */

#include "exec.h"
#include "read.h"
#include "decode.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/********** main ********
 *
 * This is the main driver function of the program, handling control flow.
 * 
 * Parameters:
 *      int argc: the number of arguments on the command line
 *      char *argv[]: the command line arguments
 *
 * Return: a successful exit code
 *
 * Expects
 *      a valid .um file is inputted on the command line
 *      format of command line arguments is:
 *              ./um [filename.um] < [optional_input.txt]
 * 
 * Notes:
 *      Will CRE if the number of command line arguments is not 2
 *      Will exit unsuccessfully if the file cannot be opened
 *      May CRE indirectly from called functions
 * **************************/
int main(int argc, char *argv[])
{
        // assert(argc == 2);
        if (argc != 2) {
                fprintf(stderr, "Incorrect number of arguments\n");
                exit(EXIT_FAILURE);
        }

        FILE *fp = fopen(argv[1], "rb");
        if (fp == NULL) {
                fprintf(stderr, "%s: No such file or directory", argv[1]);
                exit(EXIT_FAILURE);
        }

        /* get the number of instructions in the .um file */
        struct stat st;
        assert(stat(argv[1], &st) == 0);
        long long num_instructions = st.st_size / 4;

        /* initialize segment zero and initialize the state of the program */
        //UArray_T segment_zero = store_instructions(fp, num_instructions);
        //UArray_T segment_zero = UArray_new(num_instructions, 4);

        struct Segment *segment_zero = calloc(1, sizeof(*segment_zero));
        segment_zero->length = num_instructions;

        uint32_t *array = calloc(num_instructions, sizeof(uint32_t));
        segment_zero->arr = array;

        int counter = 0;

        uint8_t buffer[4];
        while (counter < num_instructions) {
                //uint32_t instruction = read_instruction(fp);

                fread(&buffer, 1, 4, fp);
                uint32_t instruction = (buffer[0] << 24) |
                                        (buffer[1] << 16) |
                                        (buffer[2] << 8)  |
                                        (buffer[3]);
                /* insert new instruction into the segment */
                //uint32_t *spot = (uint32_t*)UArray_at(segment_zero, counter);
                segment_zero->arr[counter] = instruction;
                //*spot = instruction_copy;
                //*spot = instruction;
                counter++;
        }

        fclose(fp);

        /* initialize the state of the program using segment_zero */
        //initialize_program(segment_zero);

        execute_instructions(segment_zero);

        return 0;
}