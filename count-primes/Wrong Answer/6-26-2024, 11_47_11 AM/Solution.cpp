// https://leetcode.com/problems/count-primes

class Solution {
public:
    void fillarray(vector<bool> &array) {
        int size = array.size() - 1;
        for (int i = 2; i <= sqrt(size); i++) {
            for (int j = i * 2; j <= size; j += i) {
                array[j] = false;
            }
        }
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;
        n = n - 1;
        int count = 0;
        vector<bool> array(n + 1, true);
        fillarray(array);
        array[0] = false;
        array[1] = false;
        for (int i = 2; i < n; i++) {
            if (array[i]) count++;
        }
        return count;
    }
};
