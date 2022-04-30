#include <stdio.h>
#include <stdlib.h>

typedef struct stack_struct* Stack;

struct stack_struct {
    long long  int top;
    long long int size;
    long long int *array;
};
Stack create(long long int n)
{
    Stack S = (Stack)malloc(sizeof(struct stack_struct));
    S->array = (long long int *)malloc(sizeof(long long int)*n);
    S->top = -1;
    S->size =0;
    return S;
}
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
long long int Size(Stack S)
{
    return S->size;
}


long long int max_area(long long int* array,int M)
{
    // for(int i=0;i<M;i++)
    //     printf("%lld ",array[i]);
    // printf("\n");
    Stack S = create(M);
    long long int area = 0;
    for(int i=0;i<M;i++)
    {
        if(Size(S) == 0)
            Push(S,i);
        else
        {
            if(array[Top(S)]<=array[i])
            {
                if(Top(S)!=i)
                    Push(S,i);
            }
            else
            {   
                while (array[Top(S)]>array[i])
                {   
                    long long int temp = Pop(S);
                    long long int temp_area;
                    if(Size(S) ==0)
                        temp_area = array[temp]*i;
                    else
                        temp_area = array[temp]*(i-Top(S)-1);
                    if(temp_area>area)
                        area = temp_area;
                    if(Size(S)==0)
                    {
                        break;
                    }
                }
                Push(S,i);
            }
        }
    }
    while (Size(S) !=0)
    {
        long long int temp  = Pop(S);
        long long int temp_area;
        if(Size(S) ==0)
            temp_area = array[temp]*M;
        else
            temp_area = array[temp]*(M-Top(S)-1);
        if(temp_area>area)
            area = temp_area;
    }
    return area;
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    long long int array[N][M];
    for(int i=0;i<N;i++)
    {
        char temp[M+10];
        scanf("%s",temp);
        for(int j=0;j<M;j++)
        {
            if(temp[j]=='.')
                array[i][j] = 1;
            else
                array[i][j] = 0;
        }
    }
    for(int i=1;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(array[i][j]!=0)
                array[i][j] += array[i-1][j];
        }

    long long int area =0;
    for(int i=0;i<N;i++)
    {   
        long long int temp = max_area(array[i],M);
        if(temp>area)
            area = temp;
    }
    printf("%lld",area);
    return 0;
}