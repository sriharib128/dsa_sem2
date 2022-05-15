#ifndef BIN_TREE
#define BIN_TREE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  BinTree* tree;

struct BinTree{
    tree left;
    long long int data;
    tree right;
};
void PreOrder(tree T);
void InOrder(tree T);
void PostOrder(tree T);
int depth(tree T);
tree createBinary(long long int data);
void createBakul(tree T,tree head,long long int ct);
void Delete(tree T);
#endif