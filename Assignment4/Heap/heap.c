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

void swap(ElementType* a, ElementType* b)
{
    ElementType temp = *a;
    *a = *b;
    *b = temp;
}
heap Initialize(int MaxElements)
{
    heap H = (heap)malloc(sizeof(struct HeapStruct ));
    H->Capacity = MaxElements+1;
    H->Elements = (ElementType *)malloc(sizeof(ElementType)*(MaxElements+1));
    H->Size = 0;
    return H;
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

// int main()
// {
//     int A[]={1,-1,2,4,-2};
//     int elements = sizeof(A)/sizeof(int);
//     heap H = Initialize(elements);
//     for(int i=0;i<elements;i++)
//     {
//         Insert(H,A[i]);
//         printHeap(H);
//         printf("\n");
//     }
//     printf("------------------------------------\n");
//     printf("------------------------------------\n");
//     while ((H->Size>0))
//     {
//         printHeap(H);
//         printf(" ==> %d ==> ",DeleteMin(H));
//         printHeap(H);
//         printf("\n");
//     }
//     return 0;
// }