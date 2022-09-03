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

#define TEST_SUITE_END 0

typedef void (*TestSuite)(void);

extern TestSuite testSuites[];

/* List TestSuites here */

extern void TestSuite1(void);
extern void TestSuite2(void);
extern void TestSuite3(void);

/* End of TestSuites */

#endif // TESTSUITES_H