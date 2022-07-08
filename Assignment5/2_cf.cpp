#include<bits/stdc++.h>
using namespace std;
int dist[50005][1005];//dist[u][v] ==> no of nodes with distance v from u.

void dfs(int node,int parent,int K,vector <int> vertex[],long long int *ans)
{
    dist[node][0]=1;
    for(int i=0;i<vertex[node].size();i++)
    {

        if(node!=parent)
        {

            dfs(vertex[node][i],node,K,vertex,ans);
            printf("%d\n",__LINE__);

            for(int j=1;j<=K;j++)
            {
                dist[node][j] =dist[node][j]+ dist[vertex[node][i]][j-1];//dist j from node to dist j-1 from its child
            }
        }
    }
    printf("%d\n",__LINE__);

    *ans = (*ans) + dist[node][K];
    long long int pairs = 0;
    for(int i=0;i<vertex[node].size();i++)
    {
        if(vertex[node][i]!=parent)
        {
            for(int j=1;j<=K-1;j++)
                pairs +=dist[node][j-1]*(dist[node][K-j] - dist[vertex[node][i]][K-j-1]);
        }
    } 
    *ans = (*ans) +  (pairs/2);
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
        long long int ans;
        ans =0;
        dfs(1,-1,K,vertex,&ans);
        printf("%d\n",__LINE__);

        printf("%lld\n",ans);
    }
    
}