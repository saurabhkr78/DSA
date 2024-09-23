#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(int arr[], int n, int x)
{
    int i=0,j=n-1;
    int res=-1;
    while(i<=j){
        int mid=(i+(j-i)/2);
       if (arr[mid] == x) {  // If element is found
            res = mid;       // Store the index
            j = mid - 1;     // Continue searching in the left half
        }
        else if(arr[mid]>x){
            j=mid-1;//search in left half
        }
        else if(arr[mid]<x){
            i=mid+1;//search in right
        }
    }
  return res;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;

    int result = findFirstOccurrence(arr, n, x);
    if (result != -1)
    {
        cout << "First occurrence of " << x << " is at index: " << result << endl;
    }
    else
    {
        cout << x << " not found in the array" << endl;
    }

    return -1;
}
