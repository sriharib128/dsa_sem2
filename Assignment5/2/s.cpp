#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long
  
const int MAX = 1000;
vector<pair<int, int> > adj1[MAX];
int c[MAX];
bool v[MAX];
  
void DFS(int x, int y, int col)
{
    if (v[x])
        return;
    v[x] = 1;
    if (x == y)
    {
        c[col] = 1;
        return;
    }
  
    for (int i = 0; i < int(adj1[x].size()); i++)
        if (adj1[x][i].second == col)
            DFS(adj1[x][i].first, y, col);
}

int UniColorPaths(int a, int b,int m)
{

    for (int i = 0; i < int(adj1[a].size()); i++)
    {
        DFS(a, b, adj1[a][i].second);
  
        memset(v, 0, sizeof(v));
    }
  
    int cur = 0;
    for (int i = 0; i <= m; i++)
        cur += c[i];
  
    return (cur);
}

int main()
{
    ll n,m;
    cin>>n;
    cin>>m;
    vector<pair<int, int> > adj1[MAX];
    ll a=0,b=0,c=0;
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj1[a].push_back({b,c});
        adj1[b].push_back({a,c});
    }
    ll q;
    cin>>q;
    int a1[q],a2[q];
    for(int i=0;i<q;i++)
    {
        cin>>a1[i]>>a2[i];
    }
    for(ll i=0;i<q;i++)
    {
        cout << UniColorPaths(a1[i], a2[i],m) << endl;
    }
    return 0;
}