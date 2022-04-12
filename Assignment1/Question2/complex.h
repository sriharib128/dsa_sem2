#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int dimensions;
typedef struct _complex * complex;

struct _complex
{
    dimensions t;//dimension
    complex *head;
};

//typedef struct linkedlist ll;
typedef struct linkedlist * ll_p;

struct  linkedlist
{
    double value;
    ll_p* next;
};

complex add(complex a , complex b);
complex sub(complex a , complex b);
complex mod (complex a);
complex dot(complex a,complex b);
complex cos(complex a, complex b);

#endif