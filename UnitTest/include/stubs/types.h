#ifndef TYPES_H
#define TYPES_H

typedef enum 
{
  LIB_OK = 0,
  LIB_ERROR = 1
} lib_t2;
typedef struct 
{
  int a;
  int b;
  float (*funcPtr)(int a, int b);
} lib_t;
typedef lib_t (*lib_fooA_t)(void);
typedef struct 
{
  struct 
  {
    lib_fooA_t redirectFuncPtr;
  } fooA;
} lib_t3;
typedef enum 
{
  STUB_OPTION_VALUE,
  STUB_OPTION_REDIRECT,
  STUB_OPTION_UNITCALL
} stub_option_t;
typedef enum 
{
  STUB_OPTION_PARG_COPY_FROM,
  STUB_OPTION_PARG_COPY_TO
} stub_pArg_option_t;
typedef struct 
{
  unsigned long callcount;
  stub_option_t stub_option;
  void (*redirectFuncPtr)();
} TEST_STUB_fooA_TYPE;
typedef struct 
{
  unsigned long callcount;
  stub_option_t stub_option;
  void (*redirectFuncPtr)(void);
} TEST_STUB_fooB_TYPE;
typedef struct 
{
  unsigned long callcount;
  stub_option_t stub_option;
  int returnValue;
  int (*redirectFuncPtr)();
} TEST_STUB_fooC_TYPE;
typedef struct 
{
  unsigned long callcount;
  stub_option_t stub_option;
  float returnValue;
  float (*redirectFuncPtr)();
} TEST_STUB_fooD_TYPE;
typedef struct 
{
  unsigned long callcount;
  stub_option_t stub_option;
  lib_t returnValue;
  lib_t (*redirectFuncPtr)();
} TEST_STUB_fooE_TYPE;
typedef struct 
{
  unsigned long callcount;
  stub_option_t stub_option;
  int returnValue;
  int a;
  struct 
  {
    int value;
    stub_pArg_option_t stub_pArg_option;
  } b;
  int (*redirectFuncPtr)(int a, int *b);
} TEST_STUB_UnitExample_TYPE;
typedef struct 
{
  unsigned long callcount;
  stub_option_t stub_option;
  lib_t3 returnValue;
  lib_t3 (*redirectFuncPtr)(void);
} TEST_STUB_func_TYPE;
typedef struct 
{
  TEST_STUB_fooA_TYPE fooA;
  TEST_STUB_fooB_TYPE fooB;
  TEST_STUB_fooC_TYPE fooC;
  TEST_STUB_fooD_TYPE fooD;
  TEST_STUB_fooE_TYPE fooE;
  TEST_STUB_UnitExample_TYPE UnitExample;
  TEST_STUB_func_TYPE func;
} TEST_STUB_TYPE;
extern TEST_STUB_TYPE TEST_STUB;

#endif /* TYPES_H */