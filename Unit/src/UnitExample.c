
#include "UnitExample.h"
#include "lib.h"

int UnitExample(int a, int b)
{
    if (a > 10u){
        return a + b;
    }
    else{
        return a - b;
    }
}