// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // Initialize the result vector with -1
        vector<int> result(2, -1);


        //for first occurence and storing it
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]!=target){
                    result[0]=mid;
                    break;
                }
                else high=mid-1;
            }
            else if (nums[mid]<target) low=mid+1;
            else high=mid-1;
        }

        //for last occurence
        //need to reset low and high
        low=0;
        high=n-1;
        while(low<=high)
        {
             int mid=low+(high-low)/2;
             if(nums[mid]==target)
             {
              if(mid==n-1|| nums[mid+1]!=target){
              result[1]=mid;
              break;
              }
            else low=mid+1;
        }
        
        
        else if (nums[mid]<target) low=mid+1;
            else high=mid-1;
        }

         return result;
    }
   
};
