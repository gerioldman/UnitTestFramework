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
#include <stdint.h>

typedef enum{
    LOG_SCREEN,
    LOG_FILE,
    LOG_SCREEN_AND_FILE
}LogMode_Type;

typedef enum{
    PRINT_EVERY_ASSERT,
    PRINT_FAILED_ASSERT
}AssertMode_Type;

typedef enum{
    COLOUR,
    NO_COLOUR
}ColourMode_Type;

typedef enum
{
	BG_RESET = 0,
	BG_BLACK = 30,
	BG_RED = 31,
	BG_GREEN = 32,
	BG_YELLOW= 33,
	BG_BLUE= 34,
	BG_MAGENTA= 35, 
	BG_CYAN= 36,
	BG_WHITE= 37,
        BG_DEFAULT = 39,
	BG_BRIGHTBLACK= 90,
	BG_BRIGHTRED = 91,
	BG_BRIGHTGREEN= 92,
	BG_BRIGHTYELLOW= 93,
	BG_BRIGHTBLUE= 94,
	BG_BRIGHTMAGENTA= 95, 
	BG_BRIGHTCYAN= 96,
	BG_BRIGHTWHITE= 97
}BackgroundColourCode;

typedef enum
{
	FG_RESET = 0,
	FG_BLACK = 40,
	FG_RED = 41,
	FG_GREEN = 42,
	FG_YELLOW= 43,
	FG_BLUE= 44,
	FG_MAGENTA= 45, 
	FG_CYAN= 46,
	FG_WHITE= 47,
        FG_DEFAULT = 49,
	FG_BRIGHTBLACK= 100,
	FG_BRIGHTRED = 101,
	FG_BRIGHTGREEN= 102,
	FG_BRIGHTYELLOW= 103,
	FG_BRIGHTBLUE= 104,
	FG_BRIGHTMAGENTA= 105, 
	FG_BRIGHTCYAN= 106,
	FG_BRIGHTWHITE= 107
}ForegroundColourCode;

typedef enum{
    RESET = 0,
    BOLD = 1,
    DIM = 2,
    ITALIC = 3,
    UNDERLINE = 4,
    BLINK = 5,
    INVERSE = 7,
    HIDDEN = 8,
    STRIKETHROUGH = 9
}ModifierCode;

extern LogMode_Type LogMode;
extern AssertMode_Type AssertMode;
extern ColourMode_Type ColourMode;
extern FILE *LogFile;

typedef unsigned char   boolean;
#define TRUE            1
#define FALSE           0

#define ASSERT_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation((expected) == (actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation((expected) == (actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_NOT_EQUAL(expected, actual) \
        if(expected != actual) \
        { \
                AssertImplementation((expected) != (actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation((expected) != (actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_INT8_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((int8_t)expected) == ((int8_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((int8_t)expected) == ((int8_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_INT16_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((int16_t)expected) == ((int16_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((int16_t)expected) == ((int16_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_INT32_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((int32_t)expected) == ((int32_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((int32_t)expected) == ((int32_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_INT64_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((int64_t)expected) == ((int64_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((int64_t)expected) == ((int64_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_UINT8_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((uint8_t)expected) == ((uint8_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((uint8_t)expected) == ((uint8_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_UINT16_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((uint16_t)expected) == ((uint16_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((uint16_t)expected) == ((uint16_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_UINT32_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((uint32_t)expected) == ((uint32_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((uint32_t)expected) == ((uint32_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

#define ASSERT_UINT64_EQUAL(expected, actual) \
        if(expected == actual) \
        { \
                AssertImplementation(((uint64_t)expected) == ((uint64_t)actual),"note: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        } \
        else \
        { \
                AssertImplementation(((uint64_t)expected) == ((uint64_t)actual),"error: (expected:"#expected", actual:"#actual")",__FILE__,__LINE__); \
        }

void AssertImplementation(boolean condition, char* message, char* file, int line);

void SetModifier(ModifierCode modifier);
void SetForegroundColour(ForegroundColourCode colour);
void SetBackgroundColour(BackgroundColourCode colour);
void ResetColour(void);

#endif