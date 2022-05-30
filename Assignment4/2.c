#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int*b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

int is_sorted(int A[],int N)
{
    int flag =0;
    for(int i = 0 ; i<N-1;i++)
    {
        if(A[i]>A[i+1])
        {
            flag =1;
            break;  
        }
    }
    if(flag ==1)
        return 1;
    return 0;
}

int main()
{
    int N,K;
    scanf("%d",&N);
    scanf("%d",&K);
    int A[N];

    for (int i = 0; i < N; i++)
        scanf("%d",&A[i]);
        
    int count =0;
    for(int i=0;i<N;i++)
    {
        if(is_sorted(A,N)==0)
        {
            printf("%d",count);
            return 0;
        }
        if(A[i]>K)
        {
            swap(&A[i],&K);
            count++;
        }
    }
    
    for(int k=0;k<N-1;k++)
    {
        if(A[k]>A[k+1])
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d",count);
    return 0;
}