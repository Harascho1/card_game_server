#ifndef MY_ERROR_H
#define MY_ERROR_H

#include <stdio.h>

#define ERROR(msg) fprintf(stderr, "Error: %s\n", msg)

#endif // MY_ERROR_H