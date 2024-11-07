#include<bits/stdc++.h>
using namespace std;

void moving_zero_brute_force(vector<int> &nums){
    int zero = 0;
    vector<int> temp;
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] != 0){
            temp.push_back(nums[i]);
        }else zero++;
    }
    while(zero-- > 0){
        temp.push_back(0);
    }
    nums = temp;
}


void moving_zero_optimal_solution(vector<int> &nums){
    int idx = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] != 0){
            nums[idx++] = nums[i];
        }
    }
    for(idx ; idx < nums.size() ; idx++)
        nums[idx] = 0;
}

int main() {
    vector<int> nums = {0,1,0,3,1,2};
    moving_zero_brute_force(nums);
    for(auto num : nums)
        cout << num << ' ';
    cout << endl;
    nums = {0,0,0,0,0,1,0,3,0,4,0,5};
    moving_zero_optimal_solution(nums);
    for(auto num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}