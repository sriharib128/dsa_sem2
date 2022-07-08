#include <bits/stdc++.h>
using namespace std;


long long int maximum(long long int x,long long int y,long long int z)
{
    if(x>=y && x>=z)
        return x;
    else if(y>=x && y>=z)
        return y;
    else if(z>=x && z>=y)
        return z;
}
int main()
{
    int N;  
    scanf("%d",&N);
    long long int ability[N];
    long long int p[N];
    long long int q[N];
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&ability[i]);
        p[i]=ability[i];
        q[i]=0;
    }
    vector <pair<pair<long long int,long long int>,int>> c;//connection
    for(int i=1;i<=(N-1);i++)
    {
        long long int a,b;
        scanf("%lld %lld",&a,&b);
        c.push_back({{a,i},b});
    }
    
    for(int i=c.size()-1;i>=0;i--)
    {
        if(c[i].second==0)
        {
            p[c[i].first.first]+=q[c[i].first.second];
            long long int l,m;
            l=p[c[i].first.second]+q[c[i].first.first];
            m=q[c[i].first.second]+q[c[i].first.first];
            q[c[i].first.first] = maximum(l,m,-1);
        }

        else if(c[i].second==1)
        {
            q[c[i].first.first]+=q[c[i].first.second];
            long long int l,m,n;
            l= p[c[i].first.first]+p[c[i].first.second];
            m=p[c[i].first.first]+ q[c[i].first.second];
            n= p[c[i].first.second]+q[c[i].first.first];
            p[c[i].first.first] = maximum(l,m,n);
        }

        else if(c[i].second==2)
        {
            q[c[i].first.first]+=q[c[i].first.second];
            long long int l,m;
            l= p[c[i].first.first]+q[c[i].first.second];
            m=p[c[i].first.second]+q[c[i].first.first];
            p[c[i].first.first] = maximum(l,m,-1);
        }
    }
    long long int ans = maximum(p[c[0].first.first],q[c[0].first.first],-1);
    printf("%lld",ans);
}