#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifndef my_dll_H
#define my_dll_H

typedef struct my_dll* my_dll_P;
struct my_dll
{
    NodePointer root;
    NodePointer last;
    unsigned int size;
};

my_dll_P createStruct();
void insert(my_dll_P P , int x);
void insert_at(my_dll_P P , int x , int i);
void DELETE(my_dll_P P, int i);
int find(my_dll_P P, int x);
void prune(my_dll_P P);
void print(my_dll_P P);
void print_reverse(my_dll_P P);
int get_size(my_dll_P P);
#endif
