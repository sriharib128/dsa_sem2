#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> ver;//(weight , node)
typedef pair<int,int> pi;

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    ver vertex[n+1];

    for(int i=0;i<k;i++)
    {  
        int mess;
        scanf("%d",&mess);
        vertex[0].push_back({0,mess});
    }

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        vertex[u].push_back({w,v});
        vertex[v].push_back({w,u});
    }

    int Distance[n+1];
    int visited[n+1];
    for(int i=0;i<n+1;i++)
    {
        Distance[i]=LONG_LONG_MAX;
        visited[i]=0;
    }
    
    priority_queue<pi,vector<pi>,greater<pi>> heap;
    heap.push({0,0});
    
    while(heap.size()!=0)
    {   
        int checkpoint = heap.top().second;
        int weight = heap.top().first;
        
        heap.pop();

        if(visited[checkpoint]==1)
            continue;
        visited[checkpoint]=1;
        for(int i=0;i<vertex[checkpoint].size();i++)
        {   
            // printf("hi\n");
            pi temp = vertex[checkpoint][i];
            if(Distance[temp.second]>=(temp.first+weight))
            {    
                Distance[temp.second]=temp.first+weight;
                heap.push({Distance[temp.second],temp.second}); 
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",Distance[i]);
}