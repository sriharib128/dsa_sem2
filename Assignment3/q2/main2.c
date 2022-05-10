#include "bintree.h"

void printBinary(int num){

	for(int i= 10 ; i>=0; i--) // prints upto 11 bit number
		printf("%d",(num>>i)&1);	
    printf("\n");
}
long long int power_two(int power)
{
    long long int i=1;
    for(int j=0;j<power;j++)
        i=i<<1;
    return i;
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

long long int Up(long long int n,long int current_room)
{
    if(current_room == ((n+1)/2))
        return current_room;
    printf("%lld ==>",current_room);
    long long int level =no_zeros(current_room);
    long long int diff = power_two(level+1);
    long long int temp = current_room +(diff/2);
    if(no_zeros(temp) > (level+1))
        temp = current_room - (diff)/2;
    current_room = temp;
    printf("%lld\n",current_room);    
    return current_room;
    // if(temp>(n+1)/2)
}
long long int Left(long long int n,long int current_room)
{
    long long int level  = no_zeros(current_room);
    long long int diff = power_two(level-1);
    printf("%lld ==>",current_room);
    if(!(current_room&1))
        current_room = current_room - diff;
    printf("%lld\n",current_room);    
    return current_room;
}
long long int Right(long long int n,long int current_room)
{
    long long int level  = no_zeros(current_room);
    long long int diff = power_two(level-1);
    printf("%lld ==>",current_room);
    if(!(current_room&1))
        current_room = current_room + diff;
    printf("%lld\n",current_room);    
    return current_room;
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int ct =-1;
    long long int a=n+1;
    for(int i =0;i<=31;i++)
    {
        ct++;
        if(a&(1<<i))
            break;
    }
    printf("%lld\n",ct);
    // for(int i=0;i<50;i+=2)
    // {
    //     printf("%d  - %lld - ",i,no_zeros(i));
    //     printBinary(i);
    // }
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long int initial;
        scanf("%ld",&initial);
        char temp[100010];
        scanf("%s",temp);
        // printf("%s\n",temp); 
        long long int current_room = initial;
        for(int i=0;i<strlen(temp);i++)
        {
            if(temp[i]== 'U')
                current_room = Up(n,current_room);
            else if(temp[i]=='L')
                current_room = Left(n,current_room);
            else if(temp[i]=='R')
                current_room = Right(n,current_room);
        }
        printf("%lld\n",current_room);
        printf("--------------------------------------------\n");
    }
    return 0;
}
