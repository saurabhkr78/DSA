// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors

class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1) return false;// handle n <= 1
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int smallestValue(int n) {
        if (isPrime(n)) return n;

        int sum = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            while (n % i == 0) {
                sum += i;
                n /= i;
            }
        }
        if (n > 1) sum += n; // Add the remaining prime factor if any

        if (sum == n) return sum;
        return smallestValue(sum);
    }
};
