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

int isEmpty (Stack S)
{
    if(S->size == 0)
        return 1;
    else
        return 0;
}

Stack create(long long int size)
{
    Stack S = (Stack)malloc(sizeof(struct stack_struct));
    S->size = 0;
    S->top = -1;
    S->array = (long long int *)malloc(sizeof(long long int)*size);
    return S;
}

long long int Size(Stack S)
{
    return S->size;
}

long long int gcd(long long int a ,long long int b ){
	if(a==0)
        return b;
    long long int rem = b%a;
	return gcd(rem,a);
}

void process (Stack S)
{
    if(Size(S) <= 1)
        return;
    long long int temp1 = Top(S);
    Pop(S);
    long long int temp2 = Top(S);
    Push(S,temp1);
    long long int g = gcd(temp1,temp2);
    while(g>1)
    {
        Pop(S);
        Pop(S);
        long long int lcm = temp1*temp2/g;
        Push(S,lcm);
        if(Size(S)>1)
        {
            temp1 = Top(S);
            Pop(S);
            temp2 = Top(S);
            Push(S,temp1);
            g = gcd(temp1,temp2);
        }
        else
            break;
    }
    return ;
}

int main(){

    long long int size;
    scanf("%lld",&size);

    Stack S = create(size);

    for(int i=0;i<size;i++)
    {
        long long int a;
        scanf("%lld",&a);
        Push(S,a);
        process (S);
    }
    process (S);
    size = Size(S);
    printf("%lld\n",size);
    long long int* reverse = (long long int *)malloc(sizeof(long long int)*size);
    for(int i=0;i<size;i++)
        reverse[i] = Pop(S);
    for(int i=size-1;i>=0;i--)
        printf("%lld ",reverse[i]);
    return 0;
}