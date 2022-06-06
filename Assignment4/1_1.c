#include <stdio.h>
#include <stdlib.h>


int cmpfnc(const void *a,const void *b)
{
    return*(long long int*)a-*(long long int*)b;
}
struct Heap
{
    int size;
    int cap;
    // long long int *harr;
    struct Ass* * harr;
};

struct Ass
{
    int sum;
    int index1,index2;
};

struct Heap *dataallocate(int capacity)
{
    struct Heap *heap_in = (struct Heap *)malloc(sizeof(struct Heap));
    heap_in->size=0;
    heap_in->harr = (struct Ass **)malloc(sizeof(struct Ass*) * capacity);
    return heap_in;
}

void Heapify(struct Heap *heap_in, long long int idx)
{
    long long int smallest = idx;
    long long int left = 2 * idx + 1;
    long long int right = 2 * idx + 2;
    if (left < heap_in->size)
        if (heap_in->harr[left]->sum < heap_in->harr[smallest]->sum)
            smallest = left;
    if (right < heap_in->size)
        if (heap_in->harr[right]->sum < heap_in->harr[smallest]->sum)
            smallest = right;
    if (smallest != idx)
    {
        struct Ass* temp = heap_in->harr[smallest];
        heap_in->harr[smallest] = heap_in->harr[idx];
        heap_in->harr[idx] = temp;
        Heapify(heap_in, smallest);
    }
}

void heap_make(struct Heap *heap_in)
{
    long long int i = (heap_in->size - 2) / 2;
    for (; i >= 0; --i)
        Heapify(heap_in, i);
}

struct Ass* get_min(struct Heap *heap_in)
{
    struct Ass* temp = heap_in->harr[0];
    int index = heap_in->size - 1;
    heap_in->harr[0] = heap_in->harr[index];
    --heap_in->size;
    Heapify(heap_in, 0);
    return temp;
}

void insert_elem(struct Heap *heap_in, struct Ass * val)
{   
    // printf("%d\n",__LINE__);
    ++(heap_in->size);
    long long int i = heap_in->size - 1;
    while (i > 0 && (val->sum < heap_in->harr[(i - 1) / 2]->sum))
    {
        heap_in->harr[i] = heap_in->harr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap_in->harr[i] = val;
    // printf("%d\n",__LINE__);
    
}

// struct Heap *variableallocate(struct Heap *heap_in, long long int *arr, long long int n)
// {
//     heap_in->size = n;
//     heap_in->cap = n;
//     for (long long int i = 0; i < n; ++i)
//         heap_in->harr[i] = arr[i];
//     heap_make(heap_in);
// }

void PrintHeap(struct Heap *heap_in)
{
    for(int i=0;i<heap_in->size;i++)
        printf("%lld ",heap_in->harr[i]->sum);
    printf("\n");
}

int main()
{
    long long int test ;
    scanf("%lld",&test);
    for(int v=0;v<test;v++)
    {   
        long long int k;
        scanf("%lld",&k);
        long long int count = k-1;
        long long int * one=(long long int *)malloc(sizeof(long long int)*k);
        for(int i=0;i<k;i++)
        {
            scanf("%lld",&one[i]);
        }
        qsort(one,k,sizeof(long long int),cmpfnc);

        while (count--)
        {
            long long int * two=(long long int *)malloc(sizeof(long long int)*k);
            for(int i=0;i<k;i++)
            {
                scanf("%lld",&two[i]);
            }
            qsort(two,k,sizeof(long long int),cmpfnc);

            struct Heap * heap_in = dataallocate(k+1);
            int check[k][k];
            
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                    check[j][i]=0;

            struct Ass * set = (struct Ass *)malloc(sizeof(struct Ass));
            check[0][0]=1;
            set->sum = one[0]+two[0];
            set->index1=set->index2=0;
            insert_elem(heap_in,set);
            
            long long int * sum=(long long int *)malloc(sizeof(long long int)*k);
            

            int n_minsums =0;
            while(n_minsums <k)
            {
                struct Ass * temp  =get_min(heap_in) ;
                sum[n_minsums]=temp->sum;
                int i= temp->index1;
                int j= temp->index2;

                if(j+1 < k)
                {   
                    struct Ass *set = (struct Ass *)malloc(sizeof(struct Ass));
                    set->sum=one[i]+two[j+1];
                    set->index1=i;
                    set->index2=j+1;

                    if(check[i][j+1]==0)
                    {
                        check[i][j+1]=1;
                        insert_elem(heap_in,set);
                    }
                }
                if(i+1<k)
                {   
                    struct Ass *set = (struct Ass *)malloc(sizeof(struct Ass));
                    set->sum=one[i+1]+two[j];
                    set->index1=i+1;
                    set->index2=j;

                    if(check[i+1][j]==0)
                    {
                        check[i+1][j]=1;
                        insert_elem(heap_in,set);
                    }
                }
                n_minsums = n_minsums+1;
                if(heap_in->size==0)
                {
                    break;
                }
            }      
            one = sum;
        }
        for(int i=0;i<k;i++)
        {
            printf("%lld ",one[i]);
        }
        printf("\n");
    }
}