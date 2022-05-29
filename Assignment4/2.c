#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int*b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    int A[N];

    for (int i = 0; i < N; i++)
        scanf("%d",&A[i]);
    int count =0;
    for(int i=0;i<N;i++)
    {
        if(A[i]>K)
        {
            swap(&A[i],&K);
            count++;
        }
    }
    for(int i=0;i<N-1;i++)
    {
        if(A[i]>A[i+1])
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d",count);
    return 0;
}