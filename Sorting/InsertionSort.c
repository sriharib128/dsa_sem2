//Assume P-1 elements are already sorted
// continuously move the elements from p-1 to 0 to the right until u can place pth position
//  temp = A[p]; 
//A[i]<temp;
// Best case ==> O(N);
// Worst Case ==> O(N^2);
// Avg Case ==> O(N^2);

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[]={0,1,2,-1,-2,5,10};
    int n = sizeof(A)/sizeof(int);
    
    for(int i=0;i<n-1;i++)
    {   
        int temp = A[i+1];
        int j;
        for(j=i+1;j>0;j--)
        {
            if(A[j-1]<=temp)
                break;
            else
                A[j]=A[j-1];
        }
        A[j]=temp;
    }

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
}