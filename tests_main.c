/*
 *      tests_main.c
 *      Written by course staff
 *      um
 *
 *      Driver file for creating .um files. 
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assert.h"
#include "fmt.h"
#include "seq.h"


extern void Um_write_sequence(FILE *out, Seq_T instructions);

extern void build_halt_test1(Seq_T stream);
extern void build_out_test1(Seq_T stream);
extern void build_out_test2(Seq_T stream);
extern void build_input_test1(Seq_T stream);
extern void build_input_test2(Seq_T stream);
extern void build_cmov_test1(Seq_T stream);
extern void build_cmov_test2(Seq_T stream);
extern void build_add_test1(Seq_T stream);
extern void build_add_test2(Seq_T stream);
extern void build_mul_test1(Seq_T stream);
extern void build_mul_test2(Seq_T stream);
extern void build_div_test1(Seq_T stream);
extern void build_div_test2(Seq_T stream);
extern void build_nand_test1(Seq_T stream);
extern void build_activate_test1(Seq_T stream);
extern void build_inactivate_test1(Seq_T stream);
extern void build_inactivate_test2(Seq_T stream);
extern void build_sstore_test1(Seq_T stream);
extern void build_sstore_test2(Seq_T stream);
extern void build_sload_test1(Seq_T stream);
extern void build_sload_test2(Seq_T stream);
extern void build_loadp_test1(Seq_T stream);
extern void build_loadp_test2(Seq_T stream);

/* The array `tests` contains all unit tests for the lab. */

static struct test_info {
        const char *name;
        const char *test_input;          /* NULL means no input needed */
        const char *expected_output;
        /* writes instructions into sequence */
        void (*build_test)(Seq_T stream);
} tests[] = {
        // {"halt1", NULL, "", build_halt_test1},
        // {"out1", NULL, "A", build_out_test1},
        // {"out2", NULL, 
        //         "A B C D E F \nB C D E F G \n", build_out_test2},
        // {"input1", "qwert", "qwert", build_input_test1},
        // {"input2", "Hello", "Hello", build_input_test2},
        // {"cmov1", NULL, "2F", build_cmov_test1},
        // {"folder4/cmov2", NULL, "FF", build_cmov_test2},
        // {"folder4/add1", NULL, "COOL", build_add_test1},
        // {"folder4/add2", NULL, "H", build_add_test2},
        // {"folder4/mul1", NULL, "B", build_mul_test1},
        // {"folder4/mul2", NULL, "A", build_mul_test2},
        // {"folder4/div1", NULL, "A", build_div_test1},
        // {"folder4/div2", NULL, "z=Z", build_div_test2},
        // {"folder4/nand1", NULL, "{", build_nand_test1},
        // {"folder4/activate1", NULL, "", build_activate_test1},
        // {"folder4/inactivate1", NULL, "", build_inactivate_test1},
        // {"folder4/inactivate2", NULL, "", build_inactivate_test2},
        // {"folder4/sstore1", NULL, "", build_sstore_test1},
        // {"folder4/sstore2", NULL, "", build_sstore_test2},
        // {"folder4/sload1", NULL, "", build_sload_test1},
        // {"folder4/sload2", NULL, "~", build_sload_test2},
        {"loadp1", NULL, "", build_loadp_test1},
        {"loadp2", NULL, "", build_loadp_test2}
};

#define NTESTS (sizeof(tests)/sizeof(tests[0]))

/*
 * open file 'path' for writing, then free the pathname;
 * if anything fails, checked runtime error
 */
static FILE *open_and_free_pathname(char *path);

/*
 * if contents is NULL or empty, remove the given 'path', 
 * otherwise write 'contents' into 'path'.  Either way, free 'path'.
 */
static void write_or_remove_file(char *path, const char *contents);

static void write_test_files(struct test_info *test);


int main (int argc, char *argv[])
{
        bool failed = false;
        if (argc == 1)
                for (unsigned i = 0; i < NTESTS; i++) {
                        printf("***** Writing test '%s'.\n", tests[i].name);
                        write_test_files(&tests[i]);
                }
        else
                for (int j = 1; j < argc; j++) {
                        bool tested = false;
                        for (unsigned i = 0; i < NTESTS; i++)
                                if (!strcmp(tests[i].name, argv[j])) {
                                        tested = true;
                                        write_test_files(&tests[i]);
                                }
                        if (!tested) {
                                failed = true;
                                fprintf(stderr,
                                        "***** No test named %s *****\n",
                                        argv[j]);
                        }
                }
        return failed; /* failed nonzero == exit nonzero == failure */
}


static void write_test_files(struct test_info *test)
{
        FILE *binary = open_and_free_pathname(Fmt_string("%s.um", test->name));
        Seq_T instructions = Seq_new(0);
        test->build_test(instructions);
        Um_write_sequence(binary, instructions);
        Seq_free(&instructions);
        fclose(binary);

        write_or_remove_file(Fmt_string("%s.0", test->name),
                             test->test_input);
        write_or_remove_file(Fmt_string("%s.1", test->name),
                             test->expected_output);
}


static void write_or_remove_file(char *path, const char *contents)
{
        if (contents == NULL || *contents == '\0') {
                remove(path);
        } else {
                FILE *input = fopen(path, "wb");
                assert(input != NULL);

                fputs(contents, input);
                fclose(input);
        }
        free(path);
}


static FILE *open_and_free_pathname(char *path)
{
        FILE *fp = fopen(path, "wb");
        assert(fp != NULL);

        free(path);
        return fp;
}
