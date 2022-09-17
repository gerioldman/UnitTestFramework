/**
 * @file UnitTestFramework.c
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "UnitTestFramework.h"


/**
 * @brief
 *
 */
void RunAllTests_Screen(void)
{
    LogMode = LOG_SCREEN;
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        printf("Executing TestSuite: %s\n", testSuites[i]->name);
        for (int j = 0; (testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            printf("Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
}

void RunAllTests_Curses(void)
{
    LogMode = LOG_CURSES;
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        attron(COLOR_PAIR(3));
        printw("Executing TestSuite: %s\n", testSuites[i]->name);
        attroff(COLOR_PAIR(3));
        refresh();
        for (int j = 0; (testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            attron(COLOR_PAIR(4));
            printw("Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            attroff(COLOR_PAIR(4));
            refresh();
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
    getch();
    endwin();
}

void RunAllTests_File(void)
{
    LogMode = LOG_FILE;
    LogFile = fopen("test.txt", "w");
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        fprintf(LogFile, "Executing TestSuite: %s\n", testSuites[i]->name);
        for (int j = 0; (testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            fprintf(LogFile, "Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
    fclose(LogFile);
}

void RunAllTests_ScreenAndFile(void)
{
    LogMode = LOG_SCREEN_AND_FILE;
    LogFile = fopen("test.txt", "w");
    // Run all tests
    for (int i = 0; testSuites[i] != TEST_SUITE_END; i++)
    {
        printf("Executing TestSuite: %s\n", testSuites[i]->name);
        fprintf(LogFile, "Executing TestSuite: %s\n", testSuites[i]->name);
        for (int j = 0; (testSuites[i])->TestCases[j].funct_ptr != TEST_CASE_END; j++)
        {
            printf("Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            fprintf(LogFile, "Executing TestCase: %s\n", (testSuites[i])->TestCases[j].name);
            (testSuites[i])->TestCases[j].funct_ptr();
        }
    }
    fclose(LogFile);
}

void CursesMenu(void)
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menu_win = newwin(10, 40, yMax / 2 - 5, xMax / 2 - 20);
    box(menu_win, 0, 0);
    refresh();
    wrefresh(menu_win);

    keypad(menu_win, TRUE);

    char *choices[] = {
        "Run all tests on screen",
        "Run all tests on screen and file",
        "Run all tests on curses",
        "Run all tests on file",
        "Run specific TestSuite",
        "Exit",
    };

    int choice;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == highlight)
            {
                wattron(menu_win, A_REVERSE);
            }
            mvwprintw(menu_win, i + 1, 1, choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
        choice = wgetch(menu_win);
        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_A2:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 6)
                highlight = 5;
            break;
        case KEY_C2:
            highlight++;
            if (highlight == 6)
                highlight = 5;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    switch (highlight)
    {
    case 0:
        RunAllTests_Screen();
        break;
    case 1:
        RunAllTests_ScreenAndFile();
        break;
    case 2:
        RunAllTests_Curses();
        break;
    case 3:
        RunAllTests_File();
        break;
    case 4:
        //RunSpecificTestSuite();
        break;
    }

    endwin();
}