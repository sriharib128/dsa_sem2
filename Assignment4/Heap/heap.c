#include "heap.h"

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

heap Initialize(int MaxElements)
{
    heap H = (heap)malloc(sizeof(struct HeapStruct ));
    H->Capacity = MaxElements+1;
    H->Elements = (ElementType *)malloc(sizeof(ElementType)*(MaxElements+1));
    H->Size = 0;
    H->Elements[0]= INT_MIN;
    return H;
}

void Insert(heap H,ElementType a)
{
    int i = H->Size+1;
    while(H->Elements[(i-1)/2]>=a)
    {
        H->Elements[i]=H->Elements[(i-1)/2];
        i=(i-1)/2;
        if(i==0)
            break;
    }
    H->Elements[i]=a;
    H->Size++;
    return ;
}

void AdjustHeap(heap H, int pos)
{
    return ;
}

ElementType DeleteMin(heap H)
{
    if(H->Size==0)
        return INT_MIN;
    ElementType min;
    if(H->Size==1)
    {
        min = H->Elements[1];
        H->Size--;
        return min;
    }
    else if(H->Size >=2)
    {
        if(H->Elements[1]>H->Elements[2])
        {
            min = H->Elements[2];
            H->Elements[2]=INT_MAX;
            if(H->Size!=2)
                AdjustHeap(H,2);
        }
        else
        {
            min = H->Elements[1];
            if(H->Size ==2)
                H->Elements[1]=H->Elements[2];
            else
            {
                H->Elements[1] = INT_MAX;
                AdjustHeap(H,1);
            }
        }
        H->Size--;
        return min;
    }
    
}

void printHeap(heap H)
{
    printf("%d %d\n",H->Capacity,H->Size);
    for(int i=0;i<=H->Size;i++ )
    {
        printf("%d ",H->Elements[i]);
    }
    printf("\n");
}

int main()
{
    int A[]={1,2,3,5,4,3,2,1,2};
    int elements = sizeof(A)/sizeof(int);
    heap H = Initialize(elements);
    for(int i=0;i<elements;i++)
    {
        Insert(H,A[i]);
        printHeap(H);
        printf("\n");
    }
    
    return 0;
}