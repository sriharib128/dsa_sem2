#include <stdio.h>
#include <stdlib.h>

typedef int * ElementType;

void merge(ElementType array[],int start , int mid , int end)
{
    int L_size = mid-start +1;
    int R_size = end -(mid+1) + 1;
    
    ElementType L[L_size];
    for(int i=0;i<L_size;i++)
        L[i]=array[start+i];

    ElementType R[R_size];
    for(int i=0;i<R_size;i++)
        R[i] = array[mid+1+i];
    
    // merge two sorted arrays
    int l_index =0;
    int r_index =0;
    int a_index = start;
    while(l_index <L_size && r_index <R_size)
    {
        if(*R[r_index] > *L[l_index])
        {
            array[a_index++] = L[l_index++];
        }
        else
        {
            array[a_index++] = R[r_index++];
        }
    }

    while(r_index<R_size)
    {
        array[a_index++] = R[r_index++];
    }

    while(l_index<L_size)
    {
        array[a_index++] = L[l_index++];
    }
    return ;
}

void mergesort(ElementType array[],int start , int end)
{
    if(start<end)
    {
        int mid = (start + end)/2;
        mergesort(array,start,mid);
        mergesort(array,(mid+1),end);
        merge(array,start,mid,end);
    }
    return;
}

int main()
{
    int A[]={0,1,-1};
    int n = sizeof(A)/sizeof(int);

    ElementType array[n];
    for(int i=0;i<n;i++)
    {
        array[i]=&A[i];
    }

    mergesort(array,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",*array[i]);
}