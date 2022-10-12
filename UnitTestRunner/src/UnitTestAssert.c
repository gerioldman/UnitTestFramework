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
#include <stdio.h>

AssertMode_Type AssertMode = PRINT_FAILED_ASSERT;
#if defined(__WIN64__) || defined(__WIN32__)
ColourMode_Type ColourMode = NO_COLOUR;
LogMode_Type LogMode = LOG_SCREEN;
FILE *LogFile;
#endif

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
#if defined(__WIN64__) || defined(__WIN32__)
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
#endif
            default:
                break;
        }
    }
}

void AssertImplementation(boolean condition, char *message, char *file, int line)
{
    AssertPrint(condition, "│ │ └─%s:%d: %s\n", file, line, message);
}
