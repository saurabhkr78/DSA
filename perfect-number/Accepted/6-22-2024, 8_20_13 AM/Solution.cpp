// https://leetcode.com/problems/perfect-number

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false; // No perfect number is <= 1
        
        int sum = 1; // Start with 1 since it's a proper divisor for all num > 1

        for (int i = 2; i <=sqrt(num); i++) {
            if (num % i == 0) { 
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }

        return (sum == num);
    }
};