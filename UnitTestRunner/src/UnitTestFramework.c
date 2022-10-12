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


/**
 * @brief
 *
 */
void RunAllTests_Screen(void)
{
    LogMode = LOG_SCREEN;
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        printf("├─Executing TestSuite: %s\n", testSuites[i]->name);
        for (int j = 0; (testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            printf("│ ├─Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
}


void RunAllTests_File(void)
{
    LogMode = LOG_FILE;
    LogFile = fopen("test.txt", "w");
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        fprintf(LogFile, "├─Executing TestSuite: %s\n", testSuites[i]->name);
        for (int j = 0; (testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            fprintf(LogFile, "│ ├─Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
    fclose(LogFile);
}

void RunAllTests_ScreenAndFile(void)
{
    LogMode = LOG_SCREEN_AND_FILE;
    LogFile = fopen("test.txt", "w");
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        printf("├─Executing TestSuite: %s\n", testSuites[i]->name);
        fprintf(LogFile, "├─Executing TestSuite: %s\n", testSuites[i]->name);
        for (int j = 0; (testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            printf("│ ├─Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            fprintf(LogFile, "│ ├─Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
    fclose(LogFile);
}
