#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {1, 1, 1, 1, 2, 4, 4, 4, 5, 10, 7};
    vector<int> v2 = {1, 1, 2, 1, 4, 4, 7};

    unordered_map<int, int> m;
    vector<int> ans;
    for (auto x : v1)
        m[x]++;
    for (auto y : v2)
    {
        auto it = m.find(y);

        if (it != m.end())
        {

            ans.push_back(y);
            m[y]--;
        }
    }

    for (auto z : ans)
    {
        cout << z << " ";
    }
    return 0;
}