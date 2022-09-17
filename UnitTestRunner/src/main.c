/**
 * @file main.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "UnitTestFramework.h"

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        CursesMenu();
    }
    else{
        unsigned char argi = 2;
        while (argi < argc)
        {
            if(strcmp(argv[argi],"-a")==0) 
            {
                AssertMode = PRINT_EVERY_ASSERT;
            }
            else if(strcmp(argv[argi],"--colour")==0){
                ColourMode = COLOUR;
            }
            argi++;
        }
        if(strcmp(argv[1],"-m")==0){
            CursesMenu();
        }
        if(strcmp(argv[1],"-s")==0){
            RunAllTests_Screen();
        }
        else if(strcmp(argv[1],"-c")==0){
            RunAllTests_Curses();
        }
        else if(strcmp(argv[1],"-f")==0){
            RunAllTests_File();
        }
        else if(strcmp(argv[1],"-fs")==0){
            RunAllTests_ScreenAndFile();
        }
        else{
            printf("\x1b[1;31mRun Mode incorrect. Please specify a correct runmode.\x1b[0m\n\
            1. Log to screen:\t\t-s\n\
            2. Curses mode:\t\t-c\n\
            3. Log to file:\t\t-f\n\
            4. Log to file and screen:\t-fs\n");
        }
    }
    return 0;
}
