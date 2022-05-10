#include <stdio.h>
#include <stdlib.h>

int isLite(int left,int current , int right)
{
    if(left !=0 && right !=0)
    {
        if((left < current) && (current < right))
            return 1;
        else if((left > current) && (current > right))
            return 1;
        else 
            return 0;   
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int left, current,right;
        scanf("%d %d %d",&left,&current,&right);
        int flag = isLite(left,current,right);
        if(flag)
            printf("it is a lite tree\n");
        else
            printf("it is not a lite tree\n");
    }
    
}