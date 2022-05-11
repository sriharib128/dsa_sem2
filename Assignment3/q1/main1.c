#include "deque.h"
void printLevelOrder(tree Root)
{
    if (Root == NULL)
    {
        return;
    }

    Dq Q = createStruct();
    PushBack(Q, Root);

    while (isEmpty(Q) != 1)
    {
        printf("%d ", Q->head->data->data);

        if (Q->head->data->left != NULL)
        {
            PushBack(Q, Q->head->data->left);
        }
        if (Q->head->data->right != NULL)
        {
            PushBack(Q, Q->head->data->right);
        }
        PopFront(Q);
    }
}

int isLite(int left,int current , int right)
{
    if((left < current) && (current < right))
        return 1;
    if((left > current) && (current > right))
        return 1;
    return 0;
}

int Post_Order(tree T,long int * min)
{
    if(T== NULL)
        return 0;
    else
    {
        int left = Post_Order(T->left,min);
        int right = Post_Order(T->right,min);
        int current = T->data;
        if(left ==0 && right == 0)
            return current;
        if(isLite(left,current,right))
        {
            if((*min)>(left + right + current))
                *min = left + right + current;
        }
        return current;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int data;
        int input=0;
        scanf("%d",&data);
        input++;
        int depth =0;
        tree Head = createBinary(data);
        depth = 1;
        Dq Q = createStruct();
        PushBack(Q,Head);
        while ((input+2)<=n)
        {
            tree current = Front(Q);
            tree temp;
            scanf("%d",&data);
            input++;
            if(data!=0)
            {
                temp = createBinary(data);
                current->left = temp;
                PushBack(Q,current->left);
            }
            scanf("%d",&data);
            input++;
            if(data!=0)
            {
                temp = createBinary(data);
                current->right = temp;
                PushBack(Q,current->right);
            }
            PopFront(Q);
            if(Size(Q)==0)
                break;
        }
        if((n%2) == 0)
        {
            tree current = Front(Q);
            scanf("%d",&data);
            if(data!=0)
            {
                tree temp = createBinary(data);
                current->left = temp;
            }
        }
        long int min = 1e6;
        printLevelOrder(Head);
        printf("-----------------------\n");
        // Post_Order(Head,&min);
        // printf("%ld\n",min);
        // delete(Head);
    }
    return 0;
}