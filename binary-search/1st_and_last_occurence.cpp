#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(int arr[], int n, int x)
{
    int i = 0, j = n - 1;
    int res = -1;
    while (i <= j)
    {
        int mid = (i + (j - i) / 2);
        if (arr[mid] == x)
        {                // If element is found
            res = mid;   // Store the index
            j = mid - 1; // Continue searching in the left half
        }
        else if (arr[mid] > x)
        {
            j = mid - 1; // search in left half
        }
        else if (arr[mid] < x)
        {
            i = mid + 1; // search in right
        }
    }
    return res;
}
int findLastOccurence(int arr[], int n, int x)
{
    int i = 0, j = n - 1;
    int res = -1;
    while (i <= j)
    {
        int mid = (i + (j - i) / 2);
        if (arr[mid] == x)
        {                // If element is found
            res = mid;   // Store the index
            i = mid + 1; // Continue searching in the right half
        }
        else if (arr[mid] > x)
        {
            j = mid - 1; // search in left half
        }
        else if (arr[mid] < x)
        {
            i = mid + 1; // search in right
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    int firstAppearance = findFirstOccurrence(arr, n, x);
    int lastAppearance = findLastOccurence(arr, n, x);
    cout << "first Appearance:" << firstAppearance << " " << "last Apperance:" << lastAppearance << endl;
    return -1;
}
