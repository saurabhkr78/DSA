// //direct
// #include<bits/stdc++.h>
// using namespace std;

// int majorityElement(vector<int>&nums) {

//        sort(nums.begin(),nums.end());

//        return nums[nums.size()/2];
// }

// int main(){
//     vector<int>nums={3,2,3};
//     int res;
//     cout<< (res=majorityElement(nums));

// }

// hash map
// #include <bits/stdc++.h>
// using namespace std;

// int solve(int arr[],int n){
//     unordered_map<int, int> m;
//     for (int i = 0; i < n; i++)
//     {
//         m[arr[i]]++;
//     }
//     int  maxfreq=INT_MIN;


//     for(auto it=m.begin();it!=m.end();it++){
//      if(it->second>n/2){   
//       maxfreq=it->first;
//       break;

//     }
//     }
//     return maxfreq;
// }
// int main()
// {
//     int arr[]={3,2,3};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     cout<<solve(arr,n);
    
    
      
// }

//Boyer-Moore Voting Algorithm
#include<bits/stdc++.h>
using namespace std;
void findmajority(vector<int>&v){
    int maxCount=INT_MIN;
    int count=0;
    for(int num:v){
      
    }
}

int main(){
    vector<int>v={3,2,3};
    findmax(v);
    
}
