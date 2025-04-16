/*
 *      help_test_funcs.c
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file contains helper functions that we used for debugging 
 *      our program. They are not part of the program logic.
 */
void print_segments() {
        for (int i = 0; i < Seq_length(all_segments); i++) {
                fprintf(stderr, "Segment %d:\n", i);
                void *elem = Seq_get(all_segments, i);
                if (elem != NULL) {
                        UArray_T curr_segment = (UArray_T)elem;
                        for (int j = 0; j < UArray_length(curr_segment); j++) {
                                print_binary(*(uint32_t*)
                                             UArray_at(curr_segment, j));
                        }
                } else {
                        fprintf(stderr, "NULL\n");
                }
        }
}

void print_binary(uint32_t n)
{
        uint32_t val = 1 << 31;
        for (uint32_t i = 0; i < sizeof(n) * 8; i++)
        {
                uint32_t curr_dig = val & n;
                curr_dig = curr_dig >> 31;
                fprintf(stderr, "%u", curr_dig);
                n = n << 1;
        }
        fprintf(stderr, "\n");
}

void print_registers() {
        fprintf(stderr, "registers: ");
        for (int i = 0; i < 8; i++) {
                fprintf(stderr, "%u ", registers[i]);
        }
        fprintf(stderr, "\n");
}

void print_recycled_ids()
{
        fprintf(stderr, "Printing recycled_ids\n");
        for (int i = 0; i < Seq_length(recycled_ids); i++) {
                fprintf(stderr, "%u ", *(uint32_t*)Seq_get(recycled_ids, i));
        }
        fprintf(stderr, "\n");
}