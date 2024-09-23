#include<bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int arr[],int n,int target){
    int i=0,j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;

        if(arr[mid]==target) return mid;

        if(arr[i]<=arr[mid]){//;eft half
            if(target>=arr[i] and target<arr[mid]){//again check in the left half
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        else{//go to right half
            if(target>arr[mid]&&target<arr[n-1]){//again check in the right half
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
    }
    return -1;


}


int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = searchInRotatedArray(arr, n, target);

    if (result != -1)
    {
        cout << "Element " << target << " found at index: " << result << "\n";
    }
    else
    {
        cout << "Element " << target << " not found in the array\n";
    }

    return 0;
}