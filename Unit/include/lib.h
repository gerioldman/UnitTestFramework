#ifndef LIB_H
#define LIB_H

typedef struct {
    int a;
    int b;
    float (*funcPtr)(int a, int b);
} lib_t;

typedef lib_t (*lib_fooA_t)(void);

void fooA();
void fooB(void);
int fooC();
float fooD();
lib_t fooE();

#endif