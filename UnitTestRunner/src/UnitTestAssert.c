/**
 * @file UnitTestAssert.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "UnitTestAssert.h"

void AssertImplementation(boolean condition, char* message, char* file, int line)
{
    if (condition == FALSE)
    {
        printf(" |_\e[1;31m%s:%d: %s\e[0m\n", file, line, message);
    }
}
