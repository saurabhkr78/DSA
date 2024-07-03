// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        /*1. reverse loop i.e top right
        2.if(matrix[i][j]>target)
        {
            go left j-- but not up
        }
        2. if(matrix[i][j]<target){
            go down i++ bt not right
        }
        3. if (row && column >>size)
        {
            flag=false
          }
        3.bool flag = false;
        if (matrix[i][j] = target) {
            flag = true;
        } */
        int i=0;
        int j=c-1;
        while(i<r&&j>=0){
            if(matrix[i][j]==target)
            return true;
            else if (matrix[i][j]>target)
                j--;
            else i++;
        }
        return false;

    }
};