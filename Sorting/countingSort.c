
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[]={0,-1,-2,4,2,100,10};
    int n = sizeof(A)/sizeof(int);
    
    int  hash[10000] ={};
    for(int i=0;i<n;i++)
        hash[A[i]+3]++;

    for(int i=1;i<10000;i++)
        hash[i] = hash[i]+hash[i-1];


    int sorted_array[n];

    for(int i=0;i<n;i++)
        sorted_array[--hash[A[i]+3]] = A[i];

    for(int i=0;i<n;i++)
        printf("%d ",sorted_array[i]);
    return 0;
}