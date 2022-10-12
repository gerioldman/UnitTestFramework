/**
 * @file main.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief Proccesses the command line arguments and runs the test suites.
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "UnitTestFramework.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        RunAllTests_Screen();
    }
    else
    {
        unsigned char argi = 1;
        while (argi < argc)
        {
            if (strcmp(argv[argi], "-a") == 0)
            {
                AssertMode = PRINT_EVERY_ASSERT;
            }
            else if (strcmp(argv[argi], "--colour") == 0)
            {
                ColourMode = COLOUR;
            }
            else if (strcmp(argv[argi], "-s") == 0)
            {
                RunAllTests_Screen();
            }
            else if (strcmp(argv[argi], "-f") == 0)
            {
                RunAllTests_File();
            }
            else if (strcmp(argv[argi], "-fs") == 0)
            {
                RunAllTests_ScreenAndFile();
            }
            else
            {
                printf("\x1b[1;31mRun Mode incorrect. Please specify a correct runmode.\x1b[0m\n\
                                1. Log to screen:\t\t-s\n\
                                3. Log to file:\t\t-f\n\
                                4. Log to file and screen:\t-fs\n");
            }
            argi++;
        }
    }
    return 0;
}
