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
    int i=start;
    int j = end;

    int temp= A[pivot];
    while(i<j)
    {
        if(A[i]>temp && A[j]<temp)
        {
            swap(&A[i],&A[j]);
            i++;
            j--;
        }
        else
            i++;
    }
}

void quicksort(int A[],int start , int end)
{
    if(start<end)
    {
        // int pivot = (start+end)/2;
        int pivot = start;
        // int pivot = end;
        sort(A,start,end,pivot);
        quicksort(A,start,pivot);
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