#include<bits/stdc++.h>
using namespace std;

int bruteForce_pivotIndex(vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        int leftSum = 0, rightSum = 0;
        
        // Calculate left sum
        for (int j = 0; j < i; ++j) {
            leftSum += nums[j];
        }
        
        // Calculate right sum
        for (int j = i + 1; j < n; ++j) {
            rightSum += nums[j];
        }
        
        // Check if left sum is equal to right sum
        if (leftSum == rightSum) {
            return i;
        }
    }
    
    return -1; // Return -1 if no pivot index is found
}

int optimal_pivotIndex(vector<int>& nums) {
    int left = 0;
    int right = 0;

    for(int i : nums)
        left += i;
    
    for(int i = 0 ; i < nums.size() ; i++){
        left -= nums[i];
        if(left == right)
            return i;
        right += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    int data = bruteForce_pivotIndex(nums);
    cout << "Pivot of value is: " << data << endl;
    data = optimal_pivotIndex(nums);
    cout << "Pivot of value is: " << data << endl;
    
    return 0;
}