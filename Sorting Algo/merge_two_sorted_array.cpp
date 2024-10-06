#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v1{1, 2, 3, 4};
    vector<int>v2{2, 3, 4, 4, 7, 10};
    vector<int> ans(v1.size() + v2.size());
    int i = 0, j = 0, k = 0;

    while (i < v1.size() and j < v2.size()) {
        if (v1[i] < v2[j]) {
            ans[k++] = v1[i];
            i++;
        }
        else if (v1[i] > v2[j]) {
            ans[k++] = v2[j];
            j++;
        }
        else {  // If both elements are equal
            ans[k++] = v1[i];
            ans[k++] = v2[j];
            i++;
            j++;
        }
    }

    // For the remaining elements in v1
    while (i < v1.size()) {
        ans[k++] = v1[i];
        i++;
    }

    // For the remaining elements in v2
    while (j < v2.size()) {
        ans[k++] = v2[j];
        j++;
    }

    // Print the merged array
    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}
