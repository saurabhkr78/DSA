#include <bits/stdc++.h>
using namespace std;
int countsubsetsum(vector<int> v,int sum)
{
    int n=v.size();
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    for(int j=0;j<sum+1;j++)
    {
        if(i==0)
        t[i][j]=0;
        if(j==0)
        t[i][j]=1;
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(v[i-1]>j)
        {
            t[i][j]=t[i-1][j];
        }
        else if(v[i-1]<=j)
        {
            t[i][j]=t[i-1][j] + t[i-1][j-v[i-1]];
        }
    }
    return t[n][sum];
}
int main() {
    
    vector<int> v={1,1,2,3};
    int diff=1;
    int range=0;
    range=accumulate(v.begin(),v.end(),range);
    cout<<countsubsetsum(v,(diff+range)/2);
    return 0;
}