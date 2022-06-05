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

heap Initialize(int MaxElements);
void destroy(heap H);
void MakeEmpty(heap H);
void Insert(heap H,ElementType a);
ElementType DeleteMin(heap H);
ElementType FindMin (heap H);
int IsEmpty(heap H);
int IsFull(heap H);
void printHeap(heap H);
void AdjustHeap(heap H, int pos);
void swap(ElementType* a, ElementType* B);
#endif