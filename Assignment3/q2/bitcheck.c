#include <stdio.h>
#include <stdlib.h>

void printBinary(int num){

	for(int i= 10 ; i>=0; i--) // prints upto 11 bit number
		printf("%d",(num>>i)&1);	
    printf("\n");
}
long long int no_zeros(int a)
{
    long long int ct =-1;
    for(int i =0;i<=31;i++)
    {
        ct++;
        if(a&(1<<i))
            break;
    }
    return ct;
}
long long int power_two(int power)
{
    long long int i=1;
    for(int j=0;j<power;j++)
        i=i<<1;
    return i;
}
int main()
{
    printf("%lld",power_two(20));
}
