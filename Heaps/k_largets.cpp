//brute force --sort

#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> minh;
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    for(int i=0;i<n;i++){
        minh.push(arr[i]);

        if(minh.size()>k){
        maxh.pop();
    }
    }
    while(!maxh.empty()){
        minh.top();
        minh.pop();
        cout<<minh.top();
    }
    
    
    return 0;

}