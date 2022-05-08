#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int main(){
    ll N, M;
    scanf("%lld", &N);
    scanf("%lld", &M);

    ll P[N], ans[N - M + 1];

    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &P[i]);
    }  

    ll temp1;

    for(int i = 0; i < N - M + 1 ; i++)
    {
        ll temp = P[i];
        for(int j = 0; j < M; j++)
        {
            if(P[i+j] < temp)
            {
                temp = P[i+j];
            }
        }
        printf("%lld ", temp);
        temp1 = temp;
    }
    printf("%lld", temp1);
    return 0; 
}