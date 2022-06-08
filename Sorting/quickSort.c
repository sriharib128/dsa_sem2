#include <stdio.h>
#include <stdlib.h>

void sort(int A[],int start , int end , int pivot)
{
    int pivotindex = start-1;

    int temp = A[pivot];

    for(int i=start;i<pivot;i++)
    {
        if(A[i] < temp)
        {
            pivotindex++;
            swap(&A[i],&A[pivotindex]);
        }
    }
    swap(&A[pivot],&A[pivotindex]);

    
}

void quicksort(int A[],int start , int end)
{
    if(start<end)
    {
        int pivot = end;
        sort(A,start,end,pivot);
        quicksort(A,start,pivot);
        quicksort(A,pivot+1,end);
    }
}

int main()
{
    int A[]={0,-1,-2,4,2,100,10};
    int n = sizeof(A)/sizeof(int);

    quicksort(A,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}