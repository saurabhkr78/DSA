// i->row
// j->col
// staricase approach

#include <bits/stdc++.h>
using namespace std;

bool search(int arr[][4], int n, int m, int x, pair<int, int> &result)
{
    int i = 0, j = m - 1; // Start at the top-right corner
    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (arr[i][j] == x)
        {
            result = {i, j};
            return true;
        }
        else if (arr[i][j] > x)
        {
            j--; // Move left
        }
        else
        {
            i++; // Move down
        }
    }
    return false;
}

int main()
{
    int arr[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};
    pair<int, int> result;
    int n = 4, m = 4, x = 29;

    if (search(arr, n, m, x, result))
    {
        cout << "Element found at: (" << result.first << ", " << result.second << ")\n";
    }
    else
    {
        cout << "Element not found.\n";
    }

    return 0;
}
