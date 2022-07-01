#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> ver;//list of all vertex and inside vertex (value,colour) 


void dfs(int checkpoint , int col,int colours [],int v,int visited [],ver vertex[])
{   
    if(checkpoint==v)
    {   
        colours[col]=1;
        return;
    }
    if(visited[checkpoint]!=0)
        return;

    visited[checkpoint]=1;
    for(int i=0;i<vertex[checkpoint].size();i++)
    {   
        if(vertex[checkpoint][i].second==col)
            dfs(vertex[checkpoint][i].first,col,colours,v,visited,vertex);
    }
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    ver vertex[n+10]; 

    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vertex[a].push_back({b,c});
        vertex[b].push_back({a,c});
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        int colours[1010]={};
        for(int i=0;i<vertex[u].size();i++)
        {   
            int visited [110]={};
            visited[u]=1;
            dfs(vertex[u][i].first,vertex[u][i].second,colours,v,visited,vertex);
            // printf("\n\n");
        }
        int sum =0;
        for(int i=0;i<=m;i++)
        {   
            sum= sum + colours[i];
        }   
        printf("%d\n",sum);
    }
    return 0;
}