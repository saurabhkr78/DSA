// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
    //      int l = 0, h = num;
    // while (l <= h) {
    //     long long mid = l + (h - l) / 2;
        
        
    //     if (mid * mid == num)
    //         return true;
    //     else if (mid * mid < num)
    //         l = mid + 1;
    //     else
    //         h = mid - 1;
            
            
            
            
            
    // }
    // return false;
    int r=sqrt(num);
    if(r*r==num) return true;
    else return false;
    }
};