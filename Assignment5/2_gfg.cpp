#include<bits/stdc++.h>
using namespace std;
int dist[50005][1005];//dist[u][v] ==> no of nodes with distance v from u.
long long int ans;

void dfs(int node,int parent,int K,vector <int> vertex[])
{
    dist[node][0] = 1;
    for (int i=0;i<vertex[node].size();i++) 
    {
        if (vertex[node][i]== parent)
            continue; 

        dfs(vertex[node][i], node,K,vertex);
 
        for (int j = 1; j <=K; j++)
            ans = (ans) + dist[vertex[node][i]][j - 1] * dist[node][K - j];

        for (int j = 1; j <= K; j++)
            dist[node][j] += dist[i][j - 1];
    }
}

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
        ans=0;
        memset(dist,0,50005*1005);
        dfs(1,-1,K,vertex);
        printf("%lld\n",ans);
        ans=0;
    }
    
}