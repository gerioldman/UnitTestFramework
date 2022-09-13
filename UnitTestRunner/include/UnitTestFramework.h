/**
 * @file UnitTestFramework.h
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UNITTESTFRAMEWORK_H
#define UNITTESTFRAMEWORK_H
#include "TestSuites.h"
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "UnitTestAssert.h"

void RunAllTests_Screen(void);
void RunAllTests_File(void);
void RunAllTests_Curses(void);
void RunAllTests_ScreenAndFile(void);
void CursesMenu(void);

#endif // UNITTESTFRAMEWORK_H