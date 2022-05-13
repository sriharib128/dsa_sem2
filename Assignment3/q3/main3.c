#include "hash.h"

int main( int argc, char *argv[])
{
    FILE * f[argc];
    // int temp = argc-1;
    f[0] = fopen(argv[1],"w");
    int a = 1;
    int b = 2;
    int temp_file_no=argc -1;
    while(temp_file_no!=1)
    {
        int countBucket_array[4]={2,5,10,20};
        int cases = 4;
        while(cases--)
        {   
            f[temp_file_no] = fopen( argv[temp_file_no], "r" );
            int countBucket = countBucket_array[cases];
            struct HashTable * T =init_hash_table(a,b,countBucket); 
            while (1)
            {
                char temp[1000];
                if(fscanf(f[temp_file_no],"%s",temp)==EOF)
                    break;
                if(strcmp(temp,"EXIT")==0)
                    break;
                int key;
                fscanf(f[temp_file_no],"%d",&key);
                if(strcmp(temp,"INSERT")==0)
                    insert(T,key);
                else if(strcmp(temp,"SEARCH")==0)
                    search(T,key);
                else if(strcmp(temp,"DELETE")==0)
                    Delete(T,key);
                else if(strcmp(temp,"PRINT")==0)
                    print_table(T);
            }
            printf("%d ==> %d - %s -%s",cases,temp_file_no,f[temp_file_no],argv[temp_file_no]);
            fclose(f[temp_file_no]);
            printf("\n------------------------------------\n");
        }
        temp_file_no--;
        printf("****************************************\n\n\n");
    }
    return 0;
}