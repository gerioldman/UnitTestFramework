/**
 * @file TestSuite2.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "TestSuites.h"


/**
 * @brief 
 * 
 */
void TS2_TestCase1(void)
{
    
}
/**
 * @brief 
 * 
 */
void TS2_TestCase2(void)
{
    
}

/**
 * @brief 
 * 
 */
void TS2_TestCase3(void)
{
    
}

TestSuite TestSuite2 = {
    .name = "TestSuite2",
    .TestCases =
    {
        {"TS2_TestCase1",TS2_TestCase1},
        {"TS2_TestCase2",TS2_TestCase2},
        {"TS2_TestCase3",TS2_TestCase3},
        {"TEST_CASE_END",TEST_CASE_END}
    }
};