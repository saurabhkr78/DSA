// https://leetcode.com/problems/minimum-length-of-anagram-concatenation

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        int index = 0; // Declare index here
        for (int potentialSize = 1; potentialSize < n; ++potentialSize) {
            if (n % potentialSize == 0) {
                string initialSegment = s.substr(0, potentialSize);
                sort(initialSegment.begin(), initialSegment.end());
                for (index = potentialSize; index < n; index += potentialSize) {
                    string currentSegment = s.substr(index, potentialSize);
                    sort(currentSegment.begin(), currentSegment.end());
                    if (initialSegment != currentSegment) {
                        break;
                    }
                }
                if (index == n) {
                    return potentialSize;
                }
            }
        }
        return n;
    }
};
