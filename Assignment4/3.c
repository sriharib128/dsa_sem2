#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    long long int A[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    long long int prefix[n];
    prefix[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
        prefix[i]=prefix[i+1]+A[i];
    long long int result =prefix[0];

    if(n>1)
        qsort(&prefix[1], n-1, sizeof(long long int), cmpfunc);
    
    int n_element=0;
    for(int i=n-1;i>=0;i--)
    {
        if(n_element >= (k-1))
            break;
        result=result+prefix[i];
        n_element++;
    }
    printf("%d",result);
    return 0;
}