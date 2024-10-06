#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int pivotelement)
{
    int i = 0, j = 0;
    while (i < v.size() and j < v.size())
    {
        if (v[j] > pivotelement)
        {
            j++;
        }
        else
        {
            swap(v[i], v[j]);
            i++;
            j++;
        }
    }
    return i - 1; // Return the partition index
}

void quick_sort(vector<int> &v, int l, int h)
{
    if (l == h)
        return;
    if (l > h)
        return;

    int pivotelement = v[h];
    int pivotindex = partition(v, pivotelement); // Partition the array

    quick_sort(v, l, pivotindex - 1); // Sort left partition
    quick_sort(v, pivotindex + 1, h); // Sort right partition
}

int main()
{
    vector<int> v{8, 4, 11, 13, 2, 6, 1, 9};
    quick_sort(v, 0, v.size() - 1);
    for (auto x : v)
    {
        cout << x << " ";
    }
    return 0;
}
