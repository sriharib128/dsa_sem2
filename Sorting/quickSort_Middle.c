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
    int *temp_ptr = &A[pivot];
    while(i<j)
    {
        while(A[i]<=temp)
        {
            i++;
            if(i>=end)
                break;
        }
        while (A[j]>=temp)
        {
            j--;
            if(j<=start)
                break;
        }
        if(i>=end)
                break;
        if(j<=start)
                break;
        if(A[i]>temp && A[j]<temp)
        {
            swap(&A[i],&A[j]);
            if(i==pivot)
            {
                temp_ptr = &A[j];
            }
            if(j==pivot)
            {
                temp_ptr = &A[i];
            }
        }
    }
    swap(temp_ptr,&A[j]);
    return j;
}

void quicksort(int A[],int start , int end)
{
    if(start<end)
    {
        int pivot = (start+end)/2;
        // int pivot = start;
        // int pivot = end;
        int pivotindex;
        pivotindex =sort(A,start,end,pivot);
        quicksort(A,start,pivotindex-1);
        quicksort(A,pivotindex+1,end);
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