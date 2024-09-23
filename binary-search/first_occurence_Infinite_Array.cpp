#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:


    int findidx(int arr[],int n,int x){
        int i=0,j=1;
        while(j<n && arr[j]<x){
            i=j;
            j=j*2;
        }
        return firstOccurrence(arr,i,min(j,n-1),x);

    }

   int firstOccurrence(int arr[], int low, int high, int x) {
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                result = mid;     // Store the current index and continue searching in the left half
                high = mid - 1;   // Search in the left part
            }
            else if (arr[mid] < x) {
                low = mid + 1;    // Move right
            }
            else {
                high = mid - 1;   // Move left
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int arr[]={0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x=1;

    int idx=sol.findidx(arr,n,x);
    if(idx!=-1)
        cout<<"fisrt occurence of 1 is found @:"<<idx<<endl;
    else cout<< "not found"<<endl;
    

    return 0;
}