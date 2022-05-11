#include <stdio.h>
#include <stdlib.h>

void printBinary(int num){

	for(int i=64 ; i>=0; i--) // prints upto 11 bit number
		printf("%d",(num>>i)&1);	
    printf("\n");
}
long long int no_zeros(long long int a)
{
    long long int ct =-1;
    for(int i =0;i<=64;i++)
    {
        ct++;
        if(a&(1LL<<i))
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
    for(int i=60;i<=63;i++)
    {
        printf("%d - %lld - ",i,no_zeros(power_two(i)));
        printf("%lld  = ",power_two(i));
        printBinary(power_two(i));
    }
}
