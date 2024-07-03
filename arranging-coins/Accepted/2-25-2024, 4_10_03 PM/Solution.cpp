// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
      long l=0;
      long h=n;
      while(l<=h){
          long k=l+(h-l)/2;

          long t=k*(k+1)/2;
          if(t==n) return (int)k;
          else if (t>n) h=k-1;
          else l=k+1;

      }  
      return (int)h;
    }
};