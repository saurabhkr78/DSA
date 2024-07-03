// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        //The reason for only going up to sqrt(c) is because a and b are symmetric in the equation a^2 + b^2 = c. If a solution exists, one of a or b must be less than or equal to sqrt(c)
         for (int a = 0; a <= sqrt(c); ++a) {
             //For each a, it calculates b as sqrt(c - a*a). This comes directly from rearranging the equation a^2 + b^2 = c to solve for b.
        double b = sqrt(c - a*a);
        //It then checks if b is an integer by comparing b with its integer part. If b is an integer, it means that a and b are a valid pair of solutions.
        if (b == int(b)) {
            return true;
        }
    }
    return false;
    }
};