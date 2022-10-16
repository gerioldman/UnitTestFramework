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
TEST_STUB_TYPE TEST_STUB = {0};
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

void fooF(int array[5])
{
  TEST_STUB.fooF.callcount++;
  switch (TEST_STUB.fooF.stub_option)
  {
    case STUB_OPTION_VALUE:
      if (TEST_STUB.fooF.array.stub_pArg_option == STUB_OPTION_PARG_COPY_TO)
    {
      for (int i = 0; i < 5; ++i)
      {
        array[i] = TEST_STUB.fooF.array.value[i];
      }

    }
    else
    {
      if (TEST_STUB.fooF.array.stub_pArg_option == STUB_OPTION_PARG_COPY_FROM)
      {
        for (int i = 0; i < 5; ++i)
        {
          TEST_STUB.fooF.array.value[i] = array[i];
        }

      }
    }
      break;

    case STUB_OPTION_REDIRECT:
      TEST_STUB.fooF.redirectFuncPtr(array);
      break;

    default:
      break;

  }

}

float fooZS(float a, float b, lib_t *(*foo)(void))
{
  float returnValue;
  TEST_STUB.fooZS.callcount++;
  switch (TEST_STUB.fooZS.stub_option)
  {
    case STUB_OPTION_VALUE:
      returnValue = TEST_STUB.fooZS.returnValue;
      TEST_STUB.fooZS.a = a;
      TEST_STUB.fooZS.b = b;
      TEST_STUB.fooZS.foo = foo;
      break;

    case STUB_OPTION_REDIRECT:
      returnValue = TEST_STUB.fooZS.redirectFuncPtr(a, b, foo);
      break;

    default:
      break;

  }

  return returnValue;
}

int TEST_CALL_UnitExample(int a, int b)
{
  TEST_STUB.UnitExample.callcount++;
  return UnitExample(a, b);
}

lib_t3 TEST_CALL_func(void)
{
  TEST_STUB.func.callcount++;
  return func();
}

