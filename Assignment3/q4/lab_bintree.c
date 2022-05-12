#include "bintree.h"

tree createBinary(char data)
{
    tree T = (tree)malloc(sizeof(struct BinTree));
    T->data = data;
    T->left = NULL;
    T->right = NULL;
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

void PreOrder(tree T)
{
    if(T== NULL)
        return;
    else
    {
        printf("%c ",T->data);
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