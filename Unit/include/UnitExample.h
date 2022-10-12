#ifndef UNITEXAMPLE_H
#define UNITEXAMPLE_H

#include "lib.h"
#include <stdint.h>

typedef struct
{
    struct {
        lib_fooA_t redirectFuncPtr;
    } fooA;
} lib_t3;

extern lib_fooA_t funcPtr;
extern uint8_t variable;

int UnitExample(int a, int b);

lib_t3 func(void);

#endif // UNITEXAMPLE_H