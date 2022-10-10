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
    int expected = 3;
    TEST_STUB.fooC.stub_option = STUB_OPTION_REDIRECT;
    TEST_STUB.fooC.redirectFuncPtr = fooC_userstub;
    int actual = TEST_CALL_UnitExample(a,&b);
    ASSERT_EQUAL(TEST_STUB.UnitExample.callcount, 1);
    ASSERT_EQUAL(actual, expected);
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