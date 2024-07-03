// https://leetcode.com/problems/sort-colors

class Solution {
public:
     //two passes solution
    void sortColors(vector<int>& nums) {
     int noz=0,noo=0,notwo=0;
     for(int i=0;i<nums.size();i++){
         if(nums[i]==0) noz++;
         else if(nums[i]==1) noo++;
         else notwo++;
     } 
     for(int i=0;i<nums.size();i++){
         if(i<noz) nums[i]=0;
         else if(i<(noz+noo)) nums[i]=1;
         else nums[i]=2;
     }
    }
};