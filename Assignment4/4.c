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

heap CreateHeap(int MaxElements);
void Insert(heap H,ElementType a);
void AdjustHeap(heap H, int pos);
ElementType DeleteMin(heap H);
void printHeap(heap H);
void swap(ElementType* a, ElementType* B);
int SizeOfHeap(heap H);
// void destroy(heap H);
// void MakeEmpty(heap H);
// ElementType FindMin (heap H);
// int IsEmpty(heap H);
// int IsFull(heap H);
#endif

// #include "heap.h"

ElementType minimum(ElementType a, ElementType b)
{
    if(a>=b)
        return b;
    return a;
}

ElementType maximum(ElementType a, ElementType b)
{
    if(a>=b)
        return a;
    return b;
}

void swap(ElementType* a, ElementType* b)
{
    ElementType temp = *a;
    *a = *b;
    *b = temp;
}
heap CreateHeap(int MaxElements)
{
    heap H = (heap)malloc(sizeof(struct HeapStruct ));
    H->Capacity = MaxElements+1;
    H->Elements = (ElementType *)malloc(sizeof(ElementType)*(MaxElements+1));
    H->Size = 0;
    return H;
}
int SizeOfHeap(heap H)
{
    return (H->Size);
}
void Insert(heap H,ElementType a)
{
    int i = H->Size;

    if(H->Size!=0)
    {
        while(H->Elements[(i-1)/2]>=a)
        {
            H->Elements[i]=H->Elements[(i-1)/2];
            i=(i-1)/2;
            if(i==0)
                break;
        }
    }
    H->Elements[i]=a;
    H->Size++;
    return ;
}

void AdjustHeap(heap H, int pos)
{
    if( (2*pos +2) >(H->Size-1))
    {
        if( (2*pos +1) >(H->Size-1))//NODE HAS NO CHILD
            return;
        else // NODE HAS ONE CHILD ONLY
        {
            if(H->Elements[pos]>H->Elements[2*pos +1])
                swap( &H->Elements[pos], &H->Elements[2*pos +1]);
            return;
        }
    }
    else//NODE HAS TWO CHILDREN
    {
        if(H->Elements[pos]>minimum(H->Elements[2*pos +2],H->Elements[2*pos +1]))
        {
            if(H->Elements[2*pos +2] > H->Elements[2*pos +1])
            {
                swap( &H->Elements[pos], &H->Elements[2*pos +1]);
                AdjustHeap(H,(2*pos +1));
                return;
            }
            else
            {
                swap( &H->Elements[pos], &H->Elements[2*pos +2]);
                AdjustHeap(H,(2*pos +2));
                return;
            }
        }
    }
    return ;
}

ElementType DeleteMin(heap H)
{
    if(H->Size==0)
        return INT_MIN;
    ElementType min=H->Elements[0];
    if(H->Size >=2)
    {   
        H->Elements[0]=H->Elements[H->Size-1];
        //adding last element in the hole and percolating it down
        H->Elements[H->Size-1]= INT_MAX;
        AdjustHeap(H,0);
    }
    H->Size--;
    return min;
}

void printHeap(heap H)
{
    printf(" ( %d %d ) ",H->Capacity,H->Size);
    for(int i=0;i<H->Size;i++ )
    {
        printf("%d ",H->Elements[i]);
    }
    // printf("\n");
}

// #include "heap.h"

int main()
{
    int L,D;
    scanf("%d",&L);
    scanf("%d",&D);
    heap H = CreateHeap(D);

    for(int i=0;i<D;i++)
    {
        int l;
        scanf("%d",&l);
        Insert(H,l);
    }
    long long int ans =0;
    while (SizeOfHeap(H)!= 1)
    {
        int a = DeleteMin(H);
        int b = DeleteMin(H);
        ans = ans + a+b;
        Insert(H,(a+b));
    }
    printf("%lld",ans);
    return 0;
}