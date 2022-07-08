#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[50005][1001];

void dfs(vector<ll> V[], ll node, ll p, ll k, ll* ans)
{
    arr[node][0] = 1;
    ll size = (ll)V[node].size();
    ll i = 0;
    while(i<size)
    {
        ll temp = V[node][i];
        if (temp != p)
        {
            dfs(V, temp, node, k, ans);

            for (ll j = 1; j <= k; j++)
            {
                *ans = *ans + (arr[temp][j - 1] * arr[node][k - j]);
            }

            for (ll j = 1; j <= k; j++)
            {
                arr[node][j] += arr[temp][j - 1];
            }
        }
        i++;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        ll i, j;
        ll N, k;
        cin >> N >> k;
        vector<ll> V[N + 1];
        for (i = 0; i < N - 1; i++)
        {
            ll a, b;
            cin >> a >> b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        for(i=0; i<N+1; i++)
        {
            for(j=0; j<=k; j++)
            {
                arr[i][j] = 0;
            }
        }
        if(k==0)
        {
            cout << N << endl;
            continue;
        }
        dfs(V, 1, 0, k, &ans);
        cout << ans << endl;
    }
}