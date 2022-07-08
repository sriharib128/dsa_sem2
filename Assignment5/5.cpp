#include <bits/stdc++.h>
using namespace std;

typedef vector<pair< long long int, pair<int,pair<long long int , long long int>> > >cod;//(x,(node,(x,y)));

typedef pair<long long int,long long int> pi;

typedef vector<pair<long long int , int>> ver;//(weight , node)

long long int mod(long long int x)
{
    if(x<0)
        x=x*(-1);
    return x;
}

long long int weight(pi p1,pi p2)
{
    long long int a = mod(p1.first - p2.first);
    long long int b = mod(p1.second - p2.second);

    if(a>b)
        return b;
    return a;

}


int main()
{   
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int N;
        scanf("%d",&N);
        cod vx,vy;
        for(int i=0;i<N;i++)
        {
            long long int x,y;
            scanf("%lld %lld",&x,&y);
            printf("%d  -  (%lld,%lld)\n",i,x,y);
            vx.push_back({x,{i,{x,y}}});
            vy.push_back({y,{i,{x,y}}});
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        ver vertex[N+1];

        for(int i=0;i<N-1;i++)
        {   
            long long int x_1=vx[i].second.second.first;
            long long int y_1=vx[i].second.second.second;
            int i_1 = vx[i].second.first;

            long long int x_2=vx[i+1].second.second.first;
            long long int y_2=vx[i+1].second.second.second;
            int i_2 = vx[i+1].second.first;

            long long int temp = weight({x_1,y_1},{x_2,y_2});

            vertex[i_1].push_back({temp,i_2});
            vertex[i_2].push_back({temp,i_1});
        }

        for(int i=0;i<N-1;i++)
        {   
            long long int x_1=vy[i].second.second.first;
            long long int y_1=vy[i].second.second.second;
            int i_1 = vy[i].second.first;

            long long int x_2=vy[i+1].second.second.first;
            long long int y_2=vy[i+1].second.second.second;
            int i_2 = vy[i+1].second.first;

            long long int temp = weight({x_1,y_1},{x_2,y_2});
            int flag=0;
            for(int j=0;j<vertex[i_1].size();j++)
            {
                if(vertex[i_1][j].second==i_2)
                    flag =1;
            }
            if(flag==0)
            {
                vertex[i_1].push_back({temp,i_2});
                vertex[i_2].push_back({temp,i_1});
            }
        }
        
        for(int i=0;i<N;i++)
        {
            printf("%d",i);
            for(int j=0;j<vertex[i].size();j++)
                printf("\t>(%lld,%d)",vertex[i][j].first,vertex[i][j].second);
            printf("\n");

        }

        //PRIMS ALGORITHMS
        int visited[100005] ={};

        // priority_queue <pair<long long int ,int>> pq;//(weight ,node)
        priority_queue<pair<long long int ,int>, vector<pair<long long int ,int>>, greater<pair<long long int ,int>> > pq;

        long long int ans =0;
        pq.push({0,0});
        int vis=0;
        while(pq.size()!=0)
        {   
            long long int cur_weight = pq.top().first;
            int cur_node = pq.top().second;
            pq.pop();
            // printf("cur = (%lld,%d)\n",cur_weight,cur_node);
            
            
            if(visited[cur_node]==1)
            {   
                // printf("\t>already visited\n");
                continue;
            }


            ans= ans+cur_weight;
            // printf("\t> added it to sum=%lld\n",ans);
            visited[cur_node]=1;
            vis++;
            if(vis>=N)
                break;


            for(int i=0;i<vertex[cur_node].size();i++)
            {
                if(visited[vertex[cur_node][i].second]!=1)
                {
                    pq.push({vertex[cur_node][i].first,vertex[cur_node][i].second});
                    // printf("\t\t>added (%lld,%d)\n",vertex[cur_node][i].first,vertex[cur_node][i].second);
                }
            }
        }
        printf("%lld==============================================================\n",ans);
    }
    return 0;
}