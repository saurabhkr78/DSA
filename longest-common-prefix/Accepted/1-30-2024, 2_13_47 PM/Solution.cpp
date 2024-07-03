// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int size=strs.size();
       if(size==1) return strs[0];
       sort(strs.begin(),strs.end());

       string firstIndex=strs[0];
       string lastIndex=strs[size-1];
       string temp="";
       for(int i=0;i<min(firstIndex.size(),lastIndex.size());i++){
           if(firstIndex[i]==lastIndex[i])
           temp+=firstIndex[i];
           else 
           return temp;
       }
       return temp;
    }
};