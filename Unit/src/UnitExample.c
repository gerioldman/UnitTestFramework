
#include "lib.h"
#include "UnitExample.h"
#include <stdint.h>

lib_fooA_t funcPtr;
int variable;


int UnitExample(int a, int *b)
{
    return fooC(a, *b);
}

lib_t3 func(void)
{
    lib_t3 returnValue = {
        .fooA = {
            .redirectFuncPtr = fooE
        }
    };
    return returnValue;
}