/**
 * @file main.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "UnitTestFramework.h"
#include <curses.h>

int main(int argc, char *argv[])
{
    // Run all tests
    printf("\x1b[32mRunning all tests\x1b[0m\n");
    RunAllTests();
    return 0;
}