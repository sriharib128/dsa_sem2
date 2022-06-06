#include "heap.h"

int compare (const void * a, const void * b) 
{
    int c=*(int*)a;
    int d = *(int*)b;

    if(c>d)
        return 1;
    else if(c==d)
        return 0;
   else
        return (-1);
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int k;
        scanf("%d",&k);
        int A[k][k];
        // heap H[k];
        // for(int i =0;i<k;i++ )
        // {
        //     H[i]=CreateHeap(k);
        // }
        long long int MINSUM =0;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                int temp;
                scanf("%d",&temp);
                // Insert(H[i],temp);
                A[i][j]=temp;
            }
            qsort(&A[i][0],k,sizeof(int),compare);
            for(int j=0;j<k;j++)
            {
                printf("%d ",A[i][j]);
            }
            printf("\n");
            // MINSUM = MINSUM + DeleteMin(H[i]);
        }
        
    
        printf("\n");
    }
    return 0;   
}