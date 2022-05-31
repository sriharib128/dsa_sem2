#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct HeapStruct* heap;//Priority Queue

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

heap Initialize(int MaxElemets);
void destroy(heap H);
void MakeEmpty(heap H);
void Insert(heap H);
ElementType DeleteMin(heap H);
ElementType FindMin (heap H);
int IsEmpty(heap H);
int IsFull(heap H);

#endif