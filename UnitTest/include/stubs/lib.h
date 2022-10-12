#ifndef LIB_H
#define LIB_H

#include "types.h"
void fooA();
void fooB(void);
int fooC(int a, int b);
float fooD();
lib_t fooE();
void fooF(int array[5]);
float fooZS(float a, float b, lib_t *(*foo)(void));

#endif /* LIB_H */