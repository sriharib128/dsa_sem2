#include "my_dll.h"

my_dll_P createStruct()
{
    my_dll_P P =(my_dll_P)malloc(sizeof(struct my_dll));
    assert(P!=NULL);
    P->last=NULL;
    P->root=NULL;
    P->size =0;
    return P;
}

void insert(my_dll_P P , int x)
{
    NodePointer temp = (NodePointer)malloc(sizeof(Node));
    assert(temp!=NULL);
    temp->data=x;
    if(P->root==NULL)
    {
        P->root=temp;
        temp->next=NULL;
        temp->prev=NULL;
        P->last = temp;
        P->size = P->size+1;
        return;
    }
    NodePointer a = P->last;
    a->next=temp;
    temp->prev =a;
    temp->next=NULL;
    P->last = temp;
    P->size = P->size+1;
    return ;
}
void insert_at(my_dll_P P , int x , int i)
{
    NodePointer temp = (NodePointer)malloc(sizeof(Node));
    assert(temp!=NULL);
    temp->data=x;
    if(P->root==NULL)
    {
        P->root=temp;
        temp->next=NULL;
        temp->prev=NULL;
        P->last = temp;
        P->size = P->size+1;
        return;
    }

    if(i==0)
    {
        NodePointer temporary = P->root;
        P->root = temp;
        temp->next = temporary;
        temporary->prev = temp;
        temp->prev = NULL;
        P->size = P->size+1;
        return ;
    }
    if(i==(P->size))
    {
            NodePointer a = P->last;
            a->next=temp;
            temp->prev =a;
            temp->next=NULL;
            P->last = temp;
            P->size = P->size+1;
            return;
    }
    int ct=0;
    for(NodePointer a = P->root;;a=a->next)
    {
        if(ct==(i-1))
        {
            
            NodePointer temporary = a->next;
            a->next=temp;
            temp->prev = a;
            temp->next = temporary;
            temporary->prev = temp;
            P->size = P->size+1;
            return;
        }
        ct++;
    }
}

void DELETE(my_dll_P P, int i)
{
    //only one item is there in the list
    if(P->size ==1 )
    {
        free(P->root);
        P->root = NULL;
        P->last = NULL;
        P->size = 0;
        return ;
    }
    if(i==0)
    {
        NodePointer temporary = (P->root);
        P->root = (P->root)->next;
        (P->root)->prev = NULL;
        free(temporary);
        P->size = (P->size)-1;
    }
    else if(i== (P->size)-1)
    {
        NodePointer temporary = (P->last);
        P->last = (P->last)->prev;
        (P->last)->next = NULL;
        free(temporary);
        P->size = (P->size)-1;
    }
    else
    {
        int ct=0;
        for(NodePointer a = P->root;;a=a->next)
        {
            if(ct==i)
            {
                NodePointer tempPrev = a->prev;
                NodePointer tempNext = a->next;
                tempPrev->next = tempNext;
                tempNext->prev = tempPrev;
                free(a);
                P->size = (P->size)-1;
                return;
            }
            ct++;
        }
    }
}
int find(my_dll_P P, int x)
{
    int ct=0;
    int flag =0;
    for(NodePointer a = P->root;;ct++,a=a->next)
    {   
        if(a->data == x)
            return ct;
        if(a->next == NULL)
            return (-1);
    }
}
void prune(my_dll_P P)
{
    int i=0;
    int ct=0;
    int temp = P->size;
    for(NodePointer a = P->root;ct<temp;ct++)
    {
        if(ct&1)
        {   
            if(a->next != NULL)
            {
                NodePointer tempPrev = a->prev;
                NodePointer tempNext = a->next;
                tempPrev->next = tempNext;
                tempNext->prev = tempPrev;
                free(a);
                a = tempPrev;
                P->size = P->size -1;
            }
            else
            {
                NodePointer temporary = (P->last);
                P->last = (P->last)->prev;
                (P->last)->next = NULL;
                free(temporary);
                P->size = P->size -1;
            }
        }
        a = a->next;
    }
}

void print(my_dll_P P)
{
    for(NodePointer a = P->root;; a=a->next)
    {   
        printf("%d ",a->data);

        if(a->next == NULL)
        {
            printf("\n");
            return;
        }
    }
}
void print_reverse(my_dll_P P)
{
    for(NodePointer a = P->last;; a=a->prev)
    {   
        printf("%d ",a->data);
        if(a->prev == NULL)
        {
            printf("\n");
            return;
        }
    }
}
int get_size(my_dll_P P)
{
    return (P->size);
}