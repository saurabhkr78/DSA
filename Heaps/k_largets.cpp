// brute force --sort

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minh;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Insert elements into the min-heap
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);

        // Ensure the heap size does not exceed 'k'
        if (minh.size() > k)
        {
            minh.pop();
        }
    }

    // Print the 'k' largest elements in ascending order
    vector<int> result;
    while (!minh.empty())
    {
        result.push_back(minh.top());
        minh.pop();
    }
    // The elements are popped in ascending order from the min-heap
    reverse(result.begin(), result.end()); // Reverse to get descending order
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
