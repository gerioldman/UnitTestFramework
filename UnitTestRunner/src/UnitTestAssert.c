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

// Global variables
AssertMode_Type AssertMode = PRINT_FAILED_ASSERT;
ColourMode_Type ColourMode = NO_COLOUR;
LogMode_Type LogMode = LOG_SCREEN;
#if defined(__WIN64__) || defined(__WIN32__)
FILE *LogFile;
#endif

void SetModifier(ModifierCode modifier)
{
    if (ColourMode == COLOUR)
    {
        printf("\x1b[%dm", modifier);
    }
}

void SetForegroundColour(ForegroundColourCode colour)
{
    if (ColourMode == COLOUR)
    {
        printf("\x1b[%dm", colour);
    }
}
void SetBackgroundColour(BackgroundColourCode colour)
{
    if (ColourMode == COLOUR)
    {
        printf("\x1b[%dm", colour);
    }
}

void ResetColour(void)
{
    if (ColourMode == COLOUR)
    {
        printf("\x1b[0m");
    }
}

void AssertPrint(boolean condition, char *format, char *file, int line, char *message)
{
    if (FALSE == condition || PRINT_EVERY_ASSERT == AssertMode)
    {
        switch (LogMode)
        {
            case LOG_SCREEN:
                if (condition)
                {
                    SetModifier(BOLD);
                    SetForegroundColour(BG_BRIGHTGREEN);
                    printf_s(format, file, line, message);
                    ResetColour();
                }
                else
                {
                    SetModifier(BOLD);
                    SetForegroundColour(BG_BRIGHTRED);
                    printf_s(format, file, line, message);
                    ResetColour();
                }
                break;
#if defined(__WIN64__) || defined(__WIN32__)
            case LOG_FILE:
                fprintf(LogFile, format, file, line, message);
                break;

            case LOG_SCREEN_AND_FILE:
                if (condition)
                {
                    SetModifier(BOLD);
                    SetForegroundColour(BG_BRIGHTGREEN);
                    printf_s(format, file, line, message);
                    ResetColour();
                }
                else
                {
                    SetModifier(BOLD);
                    SetForegroundColour(BG_BRIGHTRED);
                    printf_s(format, file, line, message);
                    ResetColour();
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
    AssertPrint(condition, "%s:%d: %s\n", file, line, message);
}
