// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool isPS(int x) {
        int root_of_x = sqrt(x);
        if (root_of_x * root_of_x == x)
            return true;
        else
            return false;
    }
    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while (x <= y) {
            // if both of them are true
            if (isPS(x) && isPS(y))
                return true;

            // if y is not perfect then make it perfect
            else if (!isPS(y)) {
                y=(int)sqrt(y)*(int)sqrt(y);
                x = c - y;
            }
            // if  x is !perfect then make it perfect
            else {
                x = ((int)sqrt(x) + 1 * (int)sqrt(x) + 1);
                y = c - x;
            }
        }
        return false;
    }
};