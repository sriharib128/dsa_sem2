// #include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void printBinary(int num){
// 	for(int i= 10 ; i>=0; i--) // prints upto 11 bit number
// 		printf("%d",(num>>i)&1);	
//     printf("\n");
// }
long long int power_two(long long int power)
{
    long long int i=1;
    for(long long int j=0;j<power;j++)
        i=i<<1;
    return i;
}
long long int no_zeros(long long int a)
{
    long long int ct =-1;
    for(int i =0;i<=63;i++)
    {
        ct++;
        if(a&(1<<i))
            break;
    }
    return ct;
}

long long int Up(long long int n,long long int current_room)
{
    if(current_room ==((n/2) + 1))
        return current_room;
    // printf("%lld ==>",current_room);
    long long int level =no_zeros(current_room);
    long long int diff = power_two(level);
    long long int temp = current_room +(diff);
    if(no_zeros(temp) != (level+1))
        temp = current_room - (diff);
    current_room = temp;
    // printf("%lld\n",current_room);    
    return current_room;
    // if(temp>(n+1)/2)
}
long long int Left(long long int n,long long int current_room)
{
    long long int level  = no_zeros(current_room);
    long long int diff = power_two(level-1);
    // printf("%lld ==>",current_room);
    if(!(current_room&1))
        current_room = current_room - diff;
    // printf("%lld\n",current_room);    
    return current_room;
}
long long int Right(long long int n,long long int current_room)
{
    long long int level  = no_zeros(current_room);
    long long int diff = power_two(level-1);
    // printf("%lld ==>",current_room);
    if(!(current_room&1))
        current_room = current_room + diff;
    // printf("%lld\n",current_room);    
    return current_room;
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int initial;
        scanf("%lld",&initial);
        char temp[100010];
        scanf("%s",temp);
        // printf("%s\n",temp); 
        long long int current_room = initial;
        for(long long int i=0;i<strlen(temp);i++)
        {
            if(temp[i]== 'U')
                current_room = Up(n,current_room);
            else if(temp[i]=='L')
                current_room = Left(n,current_room);
            else if(temp[i]=='R')
                current_room = Right(n,current_room);
        }
        printf("%lld\n",current_room);
        // printf("--------------------------------------------\n");
    }
    return 0;
}
