#include<unordered_map>
#include<iostream>
using namespace std;
int main(){
    unordered_map<string,int>m;
    m.insert({"a",2});
    m.insert({"b",4});
    m.insert({"c",6});
    m.insert({"d",9});
    m.insert({"x",100});
    for(auto it=m.begin();it!=m.end();it++){
 cout<< (*it).first <<"--"<<(*it).second<<endl;
    }


    m["d"]=12;
    for(auto it=m.begin();it!=m.end();it++){
 cout<< (*it).first <<"--"<<(*it).second<<endl;
    }


    m.erase("x");
    for(auto it=m.begin();it!=m.end();it++){
 cout<< (*it).first <<"--"<<(*it).second<<endl;
    }

auto it=m.find("a");
if(it==m.end()){//kyunki it iterator returned the last element of map so there is not such element which were being find
    cout<<"key not found"<<endl;
}
if(it!=m.end()){
    cout<<"key found";
}



}