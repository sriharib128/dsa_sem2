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
#endif

// #include "bintree.h"

tree createBinary(char data)
{
    tree T = (tree)malloc(sizeof(struct BinTree));
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    T->index = -1;
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

void PreOrder_Index(tree T,long int* index)
{
    if(T== NULL)
        return;
    else
    {
        T->index = *index;
        *index = *index + 1;
        // printf("%c-%ld\t",T->data,T->index);
        PreOrder_Index(T->left,index);
        PreOrder_Index(T->right,index);
    }
    return;
}
void PreOrder(tree T)
{
    if(T== NULL)
        return;
    else
    {
        printf("%c-%ld\t",T->data,T->index);
        PreOrder(T->left);
        PreOrder(T->right);
    }
    return;
}
void PostOrder(tree T)
{
    if(T== NULL)
        return;
    else
    {
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%c ",T->data);
    }
    return;
}
void InOrder(tree T)
{
    if(T== NULL)
        return;
    else
    {
        InOrder(T->left);
        printf("%c ",T->data);
        InOrder(T->right);
    }
    return;
}


// int ifBST(tree root)
// {
//     if(root == NULL)
//         return 1;
//     int flag = 1;
//     if(root->left != NULL && )

// }

// int main ()
// {
//     tree root = createBinary(2);
    
//     PreOrder_input(root);
//     printf("\n\n");
    
//     PreOrder(root);
//     printf("\n");
    
//     InOrder(root);
//     printf("\n");
    
//     PostOrder(root);
//     return 0;
// }

// #include "bintree.h"

void PreOrder_Substring(tree T, char *pre_string)
{
    if (T == NULL)
        return;
    else
    {
        int i = strlen(pre_string);
        pre_string[i] = T->data;
        pre_string[i + 1] = '\0';
        PreOrder_Substring(T->left, pre_string);
        PreOrder_Substring(T->right, pre_string);
    }
    return;
}

int main()
{
    // printf("HI\n");
    long int N;
    scanf("%ld", &N);
    tree array[N + 1];
    char string[N + 10];
    scanf("%s", string);
    for (int i = 0; i < N; i++)
        array[i] = createBinary(string[i]);
    for (int i = 0; i < N - 1; i++)
    {
        long int A, B, C;
        scanf("%ld %ld %ld", &A, &B, &C);
        if (C == 1)
        {
            array[A - 1]->left = array[B - 1];
        }
        else if (C == 2)
        {
            array[A - 1]->right = array[B - 1];
        }
    }
    long int index = 0;
    PreOrder_Index(array[0], &index);
    // printf("--\n");
    char s[1000010];
    scanf("%s", s);
    long int Q;
    scanf("%ld", &Q);
    while (Q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            long int I;
            scanf("%ld", &I);
            char c;
            // char temp;
            scanf(" %c", &c);
            // scanf(" %c",&temp);
            array[I - 1]->data = c;
            index = 0;
            // PreOrder(array[0],&index);
            // printf("--\n");
        }
        else if (t == 2)
        {
            long int L, R, I;
            scanf("%ld %ld %ld", &L, &R, &I);

            char pre_string[1000010];
            pre_string[0] = '\0';
            PreOrder_Substring(array[I - 1], pre_string);
            // printf("%s %s\n",substring,pre_string);
            if (strncmp(&s[L - 1], &pre_string[0], R - L + 1) == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}