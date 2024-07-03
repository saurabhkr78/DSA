// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors

class Solution {
public:
    int smallestValue(int n) {
        int num=n;
        n=prime(n);
       
        while(num!=n)
        {
            num=n;       
            n=prime(n);
            
        }
        return num;
    }   
    int prime(int n)
    {
        int a=n;
    int ans =0;
    for(int i=2;i<a;++i)
    {
        while(n%i==0)
        {
            ans+=i;
            n/=i;
        }
    }
    if(ans==0)
        return a;
    else return ans ;
}
};