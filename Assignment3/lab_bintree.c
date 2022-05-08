#include "bintree.h"

tree createBinary(int data)
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
        printf("%d ",T->data);
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
        printf("%d ",T->data);
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
        printf("%d ",T->data);
        InOrder(T->right);
    }
    return;
}


void PreOrder_input(tree T)
{   
    int temp1,temp2;
    printf("enter left  and right node of %d ",T->data);
    scanf("%d %d",&temp1 , &temp2);
    printf("\n");
    if(temp1 !=-1)
    {
        T->left = createBinary(temp1);
        PreOrder_input(T->left);
    }
    // printf("enter right node of %d ",T->data);
    // scanf("%d",&temp);
    // printf("\n");
    if(temp2 !=-1)
    {
        T->right = createBinary(temp2);
        PreOrder_input(T->right);
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