/**
 * @file UnitTestAssert.h
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UNITTESTASSRT_H
#define UNITTESTASSRT_H

#include <stdio.h>

typedef unsigned char   boolean;
#define TRUE            1
#define FALSE           0

#define ASSERT_EQUAL(expected, actual) \
        AssertImplementation((expected) == (actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__)

#define ASSERT_NOT_EQUAL(expected, actual) \
        AssertImplementation((expected) != (actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__)

#define ASSERT_NULL(pointer) \
        AssertImplementation((pointer) == NULL,"error: (pointer:"#pointer")",__FILE__,__LINE__)

#define ASSERT_NOT_NULL(pointer) \
        AssertImplementation((pointer) != NULL,"error: (pointer:"#pointer")",__FILE__,__LINE__)

#define ASSERT_TRUE(condition) \
        AssertImplementation((condition) == TRUE,"error: (condition:"#condition")",__FILE__,__LINE__)

#define ASSERT_FALSE(condition) \
        AssertImplementation((condition) == FALSE,"error: (condition:"#condition")",__FILE__,__LINE__)




void AssertImplementation(boolean condition, char* message, char* file, int line);

#endif