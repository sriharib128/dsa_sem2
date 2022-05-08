#include <stdio.h>
#include <stdlib.h>


typedef struct Stack
{
    long long int top;
    long long int capacity;
    long long int *array;
} STACK;

STACK *createStack(long long int capacity)
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (long long int *)malloc(stack->capacity * sizeof(long long int));
    return stack;
}

int topp(STACK *stack){
    return stack->top;
}
int isFull(STACK *stack)
{
    return (stack->top == (stack->capacity - 1));
}

int isEmpty(STACK *stack)
{
    return (stack->top == -1);
}

void push(STACK *stack, long long int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

long long int pop(STACK *stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }

    stack->top--;
    return stack->array[stack->top + 1];
}

long long int peek(STACK *stack)
{
    if (isEmpty(stack))
        return 0;

    return stack->array[stack->top];
}
int max(int num1, int num2)
{
    if (num1 > num2)
        return num1;

    else
        return num2;
}
int min(int num1, int num2)
{
    if (num1 > num2)
        return num2;

    else
        return num1;
}
long long int gcd(long long int a, long long int b)
{
    if (a == 0)
        return b;
    else
    {
        return gcd(b % a, a);
    }
}
long long int lcm(long long int a, long long int b)
{
    return (a * b) / gcd(a, b);
}
int maxHist(long long int row[], int m, int n)
{
   
    STACK *stack = createStack(m);
    long long int top;
    long long int max_area = 0;
    long long int area = 0;
    for(int i=0;i<m;)
    {
        if (isEmpty(stack) || row[peek(stack)] <= row[i])
            push(stack, i++);
        else
        {
            top = row[peek(stack)];
            pop(stack);
        
            if (isEmpty(stack))
                area = top * i;
            else
                area = top * (i - peek(stack) - 1);
            max_area = max(area, max_area);
        }
    }

    while (!isEmpty(stack))
    {
        top = row[peek(stack)];
        pop(stack);
        if (isEmpty(stack))
            area = top * m;
        else
            area = top * (m - peek(stack) - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}
int main()
{
    int m, n;
    scanf("%d %d", &n, &m);
    long long int A[n][m];
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &ch);
            if (ch == '.')
            {
                A[i][j] = 1;
            }
            else
            {
                A[i][j] = 0;
            }
        }
    }

    long long int result = maxHist(A[0], m,n);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] !=0)
            {
                A[i][j] += A[i - 1][j];
            }
        }
        result = max(result, maxHist(A[i], m,n));
    }
	printf("%lld",result);
    return 0;
}