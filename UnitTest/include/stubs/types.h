#ifndef TYPES_H
#define TYPES_H

typedef struct 
{
  int a;
  int b;
  float (*funcPtr)(int a, int b);
} lib_t;
typedef lib_t (*lib_fooA_t)(void);
typedef struct 
{
  unsigned long callcount;
  void (*redirectFuncPtr)();
} TEST_STUB_fooA_TYPE;
typedef struct 
{
  unsigned long callcount;
  void (*redirectFuncPtr)(void);
} TEST_STUB_fooB_TYPE;
typedef struct 
{
  unsigned long callcount;
  int returnValue;
  int (*redirectFuncPtr)();
} TEST_STUB_fooC_TYPE;
typedef struct 
{
  unsigned long callcount;
  float returnValue;
  float (*redirectFuncPtr)();
} TEST_STUB_fooD_TYPE;
typedef struct 
{
  unsigned long callcount;
  lib_t returnValue;
  lib_t (*redirectFuncPtr)();
} TEST_STUB_fooE_TYPE;
typedef struct 
{
  unsigned long callcount;
  int returnValue;
  int a;
  int b;
  int (*redirectFuncPtr)(int a, int b);
} TEST_STUB_UnitExample_TYPE;
typedef struct 
{
  unsigned long callcount;
  lib_t returnValue;
  lib_t (*redirectFuncPtr)(void);
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