#include<bits/stdc++.h>
using namespace std;

void bruteForce_zigzag(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n- 1; i += 2) {
        swap(nums[i], nums[i + 1]);
    }
    return;
}

void optimal_zigzag(vector<int> &nums){
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            if (nums[i] >= nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        } else { 
            if (nums[i] <= nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
}

int main() {
    vector<int> nums = {4, 3, 7, 8, 6, 2, 1};
    bruteForce_zigzag(nums);
    for(auto num : nums)
        cout << num << ' ';
    cout << endl;

    optimal_zigzag(nums);
    for(auto num : nums)
        cout << num << ' ';
    cout << endl;
    return 0;
}