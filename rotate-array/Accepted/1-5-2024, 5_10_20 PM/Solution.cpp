// https://leetcode.com/problems/rotate-array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reversePart(0, n - k - 1, nums);
        reversePart(n - k, n - 1, nums);
        reversePart(0, n - 1, nums);
    }

private:
    void reversePart(int i, int j, vector<int>& a) {
        while (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
};
