#ifndef _DQUEU_H
#define _DQUEU_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stDQueue * Dq;

struct stDQueue{
    long long int size;
    long long int Front;
    long long int Rear;
    long long int * QArr;
};

long long int PopFront(Dq Q);
long long int PopBack(Dq Q);
long long int PushFront(Dq Q , long long int a);
long long int PushBack(Dq Q , long long int a);
long long int Front(Dq Q);
long long int Back(Dq Q);
int isEmpty(Dq Q);
long long int Size(Dq Q);

#endif