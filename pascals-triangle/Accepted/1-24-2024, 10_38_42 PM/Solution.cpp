// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
//solution 2
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    row.push_back(v[i - 1][j - 1] + v[i - 1][j]);
                }
            }
            v.push_back(row);
        }
        return v;
    }
};
