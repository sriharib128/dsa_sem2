#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int ElementType;
typedef struct HeapStruct* heap;//Priority Queue

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

ElementType minimum(ElementType a, ElementType b);
ElementType maximum(ElementType a, ElementType b);

heap Initialize(int MaxElements);
void Insert(heap H,ElementType a);
void AdjustHeap(heap H, int pos);
ElementType DeleteMin(heap H);
void printHeap(heap H);
void swap(ElementType* a, ElementType* B);

// void destroy(heap H);
// void MakeEmpty(heap H);
// ElementType FindMin (heap H);
// int IsEmpty(heap H);
// int IsFull(heap H);
#endif