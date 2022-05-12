#include "bintree.h"

void PreOrder_Substring(tree T,char * pre_string)
{
    if(T== NULL)
        return;
    else
    {
        int i=strlen(pre_string);
        pre_string[i] = T->data;
        pre_string[i+1] ='\0';
        PreOrder_Substring(T->left,pre_string);
        PreOrder_Substring(T->right,pre_string);
    }
    return;
}

int main()
{   
    // printf("HI\n");
    long int N;
    scanf("%ld",&N);
    tree array[N+1];
    char string[N+10];
    scanf("%s",string);
    for(int i=0;i<N;i++)
        array[i]= createBinary(string[i]);
    for(int i=0;i<N-1;i++)
    {
        long int A,B,C;
        scanf("%ld %ld %ld",&A,&B,&C);
        if(C == 1)
        {
            array[A-1]->left = array[B-1];
        }
        else if(C == 2)
        {
            array[A-1]->right = array[B-1];
        }
    }
    long int index =0;
    PreOrder_Index(array[0],&index);
    // printf("--\n");
    char s[1000010];
    scanf("%s",s);
    long int Q;
    scanf("%ld",&Q);
    while (Q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            long int I;
            scanf("%ld",&I);
            char c;
            char temp;
            scanf(" %c",&c);
            // scanf(" %c",&temp);
            array[I-1]->data =c;
            index=0;
            // PreOrder(array[0],&index);
            // printf("--\n");
        }
        else if (t==2)
        {
            long int L,R,I;
            scanf("%ld %ld %ld",&L,&R,&I);
            char substring[1000010];
            int i;
            for(i=L-1;i<=R-1;i++)
            {
                substring[i-L+1] = s[i];
            }
            substring[i] = '\0';
            char pre_string[1000010];
            pre_string[0]='\0';
            PreOrder_Substring(array[I-1],pre_string);
            // printf("%s %s\n",substring,pre_string);
            if(strcmp(substring,pre_string)==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}