// https://leetcode.com/problems/score-after-flipping-matrix

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        /* Algo:
        1.make 1 is 0th column
        2.if noz>noO in column then flip
        3. binary addition
        */
        int r = grid.size();
        int c = grid[0].size();
        // all rows and 1st column traversal
        for (int i = 0; i < r; i++) {
            if (grid[i][0] == 0) { // flip starts
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;

                    else
                        grid[i][j] = 0;
                }
            }
        }
        // for column traversal
        for (int j = 0; j < c; j++) {
            int noO = 0;
            int noZ = 0;
            // to loop for columns every row
            for (int i = 0; i < r; i++) {
                if (grid[i][j] == 0)
                    noZ++;
                else
                    noO++;
            }
            if (noZ > noO) {
                for (int i = 0; i < r; i++) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;

                    else
                        grid[i][j] = 0;
                }
            }
        }
        // binary to decimal
        int sum = 0;
        for (int i = 0; i < r; i++) {
            int fact = 1;
            for (int j = c - 1; j >= 0; j--) {
                sum += grid[i][j] * fact;
                fact *= 2;
            }
        }
        return sum;
    }
};