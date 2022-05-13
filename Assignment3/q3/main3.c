#include "hash.h"

int main()
{
    int a = 1;
    int b = 2;
    int countBucket=7;
    struct HashTable * T =init_hash_table(a,b,countBucket); 
    while (1)
    {
    char temp[1000];
    scanf("%s",temp);
    if(strcmp(temp,"EXIT")==0)
        break;
    int key;
    scanf("%d",&key);
    if(strcmp(temp,"INSERT")==0)
        insert(T,key);
    else if(strcmp(temp,"SEARCH")==0)
        search(T,key);
    else if(strcmp(temp,"DELETE")==0)
        Delete(T,key);
    else if(strcmp(temp,"PRINT")==0)
        print_table(T);
    }
    return 0;
}