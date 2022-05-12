#ifndef BIN_TREE
#define BIN_TREE
#include <stdio.h>
#include <stdlib.h>
typedef struct  BinTree* tree;

struct BinTree{
    tree left;
    int data;
    tree right;
    int isBST;
    long long int sum;
    long long int max_value;
    long long int min_value;
};
void PreOrder(tree T);
void InOrder(tree T);
void PostOrder(tree T);
int depth(tree T);
tree createBinary(int data);
void delete(tree T);
#endif

#ifndef _DEQUE_H
#define _DEQUE_H

// #include "bintree.h"

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
int isEmpty(Dq Q);
long long int Size(Dq Q);

// long long int PopBack(Dq Q);
// void PushFront(Dq Q , tree T);
// long long int Back(Dq Q);
void print(Dq P);
// void print_reverse(Dq P);
#endif
// #include "deque.h"

Dq createStruct()
{
    Dq Q =(Dq)malloc(sizeof(struct stDQueue));
    Q->head=NULL;
    Q->tail=NULL;
    Q->size =0;
    return Q;
}

void PushFront(Dq Q, tree T)
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
        temp->next = Q->head;
        Q->head->prev = temp;
        temp->prev = NULL;
        Q->head = temp;
        return;
    }
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

tree PopBack(Dq Q)
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
        node temp = Q->tail;
        Q->tail = Q->tail->prev;
        Q->tail->next = NULL;
        element = temp->data;
        free(temp);
    }
    return element;
}
tree Front(Dq Q)
{
    return Q->head->data;
}
tree Back(Dq Q)
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

// #include "bintree.h"

tree createBinary(int data)
{
    tree T = (tree)malloc(sizeof(struct BinTree));
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    T->sum =0;
    T->max_value =0;
    T->min_value =0;
    T->isBST = -1;
    return T;
}
int max(int a , int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

void delete(tree T)
{
    if(T->left==NULL && T->right==NULL)
    {   
        printf("%d",T->data);
        free(T);
    }
    else if(T->left != NULL)
    {
        delete(T->left);
    }
    else if(T->right !=NULL)
    {
        delete(T->right);
    }
}

int depth(tree T)
{
    if(T == NULL)
        return 0;
    return 1 + max(depth(T->left),depth(T->right));
}

void check_asceding(tree current)
{   
    if(current->left == NULL && current->right == NULL)
    {
        current->isBST = 1;
        current->sum = current->data;
        current->max_value = current->data;
        current->min_value = current->data;
    }
    else if((current->left ==NULL) &&(current->right !=NULL))
    {
        if(current->right->isBST == (-1))
            check_asceding(current->right);
        if(current->isBST == (-1))
        {
            if(current->data < current->right->min_value)
            {
                current->isBST = 1;
                current->min_value = current->data;
                current->max_value = current->right->max_value;
                current->sum = current->right->sum + current->data;
            }
            else
                current->isBST =0;
        }
    }
    else if((current->left !=NULL) && (current->right ==NULL))
    {   
        if(current->left->isBST ==(-1))
            check_asceding(current->left);
        if(current->isBST == (-1))
        {
            if(current->data > current->left->max_value)
            {
                current->isBST = 1;
                current->min_value = current->left->min_value;
                current->max_value = current->data;
                current->sum = current->left->sum + current->data;
            }
            else
                current->isBST = 0;
        }
    }
    if(current->left != NULL && current ->right != NULL)
    {
        if(current->left->isBST ==(-1))
            check_asceding(current->left);
        if(current->right->isBST == (-1))
            check_asceding(current->right);
        if((current->left->isBST == 1) && (current->right->isBST == 1))
        {
            if((current->data > current->left->max_value) && (current->data < current->right->min_value))
            {
                current->isBST = 1;
                current->min_value = current->left->min_value;
                current->max_value = current->right->max_value;
                current->sum = current->left->sum + current->right->sum + current->data;
            }
        }
        if((current->left->isBST == 0) || (current->right->isBST == 0))
        {
            current->isBST = 0;
        }
    }
}

void check_descending(tree current)
{   
    if(current->left == NULL && current->right == NULL)
    {
        current->isBST = 1;
        current->sum = current->data;
        current->max_value = current->data;
        current->min_value = current->data;
    }
    else if((current->left ==NULL) &&(current->right !=NULL))
    {
        if(current->right->isBST == (-1))
            check_descending(current->right);
        if(current->isBST == (-1))
        {
            if(current->data > current->right->max_value)
            {
                current->isBST = 1;
                current->max_value = current->data;
                current->min_value = current->right->min_value;
                current->sum = current->right->sum + current->data;
            }
            else
                current->isBST =0;
        }
    }
    else if((current->left !=NULL) && (current->right ==NULL))
    {   
        if(current->left->isBST ==(-1))
            check_descending(current->left);
        if(current->isBST == (-1))
        {
            if(current->data < current->left->min_value)
            {
                current->isBST = 1;
                current->min_value = current->data;
                current->max_value = current->left->max_value;
                current->sum = current->left->sum + current->data;
            }
            else
                current->isBST = 0;
        }
    }
    if(current->left != NULL && current ->right != NULL)
    {
        if(current->left->isBST ==(-1))
            check_descending(current->left);
        if(current->right->isBST == (-1))
            check_descending(current->right);
        if((current->left->isBST == 1) && (current->right->isBST == 1))
        {
            if((current->data < current->left->min_value) && (current->data > current->right->max_value))
            {
                current->isBST = 1;
                current->min_value = current->right->min_value;
                current->max_value = current->left->max_value;
                current->sum = current->left->sum + current->right->sum + current->data;
            }
        }
        if((current->left->isBST == 0) || (current->right->isBST == 0))
        {
            current->isBST = 0;
        }
    }
}

long long int checkLevelOrder(tree Head)
{   
    long long int min = INT_MAX;
    if (Head == NULL)
        return 0;

    Dq Q = createStruct();
    PushBack(Q, Head);

    while (isEmpty(Q) != 1)
    {
        tree temp = Q->head->data;
        if(temp->sum < min)
            min = temp->sum;
        temp->isBST=-1;
        temp->sum =0;
        if (Q->head->data->left != NULL)
            PushBack(Q, Q->head->data->left);
        if (Q->head->data->right != NULL)
            PushBack(Q, Q->head->data->right);
        PopFront(Q);
    }
    return min;
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
        int depth =0;
        tree Head = createBinary(data);
        depth = 1;
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
        // printLevelOrder(Head);
        // printf("-----------------------\n");
        check_asceding(Head);
        long long int min_one = checkLevelOrder(Head);
        check_descending(Head);
        long long int min_two = checkLevelOrder(Head);
        // printf("%lld %lld\n",min_one,min_two);
        if(min_one<min_two)
            printf("%lld\n",min_one);
        else
            printf("%lld\n",min_two);
        // printf("-----------------------\n\n");
    }
    return 0;
}