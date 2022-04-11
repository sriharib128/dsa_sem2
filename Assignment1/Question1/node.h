#ifndef _NODE_H
#define _NODE_H

typedef struct node* NodePointer;
typedef struct node Node;
struct node{
    NodePointer prev;
    NodePointer next;
    int data;
};
#endif