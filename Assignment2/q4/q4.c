#include "stack.h"

long long int max_area(long long int* array,int M)
{
    for(int i=0;i<M;i++)
        printf("%lld ",array[i]);
    printf("\n");
    Stack S = create(M);
    long long int area = 0;
    // int i =0;
    // Push(S,i);
    for(int i=0;i<M;i++)
    {
        if(S->size == 0)
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
                    long long int temp  =Pop(S);
                    // Pop(S); 
                    long long int temp_area;
                    if(S->size ==0)
                        temp_area = array[temp]*i;
                    else
                        temp_area = array[temp]*(i-Top(S)-1);
                    if(temp_area>area)
                        area = temp_area;
                    if(S->size==0)
                    {
                        break;
                    }
                }
                Push(S,i);
            }
        }
    }
    while (S->size !=0)
    {
        long long int temp  = Pop(S);
        // Pop(S); 
        long long int temp_area;
        if(S->size ==0)
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
            // printf("%lld ",array[i][j]);
        }
        // printf("\n"); 
    }
    // N=4;M=4;
    // long long int array[4][4] = {
	// 	{ 0, 1, 1, 0 },
	// 	{ 1, 1, 1, 1 },
	// 	{ 1, 1, 1, 1 },
	// 	{ 1, 1, 0, 0 },
	// };
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
        printf("%lld ==> %d th row\n\n",temp,i);
        if(temp>area)
            area = temp;
    }
    printf("%lld",area);
}
/*
3 ==> 0 th row

2 0 2 1 2 1 2
5 ==> 1 th row

3 1 3 2 3 2 3
10 ==> 2 th row

4 2 4 3 4 3 0
12 ==> 3 th row
*/