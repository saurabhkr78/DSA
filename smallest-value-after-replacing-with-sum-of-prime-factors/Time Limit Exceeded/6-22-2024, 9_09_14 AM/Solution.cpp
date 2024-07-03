// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        
        return true;
    }
    
    vector<int> primeFactors(int n) {
        vector<int> factors;
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }
        
        for (int i = 3; i <= sqrt(n); i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
        
        if (n > 2) factors.push_back(n);
        
        return factors;
    }
    
    int smallestValue(int n) {
        if (isPrime(n)) return n;
        
        while (!isPrime(n)) {
            vector<int> factors = primeFactors(n);
            int sum = 0;
            for (int factor : factors) {
                sum += factor;
            }
            n = sum;
        }
        
        return n;
    }
};