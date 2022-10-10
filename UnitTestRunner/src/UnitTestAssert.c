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
#include <stdio.h>

LogMode_Type LogMode = LOG_SCREEN;
AssertMode_Type AssertMode = PRINT_FAILED_ASSERT;
ColourMode_Type ColourMode = NO_COLOUR;
FILE *LogFile;

void AssertPrint(boolean condition, char *format, char *file, int line, char *message)
{
    if (FALSE == condition || PRINT_EVERY_ASSERT == AssertMode)
    {
        switch (LogMode)
        {
            case LOG_SCREEN:
                if (TRUE == condition)
                {
                    if(COLOUR == ColourMode) printf("\x1b[1;32m");
                    printf_s(format, file, line, message);
                    if(COLOUR == ColourMode) printf("\x1b[0m");
                }
                else
                {
                    if(COLOUR == ColourMode) printf("\x1b[1;31m");
                    printf_s(format, file, line, message);
                    if(COLOUR == ColourMode) printf("\x1b[0m");
                }
                break;
            case LOG_FILE:
                fprintf(LogFile, format, file, line, message);
                break;
            case LOG_SCREEN_AND_FILE:
                if (TRUE == condition)
                {
                    if(COLOUR == ColourMode) printf("\x1b[1;32m");
                    printf_s(format, file, line, message);
                    if(COLOUR == ColourMode) printf("\x1b[0m");
                }
                else
                {
                    if(COLOUR == ColourMode) printf("\x1b[1;31m");
                    printf_s(format, file, line, message);
                    if(COLOUR == ColourMode) printf("\x1b[0m");
                }
                fprintf(LogFile, format, file, line, message);
                break;
            case LOG_CURSES:
                if (TRUE == condition)
                {
                    if(COLOUR == ColourMode) attron(COLOR_PAIR(1));
                    printw(format, file, line, message);
                    if(COLOUR == ColourMode) attroff(COLOR_PAIR(1));
                }
                else
                {
                    if(COLOUR == ColourMode) attron(COLOR_PAIR(2));
                    printw( format, file, line, message);
                    if(COLOUR == ColourMode) attroff(COLOR_PAIR(2));
                }
                refresh();
                break;
            default:
                break;
        }
    }
}

void AssertImplementation(boolean condition, char *message, char *file, int line)
{
    AssertPrint(condition, "│ │ └─%s:%d: %s\n", file, line, message);
}
