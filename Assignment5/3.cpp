#include <bits/stdc++.h>
using namespace std;


typedef vector<int> ver;

int visited[100001]={};

void dfs(int checkpoint,int parent,ver vertex[])
{
    if(visited[checkpoint]==1)
        return;
    visited[checkpoint]=1;
    for(int i=0;i<vertex[checkpoint].size();i++)
    {
        if(vertex[checkpoint][i]!=parent)
            dfs(vertex[checkpoint][i],checkpoint,vertex);            
    }
    return;
}

int visitedall(int N)
{
    int sum =0;
    for(int i=0;i<=N;i++)
    {
        sum +=visited[i];
    }
    if(sum==N)
        return 1;
    else
     return 0;
}

int main()
{
    int N;
    scanf("%d",&N);
    ver vertex[N+1];
    ver vertex_reverse[N+1];

    int m;
    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        vertex[a].push_back(b);
        vertex_reverse[b].push_back(a);
    }
    dfs(1,-1,vertex);
    int flag=0;
    if(visitedall(N)==1)
        flag=1;
    memset(visited,0,sizeof(int)*(N+1));

    dfs(1,-1,vertex_reverse);
    if(visitedall(N)==1)
    {
        if(flag==1)
        {
           printf("YES");
           return 0;
        }   
    }
    printf("NO");
    return 0;
}
