// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > v;
        for(int i=0;i<numRows;i++){ /*each row of Pascal’s triangle has one more element than the previous row*/
            vector<int>temp(i+1);
            v.push_back(temp);
        }


        //to generate pascal triangle
        for(int i=0;i<numRows;i++){
           
             for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    v[i][j]=1;
                }
                else
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        return v;
    }
};