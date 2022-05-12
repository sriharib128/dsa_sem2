#include "bintree.h"

// void PreOrder_Substring(tree T,char * pre_string)
// {
//     if(T== NULL)
//         return;
//     else
//     {
//         int i=strlen(pre_string);
//         pre_string[i] = T->data;
//         pre_string[i+1] ='\0';
//         PreOrder(T->left);
//         PreOrder(T->right);
//     }
//     return;
// }

int main()
{   
    long int N;
    scanf("%lld",&N);
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
    // InOrder(array[0]);
    // return 0;
    char s[1000010];
    scanf("%s",s);
    printf("subsrting = %s \n",s);
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
            printf("%c\n",c);
            scanf(" %c",&temp);
            array[I-1]->data =c; 
        }
        else if (t==2)
        {
            long int L,R,I;
            scanf("%ld %ld %ld",&L,&R,&I);
            char substring[1000010];
            int i;
            for(i=L;i<=R;i++)
            {
                substring[i-L] = s[i];
            }
            substring[i] = '\0';
            char pre_string[1000010];
            pre_string[0]='\0';
            // PreOrder_Substring(array[I-1],pre_string);
            if(strcmp(substring,pre_string)==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        printf("Hi\n");
        return 0;
    }
    return 0;
}