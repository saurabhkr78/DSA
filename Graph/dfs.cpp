#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dfsOfGraph(int v, vector<int> adj[])
    {
        vector<int> dfs;                // Vector to store the DFS traversal order.
        vector<bool> visited(v, false); // Vector to keep track of visited nodes.
        stack<int> s;                   // Stack to simulate the recursive call stack for DFS.

        // Start DFS from vertex 0.
        s.push(0);
        visited[0] = true;

        // Process nodes until the stack is empty.
        while (!s.empty())
        {
            int node = s.top();  // Get the node from the top of the stack.
            s.pop();             // Remove the node from the stack.
            dfs.push_back(node); // Add the node to the DFS result vector.

            // Iterate over all adjacent nodes of the current node.
            for (auto it : adj[node])
            {
                if (!visited[it])
                {                       // If the adjacent node has not been visited.
                    visited[it] = true; // Mark the adjacent node as visited.
                    s.push(it);         // Push the adjacent node onto the stack for further exploration.
                }
            }
        }

        return dfs;
    }
};

int main()
{
    int v = 5;
    vector<int> adj[v]; // Adjacency list representation of the graph.

    // Adding edges to the graph.
    adj[0].push_back(1); // Edge from vertex 0 to vertex 1.
    adj[0].push_back(4); // Edge from vertex 0 to vertex 4.
    adj[1].push_back(2); // Edge from vertex 1 to vertex 2.
    adj[1].push_back(3); // Edge from vertex 1 to vertex 3.
    adj[2].push_back(4); // Edge from vertex 2 to vertex 4.
    adj[3].push_back(4); // Edge from vertex 3 to vertex 4.

    Solution sol;                             // Create an instance of the Solution class.
    vector<int> dfs = sol.dfsOfGraph(v, adj); // Perform DFS and get the order of traversal.

    cout << "DFS traversal order: ";
    for (int node : dfs)
    {
        cout << node << " "; // Print each node in the DFS order.
    }
    cout << endl;

    return 0;
}
