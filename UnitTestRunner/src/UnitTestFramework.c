/**
 * @file UnitTestFramework.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "UnitTestFramework.h"

void RunAllTests(void)
{
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        printf("Executing TestSuite: %s\n",testSuites[i]->name);
        for (int j = 0;(testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            printf("Executing TestCase: %s\n",(testSuites[i])->TestCases[j].name);
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
}