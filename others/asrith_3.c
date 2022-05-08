#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct stack
{
    long long int max_numbers;
    long long int *stack_array;
    long long int top;
};
typedef struct stack* Stack;

long long int distance(long long int i, long long int j)
{
    long long int d = 0;
    d = j - i + 1;
    return d;
}
Stack initStack(long long int max_items)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct stack));
    assert(S != NULL);
    S->stack_array = (long long int *)malloc(max_items * sizeof(long long int));
    assert(S->stack_array != NULL);
    S->max_numbers = max_items;
    S->top = -1;
    return S;
}
long long int isEmpty(Stack S)
{
    if(S->top == -1){return 1;}
    else{return 0;}
}
long long int isFull(Stack S)
{
    if(S->top == S->max_numbers - 1){return 1;}
    else{return 0;}
}
void push(Stack S, long long int x)
{
    if(isFull(S) == 0)
    S->stack_array[++S->top] = x;
}
long long int pop(Stack S)
{
    long long int a = 0;
    if(isEmpty(S) == 0)
    a = S->stack_array[S->top];
    S->top--;
    return a;
}
long long int top(Stack S)
{
    if(!isEmpty(S)){
    return S->stack_array[S->top];}
}
long long int size(Stack S)
{
    return S->top + 1;
}
long long int SumStack(Stack S)
{
    long long int sum = 0;
    while(!isEmpty(S)){
        sum = sum + pop(S);
    }
    return sum;
}
void printStack(Stack S)
{
    for (int i = 0; i <= S->top; i++)
    {
        printf("%lld ", S->stack_array[i]);
    }
}

int main(void)
{
    long long int N;
    scanf("%lld", &N);
    long long int A[N], a;
    long long int I = (N*N - N)/2;
    Stack S1 = initStack(N);
    Stack S2 = initStack(N * N);
    for(long long int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    for(long long int i = 0; i < N; i++)
    {
        if(i == N){goto final;}
        for(long long int j = i + 1; j < N; j++)
        {
            if(isEmpty(S1))
            {
                push(S1, j); 
                a = distance(i, j);
                push(S2, a); 
                if(A[i] < A[j])
                {goto endthisloop;}
            }
            if(!isEmpty(S1))
            {
                if(A[top(S1)] < A[j] && A[top(S1)] < A[i])
                {
                    push(S1, j);
                    a = distance(i, j);
                    push(S2, a);
                }
            }
        }
endthisloop:
        while(!isEmpty(S1)){
           pop(S1);
        }
    }
final:    
    long long int ans = SumStack(S2);
    printf("%lld\n", ans);
    free(S1);
    free(S2);
}