#include <stdio.h>
#include <stdlib.h>

typedef struct stack_struct* Stack;

struct stack_struct {
    long long  int top;
    long long int size;
    long long int *array;
};

long long int Pop(Stack S)
{
    if(S->size >0)
    {
        S->top = (S->top -1);
        S->size = S->size - 1;  
        return (S->array)[S->top+1];
    }
    else
        return (-1);
}

void Push(Stack S,long long int a)
{
    if(S->size == 0)
    {
        S->array[0] = a;
        S->top = 0;
        S->size =1;
    }
    else
    {
        S->top = S->top + 1;
        S->array[S->top] = a;
        S->size = S->size + 1;
    }
    return;
}

long long int Top(Stack S)
{
    if(S->size < 0)
        return -1;
    else
        return S->array[S->top];
}

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
                if(S->size !=0)
                    sum = sum + j-Top(S)+1;
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
                    if(S->size !=0)
                        sum = sum + j-Top(S)+1;
                    if(S->size ==0)
                        break;
                }
                Push(S,i);
            }   
        }
    }
    while(S->size!=0)
    {
        int j=Top(S);
        Pop(S);
        if(S->size !=0)
            sum = sum + j-Top(S)+1;
    }
    printf("%lld",sum);
    return 0;
}