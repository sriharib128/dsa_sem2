// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define N 50001

int n, k;

int d[N][1005];
int sum = 0;

void dfs(vector<int> gr[N], int v, int par)
{
    d[v][0] = 1;
    int i = 0;
    while (i < gr[v].size())
    {
        if (gr[v][i] == par)
        {
            continue;
        }

        if (gr[v][i] != par)
        {
            dfs(gr, gr[v][i], v);

            int j = 1;
            while (j <= k)
            {
                sum += d[gr[v][i]][j - 1] * d[v][k - j];
                j++;
            }

            int a = 1;

            while (a <= k)
            {
                d[v][a] += d[gr[v][i]][a - 1];
                a++;
            }
        }
        i++;
    }
}

int main()
{
    vector<int> gr[N];
    int m;
    int x, y;
    scanf("%d", &m);
    while (m)
    {
        scanf("%d %d", &n, &k);

        for (int i = 0; i < n - 1; i++)
        {
            
            scanf("%d", &x);
            scanf("%d", &k);
            gr[x].push_back(y);
            gr[y].push_back(x);
        }

        dfs(gr, 1, 0);
        printf("%d", sum);
        m--;
    }

    return 0;
}