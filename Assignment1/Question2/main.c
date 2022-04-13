#include "complex.h"

int main()
{
    while(1)
    {
        char *s=(char*)malloc(sizeof(char)*20);
        scanf("%s",s);
        //printf("> done\n");
        int dim;
        scanf("%d",&dim);
        if(strcmp(s,"ADD")==0)
        {
            complex_P a= input(dim);
            complex_P b = input(dim);
            print(add(a,b));
        }
        else if(strcmp(s,"SUB")==0)
        {
            complex_P a= input(dim);
            complex_P b = input(dim);
            print(sub(a,b));
        }
        else if(strcmp(s,"MOD")==0)
        {
            complex_P a= input(dim);
            printf("%.2f\n",mod(a));
        }
        else if(strcmp(s,"DOT")==0)
        {
            complex_P a= input(dim);
            complex_P b = input(dim);
            printf("%.2f\n",dot(a,b));
        }
        else if(strcmp(s,"COS")==0)
        {
            complex_P a= input(dim);
            complex_P b = input(dim);
            printf("%.2f\n",COS(a,b));
        }
        else if (strcmp(s,"quit")==0)
        {
            break;
        }
        else
        {
            printf("Enter Valid Input\n");
        }
    }
}