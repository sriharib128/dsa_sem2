#include "deque.h"

int main()
{
    long long int M,N;
    scanf("%lld %lld",&N , &M);
    long long int* array = (long long int *)malloc(sizeof(long long int)*N);
    for(long long int i =0;i<N;i++)
        scanf("%lld",&array[i]);
    Dq Q = createStruct();
    PushBack(Q,0);
    // print(Q);
    // printf("---\n");
    for(long long int i=1;i<M;i++)
    {
        while(1)
        {   if(Q->size==0)
                break;
            if(array[Back(Q)]>=array[i])
                PopBack(Q);
            else
                break;
        }
        PushBack(Q,i);
    }
    // print(Q);
    // printf("first M windows completed\n");
    for(long long int i=M;i<N;i++)
    {
        printf("%lld ",array[Front(Q)]);
        // printf("indexOfFront(%lld) minimumwindowsize(%lld)\n",Front(Q),(i-M));
        while(Front(Q)<=(i-M))
        {   
            PopFront(Q);
            if(Q->size ==0)
                break;
        }
        // print(Q);
        // if(Q->size !=0)
        // {   
        //     printf("%lld  ",array[Front(Q)]);
        //     printf("indexOfFront(%lld) minimumwindowsize(%lld)",Front(Q),(i-M));
        // }
        // else
        //     printf("queue is empty\n");
        while(1)
        {
            if(Q->size==0)
                break;
            if(array[Back(Q)]>=array[i])
                PopBack(Q);
            else
                break;
        }
        PushBack(Q,i);  
        // print(Q);
        // printf("%lld  ",array[Front(Q)]);
        // printf("indexOfFront(%lld) minimumwindowsize(%lld)\n\n\n",Front(Q),(i-M));
    }
    // long long int min =1e10;
    // for(node a = Q->head ;a!=NULL;a=a->next)
    // {
    //     if(array[(a->data)]<min)
    //         min = array[a->data];
    // }
    printf("%lld",array[Front(Q)]);
    return 0;
}   