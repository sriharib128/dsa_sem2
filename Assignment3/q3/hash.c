#include "hash.h"

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
    if(T==NULL)
        return T;
    long int hash_function = (((T->a)*key) + (T->b))%(T->countBucket);
    // printf("%lld\n",__LINE__);

    if(T->buckets[hash_function].items == NULL)
    {
        // printf("%lld\n",__LINE__);
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