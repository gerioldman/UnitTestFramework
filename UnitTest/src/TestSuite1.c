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

#include "TestSuites.h"
#include "UnitTestAssert.h"
#include "stub.h"
#include "stdint.h"

static int fooC_userstub(int a, int b){
    return a + 2 * b;
}

/**
 * @brief 
 * 
 */
void TS1_TestCase1(void)
{
    int a = 1;
    int b = 2;
    int expectedResult = 15;
    TEST_STUB.fooC.stub_option = STUB_OPTION_REDIRECT;
    TEST_STUB.fooC.redirectFuncPtr = fooC_userstub;
    int result = TEST_CALL_UnitExample(a,b);
    ASSERT_HEX8_EQUAL(TEST_STUB.UnitExample.callcount, 1u);
    ASSERT_HEX8_EQUAL(expectedResult, result);
}

/**
 * @brief 
 * 
 */
void TS1_TestCase2(void)
{
    float a = 1.0f;
    float b = 2.0f;

    float expectedResult = 3.0f;
    float tolerance = 0.0001f;

    ASSERT_FLOAT(a+b,expectedResult,tolerance);   
}

/**
 * @brief 
 * 
 */
void TS1_TestCase3(void)
{
    
}


TestSuite TestSuite1 = {
    .name = "UnitExample",
    .TestCases =
    {
        {"TS1_TestCase1",TS1_TestCase1},
        {"TS1_TestCase2",TS1_TestCase2},
        {"TS1_TestCase3",TS1_TestCase3},
        {"TEST_CASE_END",TEST_CASE_END}
    },
    .cleanUpBefore_funcPtr = cleanUpBefore,
    .cleanUpAfter_funcPtr = cleanUpAfter
};