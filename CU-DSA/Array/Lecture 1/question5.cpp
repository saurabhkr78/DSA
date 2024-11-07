#include<bits/stdc++.h>
using namespace std;

int bruteForce_max_subarray_sum(vector<int> &nums) {
    int max_sum = INT_MIN; 
    
    for (int i = 0; i < nums.size(); i++) {
        int current_sum = 0;
        for (int j = i; j < nums.size(); j++) {
            current_sum += nums[j]; 
            max_sum = max(max_sum, current_sum); 
        }
    }

    return max_sum;
}

int optimal_max_subarray_sum(vector<int> &nums){
    int i = 0 ;
    int max_sum = INT_MIN;
    int sum = 0;

    for(int num : nums){
        sum = max(num, sum+num);
        max_sum = max(max_sum, sum);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int largest_sum = bruteForce_max_subarray_sum(arr);
    cout << "Largest sum is: " << largest_sum << endl; 
    return 0;
}