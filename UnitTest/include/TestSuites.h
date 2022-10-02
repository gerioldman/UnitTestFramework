/**
 * @file TestSuites.h
 * @author gerioldman (krisztian.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TESTSUITES_H
#define TESTSUITES_H

/* Includes */


/* Macros */

#define TEST_SUITE_END  0
#define TEST_CASE_END   0

/* Type Definitions */

typedef struct {
    const char* name;
    void (*funct_ptr)(void);
}TestCase;

typedef struct{
    const char* name;
    void (*cleanUpBefore_funcPtr)(void);
    void (*cleanUpAfter_funcPtr)(void);
    TestCase TestCases[];
}TestSuite;

extern TestSuite *testSuites[];

/* List TestSuites here */

extern TestSuite TestSuite1;
extern TestSuite TestSuite2;
extern TestSuite TestSuite3;

/* End of TestSuites */

/* Clean up functions */
void cleanUpBefore(void);
void cleanUpAfter(void);

#endif // TESTSUITES_H