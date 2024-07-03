// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //finding pivot
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            //normal condition
       if(nums[mid]==target) return mid;
//2.to check which half is sorted R?L as wehave a sorted array given
//3. for left search space 
       if(nums[l]<=nums[mid]){
           //4. if left space is sorted
           if(nums[l]<=target&&target<nums[mid]) h=mid-1;

           else l=mid+1;
       }
       //for right search space
       else{
           //if right space is sorted
           if(nums[mid]<=target&&target<=nums[h]) l=mid+1;
           else h=mid-1;
       }
     
        }
  return -1;
        
    }
};