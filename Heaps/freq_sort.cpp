#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // create a map to store freq
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int, int>> maxh;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        maxh.push(make_pair(it->second, it->first));
    }
    vector<int> v;
    while (!maxh.empty())
    {
        v.push_back(maxh.top().second);
        maxh.pop();
    }
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << "" << endl;
    }
    return 0;
}