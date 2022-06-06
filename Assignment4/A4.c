#include <stdio.h>
#include <stdlib.h>

#define ll long long int
typedef struct MinHeap *Heap;

struct MinHeap
{
    ll size;
    ll capacity;
    ll *harr;
};

Heap InitMinHeap(ll capacity)
{
    Heap minHeap;
    minHeap = (Heap)malloc(sizeof(struct MinHeap));
    minHeap->harr = (ll *)malloc((capacity + 1) * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swap(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(Heap minHeap, ll idx)
{
    ll min_idx = idx;
    ll left_idx = 2 * idx + 1;
    ll right_idx = 2 * idx + 2;

    if (left_idx < minHeap->size && minHeap->harr[left_idx] < minHeap->harr[min_idx])
        min_idx = left_idx;

    if (right_idx < minHeap->size && minHeap->harr[right_idx] < minHeap->harr[min_idx])
        min_idx = right_idx;

    if (min_idx != idx)
    {
        swap(&minHeap->harr[min_idx], &minHeap->harr[idx]);
        Heapify(minHeap, min_idx);
    }
}

ll ExtractMinimun(Heap minHeap)
{
    ll min = minHeap->harr[0];
    minHeap->harr[0] = minHeap->harr[minHeap->size - 1];
    minHeap->size--;
    Heapify(minHeap, 0);
    return min;
}

void Insert(Heap minHeap, ll val)
{
    minHeap->size++;
    ll i = minHeap->size - 1;
    while (i>0 && (val < minHeap->harr[(i - 1) / 2]))
    {
        minHeap->harr[i] = minHeap->harr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->harr[i] = val;
}

void HeapifyHeap(Heap minHeap)
{
    ll n = minHeap->size - 1;
    ll i;
    for (i = (n - 1) / 2; i >= 0; i--)
        Heapify(minHeap, i);
}

Heap CreateMinHeap(ll arr[], ll size)
{
    Heap minHeap = InitMinHeap(size);
    // minHeap->harr = (ll*)malloc(siz

    for (ll i = 0; i < size; i++)
        minHeap->harr[i] = arr[i];
    minHeap->size = size;
    HeapifyHeap(minHeap);
    return minHeap;
}

void print(Heap minHeap)
{
    for (int i = 0; i < minHeap->size; i++)
    {
        printf("%lld ", minHeap->harr[i]);
    }
}

ll minCost(ll arr[], ll n)
{
    ll cost = 0;
    Heap minHeap = CreateMinHeap(arr, n);
    while (minHeap->size >= 2)
    {
        ll min_1 = ExtractMinimun(minHeap);
        ll min_2 = ExtractMinimun(minHeap);

        cost += (min_1 + min_2);
        Insert(minHeap, min_1 + min_2);
    }
    return cost;
}

int main()
{
    ll L, D;
    scanf("%lld %lld", &L, &D);
    ll l[D];
    for (ll i = 0; i < D; i++)
    {
        scanf("%lld", &l[i]);
    }
    // ll l[]={1,-2,-3,2,3};
    // ll D = sizeof(l)/sizeof(ll);
    // Heap H = CreateMinHeap(l, D);
    printf("%lld\n", minCost(l, D));
    return 0;
}