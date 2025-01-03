// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;//low ,high,mid is index
        int high=nums.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target) return mid;//here arr[mid ] is element
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};