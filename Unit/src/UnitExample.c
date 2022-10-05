
#include "lib.h"
#include "UnitExample.h"
#include <stdint.h>

lib_fooA_t funcPtr;
uint16_t variable;


int UnitExample(int a, int *b)
{
    if (a > 10u){
        return a + *b;
    }
    else{
        return a - *b;
    }
}

lib_t3 func(void)
{
    lib_t3 lib3 = {
        .fooA = {
            .redirectFuncPtr = 0
        }
    };

    UnitExample(1, &variable);

    unsigned char value = 0;

    switch ( value )
    {
    case 0:
        /* code */
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    
    default:
        break;
    }

    return lib3;
}