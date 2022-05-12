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
        printf("data =%d sum = %lld max =%lld min = %lld\n", Q->head->data->data,Q->head->data->sum,Q->head->data->max_value,Q->head->data->min_value);

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
    free(Q);
}

void check_asceding(tree current)
{   
    if(current->left == NULL && current->right == NULL)
    {
        current->isBST = 1;
        current->sum = current->data;
        current->max_value = current->data;
        current->min_value = current->data;
    }
    else if((current->left ==NULL) &&(current->right !=NULL))
    {
        if(current->right->isBST == (-1))
            check_asceding(current->right);
        if(current->isBST == (-1))
        {
            if(current->data < current->right->min_value)
            {
                current->isBST = 1;
                current->min_value = current->data;
                current->max_value = current->right->max_value;
                current->sum = current->right->sum + current->data;
            }
            else
                current->isBST =0;
        }
    }
    else if((current->left !=NULL) && (current->right ==NULL))
    {   
        if(current->left->isBST ==(-1))
            check_asceding(current->left);
        if(current->isBST == (-1))
        {
            if(current->data > current->left->max_value)
            {
                current->isBST = 1;
                current->min_value = current->left->min_value;
                current->max_value = current->data;
                current->sum = current->left->sum + current->data;
            }
            else
                current->isBST = 0;
        }
    }
    if(current->left != NULL && current ->right != NULL)
    {
        if(current->left->isBST ==(-1))
            check_asceding(current->left);
        if(current->right->isBST == (-1))
            check_asceding(current->right);
        if((current->left->isBST == 1) && (current->right->isBST == 1))
        {
            if((current->data > current->left->max_value) && (current->data < current->right->min_value))
            {
                current->isBST = 1;
                current->min_value = current->left->min_value;
                current->max_value = current->right->max_value;
                current->sum = current->left->sum + current->right->sum + current->data;
            }
        }
        if((current->left->isBST == 0) || (current->right->isBST == 0))
        {
            current->isBST = 0;
        }
    }
}

void check_descending(tree current)
{   
    if(current->left == NULL && current->right == NULL)
    {
        current->isBST = 1;
        current->sum = current->data;
        current->max_value = current->data;
        current->min_value = current->data;
    }
    else if((current->left ==NULL) &&(current->right !=NULL))
    {
        if(current->right->isBST == (-1))
            check_descending(current->right);
        if(current->isBST == (-1))
        {
            if(current->data > current->right->max_value)
            {
                current->isBST = 1;
                current->max_value = current->data;
                current->min_value = current->right->min_value;
                current->sum = current->right->sum + current->data;
            }
            else
                current->isBST =0;
        }
    }
    else if((current->left !=NULL) && (current->right ==NULL))
    {   
        if(current->left->isBST ==(-1))
            check_descending(current->left);
        if(current->isBST == (-1))
        {
            if(current->data < current->left->min_value)
            {
                current->isBST = 1;
                current->min_value = current->data;
                current->max_value = current->left->max_value;
                current->sum = current->left->sum + current->data;
            }
            else
                current->isBST = 0;
        }
    }
    if(current->left != NULL && current ->right != NULL)
    {
        if(current->left->isBST ==(-1))
            check_descending(current->left);
        if(current->right->isBST == (-1))
            check_descending(current->right);
        if((current->left->isBST == 1) && (current->right->isBST == 1))
        {
            if((current->data < current->left->min_value) && (current->data > current->right->max_value))
            {
                current->isBST = 1;
                current->min_value = current->right->min_value;
                current->max_value = current->left->max_value;
                current->sum = current->left->sum + current->right->sum + current->data;
            }
        }
        if((current->left->isBST == 0) || (current->right->isBST == 0))
        {
            current->isBST = 0;
        }
    }
}

long long int checkLevelOrder(tree Root)
{   
    long long int min = INT_MAX;
    if (Root == NULL)
    {
        return 0;
    }

    Dq Q = createStruct();
    PushBack(Q, Root);

    while (isEmpty(Q) != 1)
    {
        // printf("%d ", Q->head->data->data);
        tree temp = Q->head->data;
        if(temp->sum < min)
            min = temp->sum;
        temp->sum =0;
        temp->max_value =0;
        temp->min_value =0;
        temp->isBST = -1;
        if (Q->head->data->left != NULL)
            PushBack(Q, Q->head->data->left);
        if (Q->head->data->right != NULL)
            PushBack(Q, Q->head->data->right);
        PopFront(Q);
    }
    free(Q);
    return min;
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
        // printLevelOrder(Head);
        // printf("-----------------------\n");
        check_asceding(Head);
        long long int min_one = checkLevelOrder(Head);
        check_descending(Head);
        long long int min_two = checkLevelOrder(Head);
        // printf("%lld %lld\n",min_one,min_two);
        if(min_one<min_two)
            printf("%lld\n",min_one);
        else
            printf("%lld\n",min_two);
        // printf("-----------------------\n\n");
        while (Size(Q)!=0)
        {
            PopFront(Q);
        }
        free(Q);
        delete(Head);
    }
    return 0;
}