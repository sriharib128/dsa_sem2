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
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                int temp;
                scanf("%d",&temp);
                A[i][j]=temp;
            }
            qsort(&A[i][0],k,sizeof(int),compare);
            // for(int j=0;j<k;j++)
            // {
            //     printf("%d ",A[i][j]);
            // }
            // printf("\n");
        }
        

        int* array1 = &A[0][0];
        int* array2 = &A[1][0];

        int  array3[k];
        int s =2;//section
        while(s<=k)
        {
            heap H = CreateHeap(k*k);
            int MAP[k][k];
            
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                    MAP[i][j]=0;

            long long int *pair = (long long int *)malloc(sizeof(long long int)*3);
            pair[0]=array1[0]+array2[0];
            pair[1]=0;
            pair[2]=0;
            Insert(H,pair);
            MAP[0][0] = 1;

            int count =0;
            while(count <k && SizeOfHeap(H) >=1)
            {
                long long int * temp  = DeleteMin(H);
                array3[count++]=temp[0];
                int i= temp[1];
                int j= temp[2];
                free(temp);
                // printf("%d(%d) + %d(%d) = %d(%d)\n",array1[i],i,array2[j],j,array3[count-1],count-1);
                // printf("--------------\n");
                if(i+1<k)
                {   
                    long long int *pair = (long long int *)malloc(sizeof(long long int)*3);
                    pair[0]=array1[i+1]+array2[j];
                    pair[1]=i+1;
                    pair[2]=j;

                    if(MAP[i+1][j]==0)
                    {   
                        Insert(H,pair);
                        MAP[i+1][j]=1;
                    }
                }
                if(j+1 < k)
                {   
                    long long int *pair = (long long int *)malloc(sizeof(long long int)*3);
                    pair[0]=array1[i]+array2[j+1];
                    pair[1]=i;
                    pair[2]=j+1;

                    if(MAP[i][j+1]==0)
                    {
                        MAP[i][j+1]=1;
                        Insert(H,pair);
                    }
                }
            }
            
            // printf("\n");
            destroy(H);
            for(int i=0;i<k;i++)
            {
                array1[i]=array3[i];
            }
            array2 = A[s++];
        }
        for(int i=0;i<k;i++)
            printf("%d ",array3[i]);
        printf("\n");
    }
    return 0;   
}