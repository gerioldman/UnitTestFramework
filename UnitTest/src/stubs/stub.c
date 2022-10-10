/**
* @file stub.c
*
* @brief This file contains the stubs for the functions
*
*/
#include "types.h"
#include "stub.h"
#include "lib.h"
#include "UnitExample.h"
TEST_STUB_TYPE TEST_STUB;
void fooA()
{
  TEST_STUB.fooA.callcount++;
  switch (TEST_STUB.fooA.stub_option)
  {
    case STUB_OPTION_VALUE:
      break;

    case STUB_OPTION_REDIRECT:
      TEST_STUB.fooA.redirectFuncPtr();
      break;

    default:
      break;

  }

}

void fooB(void)
{
  TEST_STUB.fooB.callcount++;
  switch (TEST_STUB.fooB.stub_option)
  {
    case STUB_OPTION_VALUE:
      break;

    case STUB_OPTION_REDIRECT:
      TEST_STUB.fooB.redirectFuncPtr();
      break;

    default:
      break;

  }

}

int fooC(int a, int b)
{
  int returnValue;
  TEST_STUB.fooC.callcount++;
  switch (TEST_STUB.fooC.stub_option)
  {
    case STUB_OPTION_VALUE:
      returnValue = TEST_STUB.fooC.returnValue;
      TEST_STUB.fooC.a = a;
      TEST_STUB.fooC.b = b;
      break;

    case STUB_OPTION_REDIRECT:
      returnValue = TEST_STUB.fooC.redirectFuncPtr(a, b);
      break;

    default:
      break;

  }

  return returnValue;
}

float fooD()
{
  float returnValue;
  TEST_STUB.fooD.callcount++;
  switch (TEST_STUB.fooD.stub_option)
  {
    case STUB_OPTION_VALUE:
      returnValue = TEST_STUB.fooD.returnValue;
      break;

    case STUB_OPTION_REDIRECT:
      returnValue = TEST_STUB.fooD.redirectFuncPtr();
      break;

    default:
      break;

  }

  return returnValue;
}

lib_t fooE()
{
  lib_t returnValue;
  TEST_STUB.fooE.callcount++;
  switch (TEST_STUB.fooE.stub_option)
  {
    case STUB_OPTION_VALUE:
      returnValue = TEST_STUB.fooE.returnValue;
      break;

    case STUB_OPTION_REDIRECT:
      returnValue = TEST_STUB.fooE.redirectFuncPtr();
      break;

    default:
      break;

  }

  return returnValue;
}

int TEST_CALL_UnitExample(int a, int *b)
{
  TEST_STUB.UnitExample.callcount++;
  return UnitExample(a, b);
}

lib_t3 TEST_CALL_func(void)
{
  TEST_STUB.func.callcount++;
  return func();
}

