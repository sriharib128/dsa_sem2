#ifndef BIN_TREE
#define BIN_TREE
#include <stdio.h>
#include <stdlib.h>
typedef struct  BinTree* tree;

struct BinTree{
    tree left;
    int data;
    tree right;
    int level;
};
tree createBinary(int data);
#endif

#ifndef _DEQUE_H
#define _DEQUE_H

typedef struct dll* node;

struct dll{
    node prev;
    node next;
    tree data;
};

typedef struct stDQueue * Dq;

struct stDQueue{
    long long int size;
    node head;
    node tail;
};

Dq createStruct();
void PushBack(Dq Q , tree T);
tree PopFront(Dq Q);
tree Front(Dq Q);
long long int Size(Dq Q);
#endif

tree createBinary(int data)
{
    tree T = (tree)malloc(sizeof(struct BinTree));
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    return T;
}
Dq createStruct()
{
    Dq Q =(Dq)malloc(sizeof(struct stDQueue));
    Q->head=NULL;
    Q->tail=NULL;
    Q->size =0;
    return Q;
}
void PushBack(Dq Q, tree T)
{
    node temp = (node)malloc(sizeof(struct dll));
    temp->data = T;
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

tree PopFront(Dq Q)
{   
    Q->size = Q->size -1;
    tree element ;
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

tree Front(Dq Q)
{
    return Q->head->data;
}

long long int Size(Dq Q)
{
    return Q->size;
}

int Post_Order(tree T,long int * min)
{
    if(T== NULL)
        return 0;
    else
    {
        int left = Post_Order(T->left,min);
        int right = Post_Order(T->right,min);
        int current = T->data;
        if((*min)>(left + right + current))
            *min = left + right + current;
        return current;
    }
    return 0;
}


int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int data;
        int input=0;
        scanf("%d",&data);
        input++;
        tree Head = createBinary(data);
        Dq Q = createStruct();
        PushBack(Q,Head);
        while ((input+2)<=n)
        {
            tree current = Front(Q);
            tree temp;
            scanf("%d",&data);
            input++;
            if(data!=0)
            {
                temp = createBinary(data);
                current->left = temp;
                PushBack(Q,current->left);
            }
            scanf("%d",&data);
            input++;
            if(data!=0)
            {
                temp = createBinary(data);
                current->right = temp;
                PushBack(Q,current->right);
            }
            PopFront(Q);
            if(Size(Q)==0)
                break;
        }
        if((n%2) == 0)
        {
            tree current = Front(Q);
            scanf("%d",&data);
            if(data!=0)
            {
                tree temp = createBinary(data);
                current->left = temp;
            }
        }
        long int min = 1e6;
        Post_Order(Head,&min);
        printf("%ld\n",min);
    }
    return 0;
}