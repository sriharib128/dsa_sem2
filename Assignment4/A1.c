#include <stdio.h>
#include <stdlib.h>
#define ll long long int

void swap(ll *x, ll *y)
{
    ll t = *x;
    *x = *y;
    *y = t;
}

void selectionsort(ll arr[], ll size)
{
    ll i, j, min_idx;
    for (i = 0; i < size; i++)
    {
        ll min_value = arr[i];
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < min_value)
            {
                min_idx = j;
                min_value = arr[j];
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

int comparision(const void * a, const void *b)
{
    return (*(long long int *)a - *(long long int *)b);
}
int main()
{
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        ll a[n+1];
        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        a[n]=-1;
        // selectionsort(a, n);
        qsort(a,n,sizeof(ll),comparision);
        ll f1[n], f2[n], count = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[i + 1])
            {
                count++;
            }
            else
            {
                f1[j++] = count + 1;
                count = 0;
            }
        }
        // selectionsort(f1, j);
        qsort(f1,j,sizeof(ll),comparision);
        ll max = f1[j - 1];
        f1[j]=-1;
        // ll b=0;
        // for(int i=0;i<j;i++)
        // {
        //     if(f1[i]==max)
        //         b++;
        // }

        ll k = 0;
        count =0;
        for (int i = 0; i < j; i++)
        {
            if (f1[i] == f1[i + 1])
            {
                count++;
            }
            else
            {
                f2[k++] = count + 1;
                count = 0;
            }
        }
        ll b = f2[k - 1];
        if (max == 1)
            printf("%lld", n);
        else
            printf("%lld\n",(((n-(b*max))/(max-1)) + b - 1));
    }
    return 0;
}