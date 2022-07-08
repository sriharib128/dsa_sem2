#include <bits/stdc++.h>
using namespace std;
#define MAX1 50001
#define MAX2 1001
int d[MAX1][MAX2];

void dfs(vector<int> *adjacencylist, int u, int parent, int k, int *no_of_flights)
{
    d[u][0] = 1;
    for (vector<int>::iterator it = adjacencylist[u].begin(); it != adjacencylist[u].end(); it++)
    {
        if ((*it) == parent)
        {
            continue;
        }

        dfs(adjacencylist, (*it), u, k, no_of_flights);

        for (int j = 1; j <= k; j++)
        {
            (*no_of_flights) += d[(*it)][j - 1] * d[u][k - j];
        }
        for (int j = 1; j <= k; j++)
        {
            d[u][j] += d[(*it)][j - 1];
        }
    }
}

int main()
{
    int no_of_testcases;
    cin >> no_of_testcases;

    for (int i = 0; i < no_of_testcases; i++)
    {
        int no_of_nodes;
        int required_distance; // k
        cin >> no_of_nodes >> required_distance;
        vector<int> adjacencylist[no_of_nodes + 1];

        for (int j = 0; j < no_of_nodes - 1; j++)
        {
            int x;
            int y;
            cin >> x >> y;
            adjacencylist[x].push_back(y);
            adjacencylist[y].push_back(x);
        }

        int no_of_flights = 0;

        dfs(adjacencylist, 1, 0, required_distance, &no_of_flights);

        cout << no_of_flights;
    }
    cout << endl;