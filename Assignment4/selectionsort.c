#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

void swap(ll *x, ll *y)
{
    ll t = *x;
    *x = *y;
    *y = t;
}


int main()
{
    int size =5;
    long long int arr[]={0,4,2,3,4};
    ll i, j, min_idx;
    for (i = 0; i < size; i++)
    {
        int min_value=arr[i];
        min_idx=i;
        for (j = i+1; j < size; j++)
        {
            if (arr[j] < min_value)
            {
                min_idx = j;
                min_value=arr[j];
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
    for(int i=0;i<size;i++)
        printf("%lld ",arr[i]);
}