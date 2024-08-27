#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    // declare adjecency matrix
    int adj[n + 1][m + 1]; // for smaller value of n and for larger value we ceate adjecency list

    // take edges input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

