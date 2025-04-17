/*
 *      exec.c
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file contains functionality for executing each instruction.
 *      It is also responsible for maintaining the state of the program.
 */

 #include "exec.h"
 #include "string.h"
 
 // /* An array hoding the registers */
 //static uint32_t registers[8] = {0, 0, 0, 0, 0, 0, 0, 0};
 
 // /* A sequence holding the recycled ids*/
 // static Seq_T recycled_ids;
 
 // /* A sequence holding the segments */
 // static Seq_T all_segments;
 
 // /********** initialize_program ********
 //  *
 //  * Allocates space and initializes the global sequences: all_segments and
 //  * recycled_ids.
 //  *
 //  * Parameters:
 //  *      UArray_T segment_zero: the segment containing instructions.
 //  *  
 //  * Returns:
 //  *      none
 //  *
 //  * Expects:
 //  *      A valid segment containing 32-bit instructions
 //  *
 //  * Notes:
 //  *      Allocates space for a two new global Seq_T objects, caller assumes
 //  *              responsibility for freeing the memory  
 //  */
 // void initialize_program(UArray_T segment_zero)
 // {
 //         all_segments = Seq_new(10);
 //         Seq_addhi(all_segments, segment_zero);        
 //         recycled_ids = Seq_new(10);
 // }
 
 // /********** execute_LV ********
 //  *
 //  * Loads an integer value into register A
 //  *
 //  * Parameters:
 //  *      uint8_t A: the index of the register to load a value into
 //  *      uint32_t val: the unsigned value to load into the register
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      A is between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if A is not between 0 and 7
 //  */
 // void execute_LV(uint8_t A, uint32_t val)
 // {
 //         registers[A] = val;
 // }
 
 // /********** execute_CMOV ********
 //  *
 //  * Puts the value from registers at index B in registers at index A if the
 //  * value in the register at index C is not 0.
 //  *
 //  * Parameters:
 //  *      uint8_t A:      the index of the register where to store the value
 //  *      uint8_t B:      the index of the register to retrieve the value from
 //  *      uint8_t C:      the index of the register to check when deciding
 //  *                      whether the assigment should be executed
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      A, B, and C are between 0 and 7
 //  *      
 //  * Notes:
 //  *      Will fail if A, B, and/or C are not within range 0 to 7
 //  *      
 //  * **************************/
 // void execute_CMOV(uint8_t A, uint8_t B, uint8_t C)
 // {
 //         if (registers[C] != 0) {
 //                 registers[A] = registers[B];
 //         }
 // }
 
 // /********** execute_SLOAD ********
 //  *
 //  * Stores the value at a given index in a given segment into register A.
 //  *
 //  * Parameters:
 //  *      uint8_t A: the index of the register to store the value in
 //  *      uint8_t B: the index of the register holding the segment id
 //  *      uint8_t C: the index of the register holding the segment offset
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      A, B, and C are between 0 and 7
 //  *      registers[B] is between 0 and the length of all_segments
 //  *      registers[C] is between 0 and the length of the specific segment
 //  *
 //  * Notes:
 //  *      Will fail if A, B, or C are not between 0 and 7
 //  *      Will fail if registers[B] is not between 0 and length of all_segments
 //  *      Will fail if registers[C] is between 0 and the length of the segment
 //  * **************************/
 // void execute_SLOAD(uint8_t A, uint8_t B, uint8_t C)
 // {
 //         UArray_T curr_segment = (UArray_T)Seq_get(all_segments, registers[B]);
 //         registers[A] = *(uint32_t *)UArray_at(curr_segment, registers[C]);
 // }
 
 // /********** execute_SSTORE ********
 //  *
 //  * Stores the value in register C into a given segment at a given index.
 //  *
 //  * Parameters:
 //  *      uint8_t A: the index of the register holding the segment id
 //  *      uint8_t B: the index of the register holding the segment offset
 //  *      uint8_t C: the index of the register holding the value to store
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      A, B, and C are between 0 and 7
 //  *      registers[A] is between 0 and the length of all_segments
 //  *      registers[B] is between 0 and the length of the specific segment
 //  *
 //  * Notes:
 //  *      Will fail if A, B, or C are not between 0 and 7
 //  *      Will fail if registers[A] is not between 0 and length of all_segments
 //  *      Will fail if registers[B] is between 0 and the length of the segment
 //  * **************************/
 // void execute_SSTORE(uint8_t A, uint8_t B, uint8_t C)
 // {
 //         UArray_T curr_segment = (UArray_T)Seq_get(all_segments, registers[A]);
 //         /* update the index in curr_segment to hold the new value */
 //         uint32_t *spot = (uint32_t *)UArray_at(curr_segment, registers[B]);
 //         *spot = registers[C];
 
 // }
 
 // /********** execute_HALT ********
 //  *
 //  * Cleans up memory allocated for all_segments and recycled_ids, then exits
 //  * successfully.
 //  *
 //  * Parameters: none
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      all_segments and recycled_ids are not NULL
 //  *
 //  * Notes:
 //  *      Will fail if all_segments or recycled_ids are NULL
 //  *      Frees memory allocated for all_segments, each UArray in all_segments,
 //  *              and recycled_ids - caller reliquishes responsibility for
 //  *              freeing the memory
 //  *      Will exit the program with exit code 0
 //  * **************************/
 // void execute_HALT()
 // {
 //         assert(all_segments != NULL && recycled_ids != NULL);
 
 //         /* free each element in all_segments */
 //         for (int i = 0; i < Seq_length(all_segments); i++) {
 //                 UArray_T curr_segment = (UArray_T)Seq_get(all_segments, i);
 //                 /* skip NULL elements (unmapped segments) */
 //                 if (curr_segment != NULL) {
 //                         UArray_free(&curr_segment);
 //                 }
 //         }
 
 //         Seq_free(&all_segments);
 //         Seq_free(&recycled_ids);
 
 //         exit(EXIT_SUCCESS);
 // }
 
 // /********** execute_OUT ********
 //  *
 //  * Outputs the value in a register as a character.
 //  *
 //  * Parameters:
 //  *      uint8_t C: the index of the register holding the value to output
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      C is between 0 and 7
 //  *      The value in registers[C] is between 0 and 255
 //  *
 //  * Notes:
 //  *      Will fail if C is not within range 0 to 7
 //  *      Will fail if the value in register C is not between 0 and 255
 //  * **************************/
 // void execute_OUT(uint8_t C)
 // {
 //         assert(registers[C] <= 255);
 //         printf("%c", (char)registers[C]);
 // }
 
 // /********** execute_INPUT ********
 //  *
 //  * Reads input from standard input and stores the value in register C.
 //  *
 //  * Parameters:
 //  *      uint8_t C: the index of the register to store the input in
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      C is between 0 and 7
 //  *      The input is a character with a corresponding ASCII value between 0
 //  *              and 255
 //  *
 //  * Notes:
 //  *      Will fail if C is not within range 0 to 7
 //  *      Will fail if the ASCII value of the input is not between 0 and 255
 //  *      If EOF (-1) is read in, a 32-bit value of all 1's will be put in
 //  *              register C
 //  * **************************/
 // void execute_INPUT(uint8_t C)
 // {
 //         int c = getchar();
 //         /* if the end of file is signaled, put special value in register C */
 //         if (c == -1) {
 //                 registers[C] = 0xFFFFFFFF;
 //                 return;
 //         }
 
 //         /* else, if within bounds, load the new character */
 //         // assert(c <= 255);
 //         registers[C] = c;
 // }
 
 // /********** execute_ADD ********
 //  *
 //  * Adds the values in the registers B and C, storing the result in register A
 //  *
 //  * Parameters:
 //  *      uint8_t A: the index of the register to store the result in
 //  *      uint8_t B: the index of the register holding the first value to add
 //  *      uint8_t C: the index of the register holding the second value to add
 //  *
 //  * Returns: none
 //  *
 //  * Expects:
 //  *      A, B, and C are between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if A, B, and/or C are not within range 0 to 7
 //  *      If the result is above 2^32, it will be modded by 2^32 before storing
 //  * **************************/
 // void execute_ADD(uint8_t A, uint8_t B, uint8_t C)
 // {
 //         /* note: C will automatically mod overflowing values by 2^32 */
 //         registers[A] = (registers[B] + registers[C]);
 // }
 
 // /********** execute_MUL ********
 //  *
 //  * Multiplies the values in the registers B and C, storing the result in
 //  * register A
 //  *
 //  * Parameters:
 //  *      uint8_t A: the index of the register to store the result in
 //  *      uint8_t B: the index of the register holding a value to multiply
 //  *      uint8_t C: the index of the register holding a value to multiply
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      A, B, and C are between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if A, B, and/or C are not within range 0 to 7
 //  *      If the result is above 2^32, it will be modded by 2^32 before storing
 //  * **************************/
 // void execute_MUL(uint8_t A, uint8_t B, uint8_t C)
 // {
 //         /* note: C will automatically mod overflowing values by 2^32*/
 //         registers[A] = (registers[B] * registers[C]);
 // }
 
 // /********** execute_DIV ********
 //  *
 //  * Divides the value in register B by the value in register C, storing the
 //  * result in register A
 //  *
 //  * Parameters:
 //  *      uint8_t A: the index of the register to store the result in
 //  *      uint8_t B: the index of the register holding the dividend
 //  *      uint8_t C: the index of the register holding the divisor
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      A, B, and C are between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if A, B, and/or C are not within range 0 to 7
 //  *      Will fail if the value in registers[C] is 0
 //  *      The result will be rounded down to an int
 //  * **************************/
 // void execute_DIV(uint8_t A, uint8_t B, uint8_t C)
 // {
 //         /* note: C will automatically truncate/floor the values */
 //         registers[A] = registers[B] / registers[C];
 // }
 
 // /********** execute_NAND ********
 //  *
 //  * Calculate the bitwise NAND of the values in registers B and C, storing the
 //  * result in registers[A].
 //  *
 //  * Parameters:
 //  *      uint8_t A: the index of the register to store the result in
 //  *      uint8_t B: the index of the register holding the first value
 //  *      uint8_t C: the index of the register holding the second value
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      A, B, and C are between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if A, B, and/or C are not within range 0 to 7
 //  * **************************/
 // void execute_NAND(uint8_t A, uint8_t B, uint8_t C)
 // {
 //         registers[A] = ~(registers[B] & registers[C]);
 // }
 
 // /********** execute_ACTIVATE ********
 //  *
 //  * Maps a new segment of a given length and places it into all_segments.
 //  * Elements are initialized to 0.
 //  *
 //  * Parameters:
 //  *      uint8_t B: the index of the register where the id of the new semgent
 //  *                      will be stored
 //  *      uint8_t C: the index of the register holding the length of the new
 //  *                      segment to map
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      B and C are between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if B and/or C are not within range 0 to 7
 //  *      Allocates memory for a new UArray_T object that is inserted into
 //  *              all_segments, caller assumes responsibility for freeing it
 //  * **************************/
 // void execute_ACTIVATE(uint8_t B, uint8_t C)
 // {
 //         /* create a new segment to map */
 //         UArray_T new_seg = UArray_new(registers[C], 4);
 
 //         int id;
 //         /* if there are unused ids from unmapped segments, re-use */
 //         if (Seq_length(recycled_ids) != 0) {
 //                 /* pop the id from recycled_ids */
 //                 id = (uint32_t)(uintptr_t)Seq_remlo(recycled_ids);
 //                 /* put the new segment at index [id] of all_segments */
 //                 Seq_put(all_segments, id, new_seg);
 //         } else {
 //                 /* if no unused ids, get next id and append */
 //                 id = Seq_length(all_segments);
 //                 Seq_addhi(all_segments, new_seg);
 //         }
 //         /* store id */
 //         registers[B] = id;
 // }
 
 
 // /********** execute_INACTIVATE ********
 //  *
 //  * Inactivates a segment stored in all_segments. Its corresponding id is
 //  * recycled.
 //  *
 //  * Parameters:
 //  *      uint8_t C:      the id at which the segment is stored
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      C is between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if C is not within range 0 to 7
 //  *      Will fail the id is out of bounds or if the associated segment in NULL.
 //  * **************************/
 // void execute_INACTIVATE(uint8_t C)
 // {
 //         /* cannot unmap segment zero */
 //         assert(registers[C] != 0);
 
 //         /* malloc id to add to recycled_ids (since sequences store pointers) */
 //         uint32_t id = registers[C];
 
 //         /* free the current segment at that index */
 //         UArray_T curr_segment = (UArray_T)Seq_get(all_segments, id);
 
 //         assert(curr_segment != NULL);
 //         UArray_free(&curr_segment);
 
 //         /* replace the segment with nullptr, add id to recycled_ids */
 //         Seq_put(all_segments, id, (void*)NULL);
 //         Seq_addhi(recycled_ids, (void *)(uintptr_t)id);
 // }
 
 
 // /********** execute_LOADP ********
 //  *
 //  * Move a segment into segment zero after duplicating it. Updates the
 //  * program counter to a new value.
 //  *
 //  * Parameters:
 //  *      uint8_t B:      the id at which the segment we want to move is stored
 //  *      uint8_t C:      holds the value of the new program counter
 //  *      int *pc:        a pointer value that will be updated to hold the
 //  *                              new program counter
 //  *
 //  * Returns: none
 //  *
 //  * Expects
 //  *      B and C are between 0 and 7
 //  *
 //  * Notes:
 //  *      Will fail if B, and/or C are not within range 0 to 7
 //  *      Will fail the id is out of bounds or if the associated segment in NULL.
 //  *      Allocates memory for a new UArray_T object and stores it into
 //  *              all_segments, caller assumes responsibility for freeing it
 //  *      Frees memory for the old UArray_T at the given index of all_segments,
 //  *              caller relinquishes responsibility for freeing it
 //  *      pc will be updated to hold the new program counter
 //  * **************************/
 // void execute_LOADP(uint8_t B, uint8_t C, int *pc)
 // {
 //         /* update the new program counter */
 //         *pc = registers[C];
 
 //         /* if the segment is already segment_zero, no need to update */
 //         if (registers[B] == 0) {
 //                 return;
 //         }
 
 //         int id = registers[B];
 //         /* create a deep copy of the segment */
 //         UArray_T segment_to_copy = Seq_get(all_segments, id);
 //         int length = UArray_length(segment_to_copy);
 //         UArray_T new_segment = UArray_copy(segment_to_copy, length);
 
 //         /* put the new segment into segment zero and free the old */
 //         struct Segment old = Seq_put(all_segments, 0, new_segment);
 //         UArray_free(&old);
 // }
 
 
 
 
 /********** execute_instruction ********
  *
  * Executes the instructions in segment_zero by calling the corresponding
  * instruction functions
  *
  * Parameters: none
  *
  * Returns: none
  *
  * Expects
  *      all_segments has been initialized with segment_zero (a UArray_T of
  *              32-bit instructions) as its first element
  *      the first four bits of instruction hold a value from 0 to 13
  *
  * Notes:
  *      Will exit unsuccessfully if the opcode (first four bits of
  *              instruction) is not in the range 0 to 13
  *      May CRE indirectly through called functions
  * **************************/
 void execute_instructions(struct Segment *segment_zero)
 {
         int pc = 0;
 
         long long length_seg_zero = segment_zero->length;
 
         Seq_T all_segments = Seq_new(10);
         Seq_addhi(all_segments, segment_zero);        
         Seq_T recycled_ids = Seq_new(10);
         uint32_t registers[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        
         uint8_t A;
         uint8_t B;
         uint8_t C;
         uint32_t val;
         int id;
 
         struct Segment *curr_segment;
 
         /* continue executing until the end of segment_zero */
         while (pc < length_seg_zero) {
                 //fprintf(stderr, "pc is %d\n", pc);
         
                 uint32_t instruction = segment_zero->arr[pc];
                 uint8_t opcode = (instruction & 4026531840) >> 28;
 
                 /* update pc to point to the next instruction */
                 pc++;
 
                 /* execute the corresponding instruction */
                 switch (opcode) {
                         case CMOV:
                                 A = (instruction & 448) >> 6;
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;
  
                                 if (registers[C] != 0) {
                                         registers[A] = registers[B];
                                 }
                                 break;
                         case SLOAD:
                                 A = (instruction & 448) >> 6;
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;
                                 
                                 curr_segment = Seq_get(all_segments, registers[B]);
                                 registers[A] = curr_segment->arr[registers[C]];
                                 break;
                         case SSTORE:
                                 A = (instruction & 448) >> 6;
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;
                                 
                                 curr_segment = Seq_get(all_segments, registers[A]);
                                 curr_segment->arr[registers[B]] = registers[C];
 
                                 break;
                         case ADD:
                                 A = (instruction & 448) >> 6;
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;

                                 registers[A] = (registers[B] + registers[C]);
                                 break;
                         case MUL:
 
                                 A = (instruction & 448) >> 6;
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;

                                 registers[A] = (registers[B] * registers[C]);
                                 break;
                         case DIV:
                                 A = (instruction & 448) >> 6;
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;

                                 registers[A] = registers[B] / registers[C];
                                 break;
                         case NAND:
                                 A = (instruction & 448) >> 6;
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;

                                 registers[A] = ~(registers[B] & registers[C]);
                                 break;
                         case HALT:
                                 /* free each element in all_segments */
                                 for (int i = 0; i < Seq_length(all_segments); i++) {
                                         curr_segment = Seq_get(all_segments, i);
                                         free(curr_segment->arr);
                                         free(curr_segment);                                         
                                 }
 
                                 Seq_free(&all_segments);
                                 Seq_free(&recycled_ids);
                                 exit(EXIT_SUCCESS);
                                 break;

                         case ACTIVATE:
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;

                                 /* allocate space for new array */
                                 uint32_t *array = calloc(registers[C], sizeof(uint32_t));
 
                                 /* if there are unused ids from unmapped segments, re-use the struct */
                                 if (Seq_length(recycled_ids) != 0) {
                                         /* pop the id from recycled_ids */
                                         id = (uint32_t)(uintptr_t)Seq_remlo(recycled_ids);
                                         /* update the members of the struct, NOT the struct itself */
                                         curr_segment = Seq_get(all_segments, id);
                                         curr_segment->arr = array;
                                         curr_segment->length = registers[C];
                                 } else {
                                         /* if no unused ids, get next id and create a new struct to append */
                                         id = Seq_length(all_segments);

                                         struct Segment *new_seg = calloc(1, sizeof(*new_seg));
                                         new_seg->length = registers[C];
                                         new_seg->arr = array;
                                         Seq_addhi(all_segments, new_seg);

                                 }
                                 /* store id */
                                 registers[B] = id;
                        
                                 break;
                         case INACTIVATE:
                                 C = instruction & 7;
                                
                                 /* cannot unmap segment zero */
                                 assert(registers[C] != 0);
 
                                 /* malloc id to add to recycled_ids (since sequences store pointers) */
                                 id = registers[C];
 
                                 /* free the current segment's array and set to NULL (NOT the struct itself)*/
                                 curr_segment = Seq_get(all_segments, id);

                                 free(curr_segment->arr);
                                 curr_segment->arr = NULL;
 
                                 /* add id to recycled_ids */
                                 Seq_addhi(recycled_ids, (void *)(uintptr_t)id);
                                
                                 break;
                         case OUT:
                                 C = instruction & 7;
                                 assert(registers[C] <= 255);
                                 printf("%c", (char)registers[C]);
                                 break;
                         case IN:
                                 C = instruction & 7;
                                 int c = getchar();
                                 /* if the end of file is signaled, put special value in register C */
                                 if (c == -1) {
                                         registers[C] = 0xFFFFFFFF;
                                         break;
                                 }
 
                                 /* else, if within bounds, load the new character */
                                 //assert(c <= 255);
                                 registers[C] = c;
                                 break;
                         case LOADP:
                                 B = (instruction & 56) >> 3;
                                 C = instruction & 7;
                                 /* note: pc may update here */
                                 pc = registers[C];
 
                                 /* if the segment is already segment_zero, no need to update */
                                 if (registers[B] == 0) {
                                         break;
                                 }
 
                                 id = registers[B];

                                 /* create deep copy of the segment's array (NOT the struct itself) */
                                 struct Segment *segment_to_copy = Seq_get(all_segments, id);
                                 uint32_t *new_arr = calloc(segment_to_copy->length, sizeof(uint32_t));
                                 memcpy(new_arr, segment_to_copy->arr, segment_to_copy->length * sizeof(uint32_t));

                                 /* update the members of the segment zero struct */
                                 free(segment_zero->arr);
                                 segment_zero->length = segment_to_copy->length;
                                 segment_zero->arr = new_arr;
                                
                                 length_seg_zero = segment_zero->length;
                                 break;
                         case LV:
                                 val = (instruction & 33554431);
                                 A = ((instruction & 234881024) >> 25);

                                 registers[A] = val;
                                 break;
                         default:
                                 exit(EXIT_FAILURE);
                 }
         }
 
         /*
          * Normally, clean-up happens once the halt instruction is executed.
          * This takes care of the case where the user does not halt, to
          * ensure no memory leaks
          */
         //execute_HALT();
         for (int i = 0; i < Seq_length(all_segments); i++) {
                 curr_segment = Seq_get(all_segments, i);
                 free(curr_segment->arr);
                 free(curr_segment);
         }
 
         Seq_free(&all_segments);
         Seq_free(&recycled_ids);
         exit(EXIT_SUCCESS);
 }
 