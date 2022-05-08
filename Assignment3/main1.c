#include "deque.h"

int Post_Order(tree T,long int * min)
{
    if(T== NULL)
        return 0;
    else
    {
        int left = Post_Order(T->left,min);
        int right = Post_Order(T->right,min);
        int current = T->data;
        if((*min)>(left + right + current))
            *min = left + right + current;
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
        Post_Order(Head,&min);
        printf("%ld\n",min);
    }
    return 0;
}