#include<bits/stdc++.h>
using namespace std;

vector<int>removeDuplicates(int arr[],int size){
    vector<int>output;
    unordered_map<int,bool>seen;
    for(int i=0;i<size;i++){
        if(seen.count(arr[i])>0){//check count of each element in hash map
            continue;
        }
        seen[arr[i]]=true;
        output.push_back(arr[i]);

    }
    return output;
}

int main(){
int a[]={1,2,3,1,4,5,6,1,7,2};
vector<int>output=removeDuplicates(a,10);
for(int i=0;i<output.size();i++){
    cout<<output[i]<<" ";
}
}