#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = size - 1;
    int ele = 6;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele = arr[mid])
            return mid;
        else if (ele < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}