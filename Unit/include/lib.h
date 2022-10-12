#ifndef LIB_H
#define LIB_H

typedef enum{
    LIB_OK = 0,
    LIB_ERROR = 1
}lib_t2;


typedef struct {
    int a;
    int b;
} lib_t;

typedef lib_t (*lib_fooA_t)(void);

void fooA();
void fooB(void);
int fooC(int a,int b);
float fooD();
lib_t fooE();
void fooF(int array[5]);

float fooZS(float a , float b, lib_t *(*foo)(void));

#endif