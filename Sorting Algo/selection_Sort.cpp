#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{5, 9, 8, 2, 1};
    for (int i = 0; i < v.size() - 1; i++) {
        int min_idx = i; // Initialize the minimum index
        for (int j = i + 1; j < v.size(); j++) { // Iterate over the unsorted part
            if (v[j] < v[min_idx]) { // Update min_idx if a smaller element is found
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        swap(v[i], v[min_idx]);
    }

    for (auto x : v) {
        cout << x << " "; 
    }
    return 0;
}
