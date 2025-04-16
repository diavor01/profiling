/*
 *      read.h
 *      by Ella Hou (ehou02), Darius-Stefan Iavorschi (diavor01)
 *      um
 *
 *      This file contains the declaration of the store_instructions function,
 *      which reads in instructions from a filestream. 
 */

#ifndef READ_H
#define READ_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <bitpack.h>
#include "uarray.h"

UArray_T store_instructions(FILE *fp, long long num_instructions);

#endif