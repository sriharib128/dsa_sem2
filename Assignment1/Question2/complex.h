#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _complex * complex_P ;

struct _complex
{
    int t;//dimension
    float *head;
};

void print(complex_P a);
complex_P input(int d);
complex_P add(complex_P a , complex_P b);
complex_P sub(complex_P a , complex_P b);
float mod (complex_P a);
float square_root(float sum);
float dot(complex_P a,complex_P b);
float COS(complex_P a, complex_P b);

#endif