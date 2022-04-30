#include <stdio.h>
#include <stdlib.h>

typedef struct dll * node;

struct dll{
    node prev;
    node next;
    long long int data;
};

typedef struct stDQueue * Dq;

struct stDQueue{
    long long int size;
    node head;
    node tail;
};

Dq createStruct()
{
    Dq Q =(Dq)malloc(sizeof(struct stDQueue));
    Q->head=NULL;
    Q->tail=NULL;
    Q->size =0;
    return Q;
}

void PushFront(Dq Q, long long int a)
{
    node temp = (node)malloc(sizeof(struct dll));
    temp->data = a;
    Q->size = Q->size+1;
    if(Q->size==1)
    {
        Q->head=temp;
        temp->next=NULL;
        temp->prev=NULL;
        Q->tail = temp;
        return;
    }
    else
    {
        temp->next = Q->head;
        Q->head->prev = temp;
        temp->prev = NULL;
        Q->head = temp;
        return;
    }
}
void PushBack(Dq Q, long long int a)
{
    node temp = (node)malloc(sizeof(struct dll));
    temp->data = a;
    Q->size = Q->size+1;
    if(Q->size==1)
    {
        Q->head=temp;
        temp->next=NULL;
        temp->prev=NULL;
        Q->tail = temp;
        return;
    }
    else
    {
        temp->prev = Q->tail;
        temp->next = NULL; 
        Q->tail->next = temp;
        Q->tail = temp;
        return;
    }
}

long long int PopFront(Dq Q)
{   
    Q->size = Q->size -1;
    long long int element ;
    if(Q->size ==0)
    {
        element = Q->head->data;
        free(Q->head);
        Q->head = NULL;
        Q->tail = NULL;
    }
    else
    {
        node temp = Q->head;
        Q->head = Q->head->next;
        Q->head->prev = NULL;
        element = temp->data;
        free(temp);
    }
    return element;
}

long long int PopBack(Dq Q)
{   
    Q->size = Q->size -1;
    long long int element ;
    if(Q->size ==0)
    {
        element = Q->head->data;
        free(Q->head);
        Q->head = NULL;
        Q->tail = NULL;
    }
    else
    {
        node temp = Q->tail;
        Q->tail = Q->tail->prev;
        Q->tail->next = NULL;
        element = temp->data;
        free(temp);
    }
    return element;
}
long long int Front(Dq Q)
{
    return Q->head->data;
}
long long int Back(Dq Q)
{
    return Q->tail->data;
}
long long int Size(Dq Q)
{
    return Q->size;
}
int main()
{
    long long int M,N;
    scanf("%lld %lld",&N , &M);
    long long int* array = (long long int *)malloc(sizeof(long long int)*N);
    for(long long int i =0;i<N;i++)
        scanf("%lld",&array[i]);
    Dq Q = createStruct();
    PushBack(Q,0);
    for(long long int i=1;i<M;i++)
    {
        while(1)
        {   if(Size(Q)==0)
                break;
            if(array[Back(Q)]>=array[i])
                PopBack(Q);
            else
                break;
        }
        PushBack(Q,i);
    }
    for(long long int i=M;i<N;i++)
    {
        printf("%lld ",array[Front(Q)]);
        while(Front(Q)<=(i-M))
        {   
            PopFront(Q);
            if(Size(Q) ==0)
                break;
        }
        while(1)
        {
            if(Size(Q)==0)
                break;
            if(array[Back(Q)]>=array[i])
                PopBack(Q);
            else
                break;
        }
        PushBack(Q,i);  
    }

    printf("%lld",array[Front(Q)]);
    return 0;
}