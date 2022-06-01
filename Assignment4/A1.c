#include <stdio.h>
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

int main()
{
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        selectionsort(a, n);
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
        selectionsort(f1, j);
        ll max = f1[j - 1];
        ll k = 0;
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