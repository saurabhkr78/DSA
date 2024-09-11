#include<bits/stdc++.h>
    int majorityElement(vector<int>& nums) {

       sort(nums.begin(),nums.end());
       return nums[nums.size()/2]; 
    }
int main(){
    int vector<int>v={3,2,3};
    majorityElement(v);

}