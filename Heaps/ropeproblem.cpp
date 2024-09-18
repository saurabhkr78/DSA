#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        long long tcost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq; // Min Heap

        // Insert all ropes lengths into the priority queue
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        // Continuously connect the two smallest ropes
        while (pq.size() >= 2)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            long long sum = first + second;
            tcost += sum;

            pq.push(sum);
        }

        return tcost;
    }
};

int main()
{
    Solution sol;

    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);

    long long result = sol.minCost(arr, n);

    cout << "Minimum cost to connect ropes: " << result << endl;

    return 0;
}