#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int>&v,int k){
    int n=v.size();
    if(k>n) return -1;

    int i=0,j=0,sum=0,max_sum=INT_MIN;
    while(j<n){
        sum+=v[j];
        cout<<v[j]<<endl;

        if(j-i+1<k) j++;

        else if(j-i+1==k) {
            max_sum=max(sum,max_sum);
            sum-=v[i];
            i++;
            j++;
        }
    }
    return max_sum;
}
int main()
{
    vector<int>v={100,200,300,400};
    int k=2;
    cout<<maxSum(v,k);
    return 0;
}