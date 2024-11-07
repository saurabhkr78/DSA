#include<bits/stdc++.h>
using namespace std;

int bruteForce_peak_element(vector<int> &nums){
   int length = nums.size();

        int max = nums[0],res =0;
        for(int i=1;i<length;i++){
            if(max < nums[i]){
                max = nums[i];
                res = i;
            }
        }
        return res;
}

int optimal_peak_element(vector<int> &nums){
    int low = 0;
    int high = nums.size()-1;

    if(high == 0) return low;
    if(nums[low] > nums[low+1]) return low;
    if(nums[high] > nums[high-1]) return high;
    low++;
    high--;
    while(low <= high){
        int mid = (high + low)/2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) 
            return mid;
        
        if(nums[mid] > nums[mid-1]){
            low = mid+1;
        }else high = mid-1;
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    // brute force
    cout << "Peak element in nums: " << bruteForce_peak_element(nums) << endl;
    // optimal 
    cout << "Peak element in nums: " << optimal_peak_element(nums) << endl;
    return 0;
}
