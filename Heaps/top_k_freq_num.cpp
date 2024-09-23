#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        minh.push(make_pair(it->second, it->first)); // (frequency, element)
        if (minh.size() > k) {
            minh.pop();//to maintain heap size
    }
    }
    vector<int> v;
    while (!minh.empty()) {
        v.push_back(minh.top().second); 
        minh.pop();
    }

    sort(v.begin(), v.end());

    for (auto it : v) {
        cout << it << " " << endl;
    }

    return 0;
}
