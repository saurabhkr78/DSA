// for bigger value of n
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e; // node and edges
    // declare adjecency matrix
    vector<int> adj[n + 1]; // for larger value we ceate adjecency list
    // at each node(i) we are storing an adjacency list
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}