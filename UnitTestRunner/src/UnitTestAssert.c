/**
 * @file UnitTestAssert.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "UnitTestAssert.h"
#include "curses.h"

void AssertImplementation(boolean condition, char* message, char* file, int line)
{
    if (condition == FALSE)
    {
        attron(COLOR_PAIR(1));
        printw("%s:%d: %s\n", file, line, message);
        attroff(COLOR_PAIR(1));
        refresh();
    }
}
