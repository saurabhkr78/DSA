#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int k = 3;

    priority_queue<pair<int, int>> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push(make_pair(abs(arr[i] - x), arr[i]));
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    while (!maxh.empty())
    {
        cout << maxh.top().second << "";
        maxh.pop();
    }
}
