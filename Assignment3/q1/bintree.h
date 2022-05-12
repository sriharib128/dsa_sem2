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