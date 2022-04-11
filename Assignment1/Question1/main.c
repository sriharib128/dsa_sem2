#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_dll.h"
int main()
{
    my_dll_P P = createStruct();
    while(1)
    {
        char *s=(char*)malloc(sizeof(char)*20);
        scanf("%s",s);
        printf("\nonce done\n");
        int x,i;

        if(strcmp(s,"insert")==0)
        {
            scanf("%d",&x);
            insert(P,x);
        }
        else if (strcmp(s,"insert_at")==0)
        {
            scanf("%d %d",&x,&i);
            insert_at(P,x,i);
        }
        else if (strcmp(s,"DELETE")==0)
        {
            scanf("%d",&i);
            DELETE(P,i);
        }
        else if (strcmp(s,"find")==0)
        {
            scanf("%d",&x);
            find(P,x);
        }
        else if (strcmp(s,"prune")==0)
        {
            prune(P);
        }
        else if (strcmp(s,"print")==0)
        {
            print(P);
        }
        else if (strcmp(s,"print_reverse")==0)
        {
            print_reverse(P);
        }
        else if (strcmp(s,"get_size")==0)
        {
            printf("%d\n",get_size(P));
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