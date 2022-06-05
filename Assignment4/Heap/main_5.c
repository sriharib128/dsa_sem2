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
        heap H[k];
        for(int i =0;i<k;i++ )
        {
            H[i]=CreateHeap(k);
        }
        long long int MINSUM =0;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                int temp;
                scanf("%d",&temp);
                Insert(H[i],temp);
                A[i][j]=temp;
            }
            qsort(&A[i][0],k,sizeof(int),compare);
            for(int j=0;j<k;j++)
            {
                printf("%d ",A[i][j]);
            }
            printf("\n");
            MINSUM = MINSUM + DeleteMin(H[i]);
        }
        printf("===\n");
        printf("%lld\n",MINSUM);
        int no_of_purchases =1;
        while(no_of_purchases<k)
        {   
            long long int temp_maxsum = MINSUM;
            int min = INT_MAX;
            int min_pos =-1;
            for(int i=0;i<k;i++)
            {
                long long int temp_min = FindMin(H[i]) - A[i][0];
                if(temp_min<min)
                {
                    min = temp_min;
                    min_pos = i;
                }
            }
            printf("i=%d => %d ",min_pos,FindMin(H[min_pos]));
            temp_maxsum = MINSUM - A[min_pos][0] +DeleteMin(H[min_pos]);
            printf("%lld\n",temp_maxsum);
            no_of_purchases++;
        }
        printf("\n");
    }
    return 0;   
}