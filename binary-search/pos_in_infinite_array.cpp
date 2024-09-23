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
        return bs(arr,i,min(j,n-1),x);

    }



    int bs(int arr[],int i,int j,int x){
        while(i<=j){
            int mid = i + (j - i) / 2;
             if (arr[mid] == x) return mid; 
             else if (arr[mid] < x) i = mid + 1;
             else j=mid-1;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int arr[]={1, 3, 7, 15, 18, 21, 30, 35, 40, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x=21;

    int idx=sol.findidx(arr,n,x);
    if(idx!=-1)
        cout<<"element found @"<<idx<<endl;
    else cout<< "not found"<<endl;
    

    return 0;
}