#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int N,K;
        scanf("%d %d",&N,&K);
        vector <int> vertex[N+1];
        for(int i=0;i<N-1;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            vertex[u].push_back(v);
            vertex[v].push_back(u);
        }
        
    }
    
}