#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++; // Count frequencies
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        minh.push(make_pair(it->second, it->first)); // Push (frequency, element)
        if (minh.size() > k) {
            minh.pop(); // Maintain heap size to at most k
        }
    }

    vector<int> v;
    while (!minh.empty()) {
        v.push_back(minh.top().second); // Collect elements
        minh.pop();
    }

    // Sort the result vector
    sort(v.begin(), v.end());

    // Print results
    for (auto it : v) {
        cout << it << " " << endl;
    }

    return 0;
}
