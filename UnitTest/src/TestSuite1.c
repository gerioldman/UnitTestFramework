/**
 * @file TestSuite1.c
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
void TS1_TestCase1(void)
{
    
}
/**
 * @brief 
 * 
 */
void TS1_TestCase2(void)
{
    
}

/**
 * @brief 
 * 
 */
void TS1_TestCase3(void)
{
    
}


TestSuite TestSuite1 = {
    .name = "TestSuite1",
    .TestCases =
    {
        {"TS1_TestCase1",TS1_TestCase1},
        {"TS1_TestCase2",TS1_TestCase2},
        {"TS1_TestCase3",TS1_TestCase3},
        {"TEST_CASE_END",TEST_CASE_END}
    }
};