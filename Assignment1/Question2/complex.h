#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _complex * complex;

struct _complex
{
    int t;//dimension
    float *head;
};

void print(complex a);
complex input(int d);
complex add(complex a , complex b);
complex sub(complex a , complex b);
float mod (complex a);
float square_root(float sum);
float dot(complex a,complex b);
float COS(complex a, complex b);

#endif