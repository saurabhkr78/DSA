// https://leetcode.com/problems/prime-in-diagonal

class Solution {
public:
/*A prime number is a natural number greater than 1 that cannot be formed by multiplying two smaller natural numbers. In other words, a prime number has exactly two distinct positive divisors: 1 and itself

*/
bool isPrime(int n) {
    // Handle numbers less than or equal to 1
    if (n <= 1) return false;
    
    // Handle small prime numbers (2 and 3)
    if (n <= 3) return true;
    
    // Exclude even numbers and multiples of 3
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check for divisors from 5 up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    // If no divisors found, n is prime
    return true;
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(isPrime( nums[i][i])){
                mx=max(mx,nums[i][i]);
            }
            if(isPrime( nums[i][n-i-1])){
                mx=max(mx,nums[i][n-i-1]);
            }
        }
        return mx;
    }
};