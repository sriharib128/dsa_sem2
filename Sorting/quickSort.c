#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

int sort(int A[],int start , int end , int pivot)
{
    int pivotindex = start;

    int temp = A[pivot];

    for(int i=start;i<=end;i++)
    {   
        // if(i==pivot)
        //     continue;
        if(A[i] < temp)
        {
            if(i!=pivotindex)
                swap(&A[i],&A[pivotindex]);
            pivotindex++;
        }

    }
    swap(&A[pivot],&A[pivotindex]);
    return pivotindex;  
}

void quicksort(int A[],int start , int end)
{
    if(start<end)
    {
        // int pivot = (start+end)/2;
        // int pivot = end;
        int pivot = end;
        sort(A,start,end,pivot);
        quicksort(A,start,pivot-1);
        quicksort(A,pivot+1,end);
    }
}

int main()
{
    int A[]={0,-1,-2,4,2,0,2,100,10};
    int n = sizeof(A)/sizeof(int);
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");  
    quicksort(A,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}