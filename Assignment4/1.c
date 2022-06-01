#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximum (const void * a, const void * b) 
{
    int c=*(int*)a;
    int d = *(int*)b;
    return (c-d);
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int A[n+1];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        A[n]=INT_MAX;
        qsort(A, n+1 , sizeof(int), maximum);
        int max_number[10000][2] ={};
        int j=0;
        for(int i=0;i<n;i++)
        {   
            int count =1;
            while(A[i]==A[i+1])
            {
                i++;
                count++;
                if(i==(n-1))
                    break;
            }
            max_number[j][0]=A[i];
            max_number[j][1]=count;
            // if(max_number[j][0]!=0)
            //     printf("(%d-%d)\n",max_number[j][0],max_number[j][1]);
            j++;
        }
        // int unique_elements = j;
        // int temp=0;
        int max_freq=(-1);
        for(int i=0;i<j;i++)
        {
            if(max_number[i][1]>max_freq)
            {
                max_freq=max_number[i][1];
            }
        }
        int max_freq_count=0; // no of unique elements with max frequency

        for(int i=0;i<j;i++)
        {
            if(max_number[i][1]==max_freq)
                max_freq_count++;
        }
        
        int remaining = n - (max_freq_count * max_freq);
        int ans;
        if(max_freq == 1)
            ans =n;
        else
            ans = (remaining/(max_freq-1)) + max_freq_count -1;
        printf("%d\n",ans);

        /*
        1 1 1 1     2 2 2 3 4 5 6 7
        1  236   1   247  1   25  1
        
        12 12 12 12 3 4 5 6 7
        12 3 6 12 4 7 12 5 12  
        */

    }
    return 0;
}
/*
1 1 1 1 2 2 2 2 3 4 5 6 
12 12 12 12     3 4 5 6 
n-max_freq*count;
elements/(max_freq-1) + count-1;
*/
