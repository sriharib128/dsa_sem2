#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_struct* Stack;

struct stack_struct {
    long long  int top;
    long long int size;
    long long int *array;
};
long long int Pop(Stack S);
void Push(Stack S,long long int a);
long long int Top(Stack S);
int isEmpty (Stack S);
long long int Size(Stack S);
#endif
