#include <bits/stdc++.h>
using namespace std;

typedef vector<pair< long long int, pair<int,pair<long long int , long long int>> > >cod;//(x,(node,(x,y)));

typedef pair<long long int,long long int> pi;

typedef vector<pair<long long int , int>> ver;//(weight , node)

long long int weight(pi p1,pi p2)
{
    return p1.first;
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
            // vertex[vx[i].second.first].push_back({weight(vx[i].second.second.first,vx[i].second.second.second),vx[i].second.first});
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

            vertex[i_1].push_back({temp,i_2});
            vertex[i_2].push_back({temp,i_1});
            // vertex[vx[i].second.first].push_back({weight(vx[i].second.second.first,vx[i].second.second.second),vx[i].second.first});
        }

        

    }
}