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
};
void PreOrder(tree T);
void InOrder(tree T);
void PostOrder(tree T);
int depth(tree T);
tree createBinary(char data);
void delete(tree T);
#endif