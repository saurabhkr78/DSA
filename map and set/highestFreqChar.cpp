#include <bits/stdc++.h>
using namespace std;

int main() {
    string st;
    cin >> st;
    unordered_map<char, int> m;
    vector<char> ans;

    // Count the frequency of each character
    for (auto x : st) {
        m[x]++;
    }

    int maxfreq = 0;

    // Find the maximum frequency
    for (auto it = m.begin(); it != m.end(); it++) {
        maxfreq = max(maxfreq, it->second);
    }

    // Collect all characters with maximum frequency
    for (auto it = m.begin(); it != m.end(); it++) {
        if (maxfreq == it->second) {
            ans.push_back(it->first);
        }
    }

    // Sort the characters
    sort(ans.begin(), ans.end());

    // Print the results
    for (auto c : ans) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
