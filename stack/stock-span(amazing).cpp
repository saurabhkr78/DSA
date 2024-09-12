// find consective samller equal to before it
// store ngl index
// push (i-ngl) index in vector

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> v(n);        // To store the index of the next smaller element
    stack<pair<int, int>> s; // Stack to keep track of elements and their indices

    // Traverse the array from left to right
    for (int i = 0; i < n; i++)
    {
        // Check and pop elements from the stack if they are greater than or equal to arr[i]
        while (!s.empty() && s.top().first >= arr[i])
        {
            s.pop();
        }

        // If stack is empty, no smaller element found
        if (s.empty())
        {
            v[i] = -1;
        }
        else
        {
            v[i] = s.top().second; // Index of the next smaller element
        }

        // Push the current element and its index onto the stack
        s.push({arr[i], i});
    }

    // Convert indices to distances
    for (int i = 0; i < n; i++)
    {
        if (v[i] != -1)
        {
            v[i] = i - v[i];
        }
    }

    // Print the result
    cout << "Distances to the Next Smaller Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
