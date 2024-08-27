//work as well for directed graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // vector<int> adj[]: An array of vectors where adj[i] holds the list of adjacent nodes (edges) for vertex i.
    vector<int> bfsOfGraph(int v, vector<int> adj[])
    {
        vector<int> bfs;
        vector<bool> visited(v, false); // Using vector<bool> for visited nodes
        queue<int> q;

        q.push(0);         // Assuming BFS starts from node 0
        visited[0] = true; // Adds the starting node (node 0) to the queue and marks it as visited.

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node); // Use push_back to add element to the vector

            for (auto it : adj[node])//Iterates over each neighbor (it) of the current node. adj[node] provides the list of adjacent nodes.
            { // Iterates over all adjacent nodes (neighbors) of the current node
                if (!visited[it])
                {                       // If a neighbor (it) hasn't been visited
                    visited[it] = true; // Marks it as visited
                    q.push(it);         // Adds it to the queue for further exploration.
                }
            }
        }
        return bfs;
    }
};
int main() {
    int v = 5;
    vector<int> adj[v];

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(4);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);

    Solution sol;
    vector<int> bfs = sol.bfsOfGraph(v, adj);

    cout << "BFS traversal order: ";
    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}