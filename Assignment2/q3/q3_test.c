// sum = sum + j-Top(S)+1;
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
                else
                    sum = sum + j-Top(S)+1;
                while(array[Top(S)]<array[i])
                {
                    j=Top(S);
                    sum = sum + i-j +1;
                    Pop(S);
                    if(S->size ==0)
                        break;
                    else
                        sum = sum + j-Top(S)+1;
                }
                Push(S,i);
            }   
        }
    }
    printf("%lld",sum);
    return 0;
}