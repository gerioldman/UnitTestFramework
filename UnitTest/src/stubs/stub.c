/**
* @file stub.c
*
* @brief This file contains the stubs for the functions
*
*/
#include "types.h"
#include "lib.h"
#include "UnitExample.h"
TEST_STUB_TYPE TEST_STUB;
void fooA()
{
  TEST_STUB.fooA.callcount++;
  switch (TEST_STUB.fooA.stub_option)
  {
    case STUB_OPTION_VALUE:

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

    case STUB_OPTION_REDIRECT:
      TEST_STUB.fooB.redirectFuncPtr();
      break;

    default:
      break;

  }

}

int fooC()
{
  TEST_STUB.fooC.callcount++;
  switch (TEST_STUB.fooC.stub_option)
  {
    case STUB_OPTION_VALUE:

    case STUB_OPTION_REDIRECT:
      return TEST_STUB.fooC.redirectFuncPtr();
      break;

    default:
      break;

  }

}

float fooD()
{
  TEST_STUB.fooD.callcount++;
  switch (TEST_STUB.fooD.stub_option)
  {
    case STUB_OPTION_VALUE:

    case STUB_OPTION_REDIRECT:
      return TEST_STUB.fooD.redirectFuncPtr();
      break;

    default:
      break;

  }

}

lib_t fooE()
{
  TEST_STUB.fooE.callcount++;
  switch (TEST_STUB.fooE.stub_option)
  {
    case STUB_OPTION_VALUE:

    case STUB_OPTION_REDIRECT:
      return TEST_STUB.fooE.redirectFuncPtr();
      break;

    default:
      break;

  }

}

int TEST_CALL_UnitExample(int a, int *b)
{
  TEST_STUB.UnitExample.callcount++;
  switch (TEST_STUB.UnitExample.stub_option)
  {
    case STUB_OPTION_VALUE:
      TEST_STUB.UnitExample.a = a;
      if (TEST_STUB.UnitExample.b.stub_pArg_option == STUB_OPTION_PARG_COPY_TO)
    {
    }

    case STUB_OPTION_REDIRECT:
      return TEST_STUB.UnitExample.redirectFuncPtr(a, b);
      break;

    default:
      break;

  }

}

lib_t3 TEST_CALL_func(void)
{
  TEST_STUB.func.callcount++;
  switch (TEST_STUB.func.stub_option)
  {
    case STUB_OPTION_VALUE:

    case STUB_OPTION_REDIRECT:
      return TEST_STUB.func.redirectFuncPtr();
      break;

    default:
      break;

  }

}

