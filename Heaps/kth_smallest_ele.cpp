#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int>maxh;
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
        maxh.pop();
    }
    
    }
    cout<<maxh.top();
    return 0;

}