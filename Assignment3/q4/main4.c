#include "bintree.h"
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

int main()
{
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
    char pre_string[1000010];
    pre_string[0] = '\0';
    PreOrder_Substring(array[0], pre_string);
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
            scanf(" %c", &c);
            pre_string[array[I-1]->index] = c;
        }
        else if (t == 2)
        {
            long int L, R, I;
            scanf("%ld %ld %ld", &L, &R, &I);
            if (strncmp(&s[L - 1], &pre_string[array[I-1]->index], R - L + 1) == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}