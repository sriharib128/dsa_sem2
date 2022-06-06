#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long int* ElementType;
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
ElementType FindMin (heap H);
void destroy(heap H);
// void MakeEmpty(heap H);
// int IsEmpty(heap H);
// int IsFull(heap H);
#endif

// #include "heap.h"

ElementType minimum(ElementType a, ElementType b)
{
    if(a[0]>=b[0])
        return b;
    return a;
}

ElementType maximum(ElementType a, ElementType b)
{
    if(a[0]>=b[0])
        return a;
    return b;
}
ElementType FindMin (heap H)
{
    if(H->Size==0)
        return NULL;
    return H->Elements[0];
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
void destroy(heap H)
{
    free(H->Elements);
    free(H);
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
        while(H->Elements[(i-1)/2][0]>=a[0])
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
            if(H->Elements[pos][0]>H->Elements[2*pos +1][0])
                swap( &H->Elements[pos], &H->Elements[2*pos +1]);
            return;
        }
    }
    else//NODE HAS TWO CHILDREN
    {
        if(H->Elements[pos][0]>minimum(H->Elements[2*pos +2],H->Elements[2*pos +1])[0])
        {
            if(H->Elements[2*pos +2][0] > H->Elements[2*pos +1][0])
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
        return NULL;
    ElementType min=H->Elements[0];
    if(H->Size >=2)
    {   
        H->Elements[0]=H->Elements[H->Size-1];
        AdjustHeap(H,0);
    }
    H->Size--;
    return min;
}

// void printHeap(heap H)
// {
//     printf(" ( %d %d ) ",H->Capacity,H->Size);
//     for(int i=0;i<H->Size;i++ )
//     {
//         printf("%d_i(%d)_j(%d) ",H->Elements[i][0],H->Elements[i][1],H->Elements[i][2]);
//     }
//     // printf("\n");
// }

// #include "heap.h"

int compare (const void * a, const void * b) 
{
    int c=*(int*)a;
    int d = *(int*)b;

    if(c>d)
        return 1;
    else if(c==d)
        return 0;
   else
        return (-1);
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int k;
        scanf("%d",&k);
        int A[k][k];
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                int temp;
                scanf("%d",&temp);
                A[i][j]=temp;
            }
            qsort(&A[i][0],k,sizeof(int),compare);
            // for(int j=0;j<k;j++)
            // {
            //     printf("%d ",A[i][j]);
            // }
            // printf("\n");
        }
        

        int* array1 = &A[0][0];
        int* array2 = &A[1][0];

        int  array3[k];
        int s =2;//section
        while(s<=k)
        {
            heap H = CreateHeap(k*k);
            int MAP[k][k];
            
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                    MAP[i][j]=0;

            long long int *pair = (long long int *)malloc(sizeof(long long int)*3);
            pair[0]=array1[0]+array2[0];
            pair[1]=0;
            pair[2]=0;
            Insert(H,pair);
            MAP[0][0] = 1;

            int count =0;
            while(count <k && SizeOfHeap(H) >=1)
            {
                long long int * temp  = DeleteMin(H);
                array3[count++]=temp[0];
                int i= temp[1];
                int j= temp[2];
                free(temp);
                // printf("%d(%d) + %d(%d) = %d(%d)\n",array1[i],i,array2[j],j,array3[count-1],count-1);
                // printf("--------------\n");
                if(i+1<k)
                {   
                    long long int *pair = (long long int *)malloc(sizeof(long long int)*3);
                    pair[0]=array1[i+1]+array2[j];
                    pair[1]=i+1;
                    pair[2]=j;

                    if(MAP[i+1][j]==0)
                    {   
                        Insert(H,pair);
                        MAP[i+1][j]=1;
                    }
                }
                if(j+1 < k)
                {   
                    long long int *pair = (long long int *)malloc(sizeof(long long int)*3);
                    pair[0]=array1[i]+array2[j+1];
                    pair[1]=i;
                    pair[2]=j+1;

                    if(MAP[i][j+1]==0)
                    {
                        MAP[i][j+1]=1;
                        Insert(H,pair);
                    }
                }
            }
            
            // printf("\n");
            destroy(H);
            for(int i=0;i<k;i++)
            {
                array1[i]=array3[i];
            }
            array2 = A[s++];
        }
        for(int i=0;i<k;i++)
            printf("%d ",array3[i]);
        printf("\n");
    }
    return 0;   
}