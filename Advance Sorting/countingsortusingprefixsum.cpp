#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMax(vector<int> &arr)
{
    int mx = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    { // Start loop from the second element
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(vector<int> &arr)
{
    int n = arr.size();
    int mx = findMax(arr);
    vector<int> count(mx + 1, 0);
    vector<int> output(n);

    // Count the occurrences of each element
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Calculate prefix sum
    for (int i = 1; i <= mx; i++)
    { // Start from 1 to avoid accessing count[-1]
        count[i] += count[i - 1];
    }

    // Place the elements in the output array in sorted order
    ////place the elements in output array in sorted order by reverse loop in original array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i]; // output[count[arr[i]]-1]: arr[i]=5,count[5]=8,output[8-1=7] par 5 ko daalo joki correct position hai
        count[arr[i]]--;                    // Decrease count for the current element
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    vector<int> arr = {4, 3, 1, 5, 3, 1, 3, 5};

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    countSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
