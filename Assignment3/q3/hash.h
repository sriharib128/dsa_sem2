struct Item
{
    int key;
    int frequency;
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