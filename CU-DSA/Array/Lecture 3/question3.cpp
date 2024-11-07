#include<bits/stdc++.h>
using namespace std;

int bruteForce_maxProduct(vector<int>& nums) {
    int maxi = INT_MIN;
    int prod = 1;
    for(int num : nums){
        prod *= num;
        maxi = max(prod, maxi);
        if(prod == 0) prod = 1;
    }
    prod = 1;

    for(int i = nums.size() - 1 ; i >= 0 ; i--){
        prod *= nums[i];
        maxi = max(prod, maxi);
        if(prod == 0) prod = 1;
    }
    return maxi;
}

int optimal_max_product(vector<int> &nums){
    int maxProd = nums[0];
    int leftProd = 1;
    int rightProd = 1;
    int n = nums.size()-1;

    for(int i = 0 ; i <= n ; i++){
        if(leftProd == 0) leftProd = 1;
        if(rightProd == 0) rightProd = 1;

        leftProd *= nums[i];
        rightProd *= nums[n-i];
        
        maxProd = max(maxProd, max(leftProd, rightProd));
    }

    return maxProd;  
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "maximum Product of nums: " << bruteForce_maxProduct(nums) << endl;
    cout << "maximum Product of nums: " << optimal_max_product(nums) << endl;
    return 0;
}