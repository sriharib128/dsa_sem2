#include "heap.h"

int main()
{
    int L,D;
    scanf("%d %d",&L,&D);
    heap H = CreateHeap(D);

    for(int i=0;i<D;i++)
    {
        int l;
        scanf("%d",&l);
        Insert(H,l);
    }
    long long int ans =0;
    while (SizeOfHeap(H)!= 1)
    {
        int a = DeleteMin(H);
        int b = DeleteMin(H);
        ans = ans + a+b;
        Insert(H,(a+b));
    }
    printf("%lld",ans);
    return 0;
}