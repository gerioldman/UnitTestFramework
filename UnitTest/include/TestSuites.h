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

#define TEST_SUITE_END  0
#define TEST_CASE_END   0

typedef struct {
    const char* name;
    void (*funct_ptr)(void);
}TestCase;

typedef struct{
    const char* name;
    TestCase TestCases[];
}TestSuite;

extern TestSuite *testSuites[];

/* List TestSuites here */

extern TestSuite TestSuite1;
extern TestSuite TestSuite2;
extern TestSuite TestSuite3;

/* End of TestSuites */

#endif // TESTSUITES_H