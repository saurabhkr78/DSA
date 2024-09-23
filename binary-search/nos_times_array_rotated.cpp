#include <bits/stdc++.h>
using namespace std;

int findMinIndex(int arr[], int n)
{
    int i = 0, j = n - 1;
    
    while (i <= j)
    {
        if (arr[i] <= arr[j]) // If the array is already sorted
            return i; // The first element is the minimum

        int mid = i + (j - i) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        // Check if mid is the minimum element
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            return mid;
        }

        // Decide whether to move left or right
        if (arr[i] <= arr[mid]) // Left half is sorted
        {
            i = mid + 1;
        }
        else // Right half is sorted
        {
            j = mid - 1;
        }
    }
    
    return -1; // This shouldn't be reached in a valid rotated array
}

int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int minIndex = findMinIndex(arr, n);
    
    if (minIndex != -1)
        cout << "Minimum element is at index so no of time an array is rotated=" << minIndex << "\n";
    else
        cout << "Array is not rotated sorted\n";
    
    return 0;
}
