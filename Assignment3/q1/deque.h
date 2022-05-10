#ifndef _DEQUE_H
#define _DEQUE_H

#include "bintree.h"

typedef struct dll* node;

struct dll{
    node prev;
    node next;
    tree data;
};

typedef struct stDQueue * Dq;

struct stDQueue{
    long long int size;
    node head;
    node tail;
};

Dq createStruct();
void PushBack(Dq Q , tree T);
tree PopFront(Dq Q);
tree Front(Dq Q);
int isEmpty(Dq Q);
long long int Size(Dq Q);

// long long int PopBack(Dq Q);
// void PushFront(Dq Q , tree T);
// long long int Back(Dq Q);
void print(Dq P);
// void print_reverse(Dq P);
#endif
