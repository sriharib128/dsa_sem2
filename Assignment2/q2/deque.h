#ifndef _DEQUE_H
#define _DEQUE_H

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

Dq createStruct();
void PushFront(Dq Q , long long int a);
void PushBack(Dq Q , long long int a);
long long int PopFront(Dq Q);
long long int PopBack(Dq Q);
long long int Front(Dq Q);
long long int Back(Dq Q);
int isEmpty(Dq Q);
long long int Size(Dq Q);
void print(Dq P);
void print_reverse(Dq P);
#endif

/*
Create a deque to store k elements.
Run a loop and insert first k elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Now, run a loop from k to end of the array.
Print the front element of the deque.
Remove the element from the front of the queue if they are out of the current window.
Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Print the maximum element of the last window.
*/