#ifndef _HASH_H
#define _HASH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item * Item_p;
typedef struct HashTable * HashTable_P;
typedef struct  Bucket * Bucket_P;
struct Item
{
    int key;
    int frequency;
    struct Item* next;
};
struct Bucket
{
    struct Item *items;
};

struct HashTable
{
    int a, b, countBucket;
    // count Bucket = number of buckets
    //hash function will be (a*key + b)%countBucket;
    struct Bucket *buckets;
};
struct HashTable *init_hash_table(int a, int b, int countBucket); // function for initializing a hash table with given parameters.
struct HashTable *insert(struct HashTable *T, int key); // function for inserting new key into hash table.
int search(struct HashTable *T, int key); // return true if element is present in hash table, otherwise false.
struct HashTable * Delete (struct HashTable *T, int key); // delete given key from the hash table. Do nothing if element is not present inside hash table.
void print_table(struct HashTable *T); // function should print one line for each
#endif
// #include "hash.h"

long long int insert_call_count=0;
long long int insert_operations_count=0;
long long int search_call_count=0;
long long int search_operations_count=0;

struct HashTable *init_hash_table(int a, int b, int countBucket)
{
    struct HashTable * hash = (struct HashTable *)malloc(sizeof(struct HashTable));
    hash->a = a;
    hash->b = b;
    hash->countBucket = countBucket;
    hash->buckets = (struct Bucket *)malloc(sizeof(struct Bucket)*countBucket);
    for(long int i=0;i<countBucket;i++)
        hash->buckets[i].items=NULL;
    return hash;
}
// function for initializing a hash table with given parameters.
struct HashTable *insert(struct HashTable *T, int key)
{   
    insert_call_count++;
    if(T==NULL)
        return T;
    long int hash_function = (((T->a)*key) + (T->b))%(T->countBucket);

    if(T->buckets[hash_function].items == NULL)
    {
        struct Item* temp_item =(struct Item *)malloc(sizeof(struct Item));
        temp_item->key = key;
        temp_item->frequency =1;
        temp_item->next = NULL;
        T->buckets[hash_function].items = temp_item; 
    }
    else
    {
        struct Item * temp_item = T->buckets[hash_function].items;
        while (temp_item->next != NULL)
        {
            if(temp_item->key == key)
            {
                temp_item->frequency++;
                return T;
            }
            temp_item = temp_item->next;
            insert_operations_count++;
        }
        if(temp_item->key == key)
        {
            temp_item->frequency++;
            return T;
        }
        else
        {
            struct Item* temp_item_2 =(struct Item *)malloc(sizeof(struct Item));
            temp_item_2->key = key;
            temp_item_2->frequency =1;
            temp_item_2->next = NULL;
            temp_item->next  = temp_item_2;
        }
    }
    return T;
}
 // function for inserting new key into hash table.
int search(struct HashTable *T, int key)
{   
    search_call_count++;
    if(T==NULL)
        return 0;
    long int hash_function = (((T->a)*key) + (T->b))%(T->countBucket);
    if(T->buckets[hash_function].items == NULL)
        return 0;
    else
    {
        struct Item * temp_item = T->buckets[hash_function].items;
        while (temp_item!= NULL)
        {
            search_operations_count++;
            if(temp_item->key == key)
            {
                return 1;
            }
            temp_item = temp_item->next;
        }
    }
    return 0;
}
// return true if element is present in hash table, otherwise false.
struct HashTable * Delete (struct HashTable *T, int key)
{
    if(T==NULL)
        return T;
    long int hash_function = (((T->a)*key) + (T->b))%(T->countBucket);
    if(T->buckets[hash_function].items == NULL)
        return 0;
    else
    {
        struct Item * temp_temp=NULL;
        struct Item * temp_item = T->buckets[hash_function].items;
        while (temp_item!= NULL)
        {
            if(temp_item->key == key)
            {   
                if(temp_item->frequency >1)
                {
                    temp_item->frequency--;
                    return T;
                }
                else
                {
                    if(temp_temp != NULL)
                    {
                        temp_temp->next = temp_item->next;
                        free(temp_item);
                        return T;
                    }
                    else
                    {
                        T->buckets[hash_function].items = temp_item->next;
                        free(temp_item);
                        return T;
                    }
                }
            }
            temp_temp = temp_item;
            temp_item = temp_item->next;
        }
    }
} // delete given key from the hash table. Do nothing if element is not present inside hash table.
void print_table(struct HashTable *T)
{
    for(int i=0;i<T->countBucket;i++)
    {
        struct Item* temp = T->buckets[i].items;
        while (temp!=NULL)
        {
            printf("%d %d ",temp->key,temp->frequency);
            temp= temp->next;
        }
        printf("\n");
    }
}
// #include "hash.h"
// long long int insert_call_count=0;
// long long int insert_operations_count=0;
// long long int search_call_count=0;
// long long int search_operations_count=0;
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
            printf("%d ==> %d - %s -%s\n",cases,temp_file_no,f[temp_file_no],argv[temp_file_no]);
            fclose(f[temp_file_no]);
            printf("\t > no of buckets = %d\n\t\t\tinsert_calls = %lld insert_operations = %lld  avg_per_call = %lld\n",countBucket_array[cases],insert_call_count,insert_operations_count,(insert_operations_count/insert_call_count));
            printf("\t\t\tsearch_calls = %lld search_operations = %lld  avg_per_call = %lld\n",search_call_count,search_operations_count,search_operations_count/search_call_count);
            insert_call_count=0;
            insert_operations_count=0;
            search_call_count=0;
            search_operations_count=0;
            printf("\n------------------------------------\n");
        }
        temp_file_no--;
        printf("****************************************\n\n\n");
    }
    return 0;
}