// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    //    //if cookies size>=greed factor then yes else no
    //    // no child should left without cookie
    //    //sort cookies array and greed factor array
    //    // index will go out of bound if size is less than greedy factor
    //    //we have to travese but till whose size will be less out of cookies and greedy factor i mean if cookies is less than number of students 
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
    //     int minimum_of_g_and_s=min(g.size(),s.size());
    //     for(int i=0;i<minimum_of_g_and_s;i++){
    //         //we were going to each index of each array and checking the below condition so we neednot strt the traversal in both the array from starting.
    //         if(s[i]>=g[i]) 
    //         count++;
    //     }
    //     return count;


    
    int i=0,j=0;//j for cookies
    while(i<g.size()&&j<s.size()){
        if(s[i]>=g[j]){
            count++;
            i++;
            j++;
        }
        else j++;
    }
    return count;
    }
};