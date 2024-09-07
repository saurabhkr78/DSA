#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v1={1,5,9,7};
    vector<int>v2={12,5,3,1};
    unordered_map<int,int>m;
    for(auto x:v1){
        m[x]++;
    }
    unordered_set<int>s;
    for(auto y:v2){
        auto it=m.find(y);//dundho y ko jo v2 ka element hai kisme map mein 
        if(it!=m.end()){
            s.insert(y);
        }
    }
    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<" ";
    }

    return 0;
}