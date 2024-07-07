// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
      int l=0;
      int h=n-1;
      while(l<=h){
          int k=l+(h-l)/2;
          int t=k*(k+1)/2;
          if(t==n) return k;
          else if (t>n) h=k-1;
          else l=k+1;

      }  
      return h;
    }
};