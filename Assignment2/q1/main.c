#include "stack.h"

void process (Stack S)
{
    if(S->size <= 1)
        return;
    long long int temp1 = S->array[S->top];
    long long int temp2 = S->array[S->top - 1];
    long long int g = gcd(temp1,temp2);
    while(g>1)
    {
        Pop(S);
        Pop(S);
        long long int lcm = temp1*temp2/g;
        Push(S,lcm);
        if(S->size>1)
        {
            temp1 = S->array[S->top];
            temp2 = S->array[S->top - 1];
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

    Stack S = (Stack)malloc(sizeof(struct stack_struct));
    S->size = 0;
    S->top = -1;
    S->array = (long long int *)malloc(sizeof(long long int)*size);

    for(int i=0;i<size;i++)
    {
        long long int a;
        scanf("%lld",&a);
        Push(S,a);
        process (S);
    }
    process (S);
    size = S->size;
    for(int i=0;i<size;i++)
    {
        printf("%lld ",(S->array)[i]);
    }


/*
	long long int g = gcd(a,b);
    long long int lcm  = a*b/g;
    */

}