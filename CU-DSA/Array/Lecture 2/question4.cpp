#include<bits/stdc++.h>
using namespace std;

pair<int,int> bruteForce_sum_neg(vector<int> &nums) {
    int pos = 0, neg = 0;
    for(int num : nums) {
        if(num > 0) pos++;
        if(num < 0) neg++;
    }
    return {pos, neg};
}

pair<int,int> optimal_sum_neg(vector<int> &nums) {
    int size = nums.size();
    
    if (nums[0] > 0) return {size, 0};  
    if (nums[size - 1] < 0) return {0, size};  
    if (nums[0] == 0 && nums[size - 1] == 0) return {0, 0}; 
    
    int lastNeg = -1;
    int firstPos = size;
    
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < 0) {
            if (mid + 1 < size && nums[mid + 1] >= 0) {
                lastNeg = mid;
                break;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > 0) {
            if (mid - 1 >= 0 && nums[mid - 1] <= 0) {
                firstPos = mid;
                break;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    int posCount = size - firstPos;
    int negCount = lastNeg + 1;
    
    return {posCount, negCount};
}


int main() {
    vector<int> nums = {-2, -1, -1,0,0, 1, 2, 3,4,5};
    pair<int, int> data_nums = bruteForce_sum_neg(nums);
    cout << "max positive: " << data_nums.first << endl;
    cout << "max negative: " << data_nums.second << endl;

    data_nums = optimal_sum_neg(nums);
    cout << "max positive: " << data_nums.first << endl;
    cout << "max negative: " << data_nums.second << endl;

    return 0;
}
