/**
 * @file UnitTestFrame.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "UnitTestFramework.h"

void RunAllTests(void){
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        testSuites[i]();
    }
}