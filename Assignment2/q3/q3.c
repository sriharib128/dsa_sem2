#include "stack.h"

int main()
{
    long long int N;
    scanf("%lld",&N);
    long long int array[N];
    for(int i=0;i<N;i++)
        scanf("%lld",&array[i]);
    
    Stack S = (Stack)malloc(sizeof(struct stack_struct));
    S->array = (long long int *)malloc(sizeof(long long int)*N);
    S->top = -1;
    S->size = 0;

    long long int sum =0;
    for(int i=0;i<N;i++)
    {
        if(S->size ==0)
        {   
            Push(S,i);
        }
        else
        {
            if(array[Top(S)]>array[i])
                Push(S,i);
            else
            {   
                int j  = Top(S);
                sum = sum + i-j +1;
                Pop(S);
                if(S->size ==0)
                {
                    Push(S,i);
                    continue;
                }
                while(array[Top(S)]<array[i])
                {
                    j=Top(S);
                    sum = sum + i-j +1;
                    Pop(S);
                    if(S->size ==0)
                        break;
                }
                Push(S,i);
            }   
        }
    }
    printf("%lld\n",sum);
    Stack S2 = (Stack)malloc(sizeof(struct stack_struct));
    S2->array = (long long int *)malloc(sizeof(long long int)*N);
    S2->top = -1;
    S2->size =0;
    for(int i=N-1;i>=0;i--)
    {
        if(S2->size ==0)
        {   
            Push(S2,i);
        }
        else
        {
            if(array[Top(S2)]>array[i])
                Push(S2,i);
            else
            {   
                int j  = Top(S2);
                sum = sum + j-i +1;
                printf("%d and %d\n",i,j);
                Pop(S2);
                if(S2->size ==0)
                {
                    Push(S2,i);
                    continue;
                }
                while(array[Top(S2)]<array[i])
                {
                    j=Top(S2);
                    sum = sum + j-i +1;
                printf("%d and %d\n",i,j);
                    Pop(S2);
                    if(S2->size ==0)
                        break;
                }
                Push(S2,i);
            }   
        }
    }
    printf("%lld",sum);
    return 0;
}