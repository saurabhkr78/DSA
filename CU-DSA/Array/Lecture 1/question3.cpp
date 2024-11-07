#include<bits/stdc++.h>
using namespace std;

void bruteForce_sortSquare(vector<int> &nums){
    for(int &num : nums)
        num *= num;

    sort(nums.begin(), nums.end());
}

void optimal_sortSquare(vector<int> &nums){
    int i = 0, j = nums.size() - 1;
    int n = nums.size()-1;

    while(i <= j){
        if(abs(nums[i]) < abs(nums[j])){
            nums[n] = nums[j] * nums[j];
            j--;
        }else{
            nums[n] = nums[i] * nums[i];
            i++;
        }
        n--;
    }
}

int main() {
    vector<int> nums = {-4,-1,0,3,10};
    bruteForce_sortSquare(nums);

    for(auto num : nums){
        cout << num << ' ';
    }
    cout << endl;

    nums = {-7,-3,2,3,11};
    
    optimal_sortSquare(nums);

    for(auto num : nums){
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}