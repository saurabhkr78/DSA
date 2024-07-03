// https://leetcode.com/problems/spiral-matrix

class Solution {
    //gurmehar soln
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
   
    int m = matrix.size();
    if (m == 0) return result;
 
    int n = matrix[0].size();
    if (n == 0) return result;
 
    int t = 0, lt = 0;
    int b = m - 1;
    int rt = n - 1;
 
    while (t <= b && lt <= rt) {
        for (int i = lt; i <= rt; i++) {
            result.push_back(matrix[t][i]);
        }
        t++;  // top
 
        for (int i = t; i <= b; i++) {
            result.push_back(matrix[i][rt]);
        }
        rt--;  // right
       if (t <= b)  {
            for (int i = rt; i >= lt; i--) {
                result.push_back(matrix[b][i]);
            }
            b--;  // bottom
        }
        if (lt <= rt) {
            for (int i = b; i >= t; i--) {
                result.push_back(matrix[i][lt]);
            }
            lt++;  // left
        }
    }
 
    return result;
}
};