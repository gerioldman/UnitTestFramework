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
#include "UnitTestAssert.h"


/**
 * @brief 
 * 
 */
void TS1_TestCase1(void)
{
    ASSERT_EQUAL(0, 1);
}
/**
 * @brief 
 * 
 */
void TS1_TestCase2(void)
{
    ASSERT_EQUAL(1, 1);
}

/**
 * @brief 
 * 
 */
void TS1_TestCase3(void)
{
    ASSERT_EQUAL(10, 0);
    ASSERT_EQUAL(0, 1);
    ASSERT_EQUAL(1, 2);
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