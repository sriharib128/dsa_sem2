#include "heap.h"

heap Initialize(int MaxElements)
{
    heap H = (heap)malloc(sizeof(struct HeapStruct ));
    H->Capacity = MaxElements;
    H->Elements = (ElementType *)malloc(sizeof(ElementType)*(MaxElements+1));
    H->Size = 0;
    H->Elements[0]= INT_MIN;
}

void Insert(heap H,ElementType a)
{
    
}