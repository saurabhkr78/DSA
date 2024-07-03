// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
   int trap(vector<int>& height)
    {
       int n=height.size();
       //prev greatest element
        int prev[n];
        prev[0]=-1;
        int max=height[0];

        for(int i=1;i<n;i++)
        {
          prev[i]=max;
           if(max<height[i])
          {
            max=height[i];
          }
        }
//next greatest element
    int next[n];
    next[n-1]=-1;
    max=height[n-1];
    for(int i=n-2;i>=0;i--)
    {
        next[i]=max;
        if(max<height[i])
       {
        max=height[i];
        }
    }
    //minimum of prev and next greatest
    int mini[n];
    for(int i=0;i<n;i++)
    {
        mini[i]=min(prev[i],next[i]);
    }
    //water trapping amt
    int wateramt=0;
    for(int i=1;i<n-1;i++)
    {
        if(height[i]<mini[i])
        {
           wateramt+=mini[i]-height[i];
        }
        
    }
    
    return wateramt;
    }
};