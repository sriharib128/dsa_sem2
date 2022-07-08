#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define N 50005
#define ll long long

ll n, k;
ll d[N][1002];
ll ans;
void DFS(ll v, ll p,vector<ll> gr[])
{
    d[v][0] = 1;
    for (auto i : gr[v]) 
    {
        if (i != p) 
        {
            DFS(i, v,gr);
            for (int j = 1; j <= k; j++)
                ans += d[i][j - 1] * d[v][k - j];

            for (int j = 1; j <= k; j++)
                d[v][j] += d[i][j - 1];
        }
    }
}
int main()
{   
    ll t;
    cin>>t;
    while(t>0)
    {   
        ans=0;
        cin>>n;
        cin>>k;
        if(k==0)
        {
            cout<<n<<endl;
            continue;
        }
        vector<ll>gr[n+1];
        ll a=0,b=0;
        for(ll i=0;i<n-1;i++)
        {
            cin>>a>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        memset(d,0,(N*1002)*sizeof(ll));
        DFS(1,0,gr);
        cout<<ans<<endl;
        t--;
    }
    return 0;

}