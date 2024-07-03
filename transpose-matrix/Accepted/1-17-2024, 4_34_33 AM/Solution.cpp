// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      int row=matrix.size();
      int col=matrix[0].size();

      vector<vector<int>>transpo(col,vector<int>(row));
      for(int k=0;k<col;k++){
          for(int l=0;l<row;l++){
              transpo[k][l]=matrix[l][k];
          }
      }
      return transpo;
    }
};
