#ifndef LIB_H
#define LIB_H

typedef struct {
    int a;
    int b;
} lib_t;

typedef lib_t (*lib_fooA_t)(void);

void fooA();
void fooB();
int fooC();
float fooD();
lib_t fooE();

#endif