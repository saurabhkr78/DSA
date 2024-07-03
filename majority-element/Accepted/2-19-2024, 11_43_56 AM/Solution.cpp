// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //built in functio of vector and if number is in majority it will exist more than n/2 means it will present at the middle index
       sort(nums.begin(),nums.end());
       return nums[nums.size()/2]; 
    }
};