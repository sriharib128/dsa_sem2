#include "deque.h"

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
int isEmpty(Dq Q)
{
    if(Q->size == 0)
        return 1;
    else
        return 0;
}

long long int Size(Dq Q)
{
    return Q->size;
}

void print(Dq P)
{
    for(node a = P->head;a!=NULL; a=a->next)
    {   
        printf("%lld ",a->data);

        if(a->next == NULL)
        {
            printf("\n");
            return;
        }
    }
}
void print_reverse(Dq P)
{
    for(node a = P->tail;a!=NULL; a=a->prev)
    {   
        printf("%lld ",a->data);
        if(a->prev == NULL)
        {
            printf("\n");
            return;
        }
    }
}