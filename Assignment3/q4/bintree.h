#ifndef BIN_TREE
#define BIN_TREE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  BinTree* tree;
struct BinTree{
    tree left;
    char data;
    tree right;
    long int index;
};
void PreOrder(tree T);
void InOrder(tree T);
void PostOrder(tree T);
int depth(tree T);
tree createBinary(char data);
void delete(tree T);
void PreOrder_Index(tree T,long int* index);
void PreOrder_Substring(tree T, char *pre_string);
#endif

