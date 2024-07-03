// https://leetcode.com/problems/count-primes

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    void fillarray(vector<bool> &array) {
        int size = array.size() - 1;
        for (int i = 2; i <= sqrt(size); i++) {
            if (array[i]) {
                for (int j = i * i; j <= size; j += i) {
                    array[j] = false;
                }
            }
        }
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> array(n, true);
        fillarray(array);
        array[0] = false;
        array[1] = false;
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (array[i]) count++;
        }
        return count;
    }
};
