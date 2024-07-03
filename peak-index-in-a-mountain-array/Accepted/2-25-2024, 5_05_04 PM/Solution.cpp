// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int n=arr.size();
        // int idx=-1;
        // for(int i=1;i<n-2;i++){
        //     if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
        //         idx=i;
        //         break;
        //     }
        // }
        // return idx; 
        int n=arr.size();
        int l=1;
        int h=n-2;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]) return mid;
            else if(arr[mid]>arr[mid+1]) h=mid-1;
            else l=mid+1;
        }
        return 0;

    }
};