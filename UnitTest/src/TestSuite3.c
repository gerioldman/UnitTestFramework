/**
 * @file TestSuite3.c
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
void TS3_TestCase1(void)
{
    
}
/**
 * @brief 
 * 
 */
void TS3_TestCase2(void)
{
    
}

/**
 * @brief 
 * 
 */
void TS3_TestCase3(void)
{
    
}

TestSuite TestSuite3 = {
    .name = "TestSuite3",
    .TestCases =
    {
        {"TS3_TestCase1",TS3_TestCase1},
        {"TS3_TestCase2",TS3_TestCase2},
        {"TS3_TestCase3",TS3_TestCase3},
        {"TEST_CASE_END",TEST_CASE_END}
    },
    .cleanUpBefore_funcPtr = cleanUpBefore,
    .cleanUpAfter_funcPtr = cleanUpAfter
};