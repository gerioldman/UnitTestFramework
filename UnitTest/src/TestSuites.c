/**
 * @file TestSuites.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "TestSuites.h"

/**
 * @brief 
 * 
 */
TestSuite* testSuites[] = {
    &TestSuite1,
    &TestSuite2,
    &TestSuite3,
    TEST_SUITE_END
};

/**
 * @brief 
 * 
 */
void cleanUpBefore(void)
{

}

/**
 * @brief 
 * 
 */
void cleanUpAfter(void)
{
    
}