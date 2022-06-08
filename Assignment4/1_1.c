#include <stdio.h>
#include <stdlib.h>


int cmpfnc(const void *a,const void *b)
{
    return (*(long long int*)a-*(long long int*)b);
}
struct Heap
{
    int size;
    int cap;
    struct Ass** harr;
};

struct Ass
{
    long long int sum;
    int index1,index2;
};

struct Heap *dataallocate(int capacity)
{
    struct Heap *heap_in = (struct Heap *)malloc(sizeof(struct Heap));
    heap_in->size=0;
    heap_in->harr = (struct Ass **)malloc(sizeof(struct Ass*) * capacity);
    return heap_in;
}

void Heapify(struct Heap *heap_in, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap_in->size)
        if (heap_in->harr[left]->sum <= heap_in->harr[smallest]->sum)
            smallest = left;
    if (right < heap_in->size)
        if (heap_in->harr[right]->sum <= heap_in->harr[smallest]->sum)
            smallest = right;
    if (smallest != idx)
    {
        struct Ass* temp = heap_in->harr[smallest];
        heap_in->harr[smallest] = heap_in->harr[idx];
        heap_in->harr[idx] = temp;
        Heapify(heap_in, smallest);
    }
}

struct Ass* get_min(struct Heap *heap_in)
{
    struct Ass* temp = heap_in->harr[0];
    int index = heap_in->size - 1;
    heap_in->harr[0] = heap_in->harr[index];
    heap_in->size = heap_in->size -1;
    Heapify(heap_in, 0);
    return temp;
}

void insert_elem(struct Heap *heap_in, struct Ass * val)
{   
    ++(heap_in->size);
    int i = heap_in->size - 1;
    while (i > 0 && (val->sum < heap_in->harr[(i - 1) / 2]->sum))
    {
        heap_in->harr[i] = heap_in->harr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap_in->harr[i] = val;
}


int main()
{
    long long int test ;
    scanf("%lld",&test);
    for(int v=0;v<test;v++)
    {   
        // printf("1");
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

            struct Heap * heap_in = dataallocate(k*k);
            int check[k][k];
            
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                    check[i][j]=0;

            struct Ass * set = (struct Ass *)malloc(sizeof(struct Ass));
            check[0][0]=1;
            set->sum = one[0]+two[0];
            set->index1=0;
            set->index2=0;
            insert_elem(heap_in,set);
            
            long long int * sum=(long long int *)malloc(sizeof(long long int)*k);
            

            int n_minsums =0;
            while(n_minsums <k)
            {
                if(heap_in->size>0)
                {
                    struct Ass * temp  =get_min(heap_in) ;
                    sum[n_minsums]=temp->sum;
                    int i= temp->index1;
                    int j= temp->index2;
                    free(temp);
                    if((j+1 < k) && (check[i][j+1]==0) )
                    {   
                        struct Ass *set = (struct Ass *)malloc(sizeof(struct Ass));
                        set->sum=one[i]+two[j+1];
                        set->index1=i;
                        set->index2=j+1;
                        check[i][j+1]=1;
                        insert_elem(heap_in,set);
                    }
                    if((i+1<k) && (check[i+1][j]==0) )
                    {   
                        struct Ass *set = (struct Ass *)malloc(sizeof(struct Ass));
                        set->sum=one[i+1]+two[j];
                        set->index1=i+1;
                        set->index2=j;
                        check[i+1][j]=1;
                        insert_elem(heap_in,set);
                    }
                    n_minsums = n_minsums+1;
                }
                else
                    break;
            }
            free(two);
            free(one);
            free(heap_in->harr);
            free(heap_in);
            one = sum;
        }
        for(int i=0;i<k;i++)
        {
            printf("%lld ",one[i]);
        }
        printf("\n");
    }
}