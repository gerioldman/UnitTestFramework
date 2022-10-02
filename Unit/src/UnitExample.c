
#include "lib.h"
#include "UnitExample.h"
#include <stdint.h>

lib_fooA_t funcPtr;
uint16_t variable;

int UnitExample(int a, int b)
{
    if (a > 10u){
        return a + b;
    }
    else{
        return a - b;
    }
}

lib_t func(void)
{
    lib_t lib = {
        .a = 0,
        .b = 0
    };
    return lib;
}