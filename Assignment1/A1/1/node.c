#include "my_dll.h"

NodePointer createNode()
{
    NodePointer  n = (NodePointer)malloc(sizeof(Node));
    n->next = NULL;
    n->prev = NULL;
    return n;
}