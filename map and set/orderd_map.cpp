//stores key in sorted order
//t.c of each operation is o(log n)
//it basically AVL tree(self balancing tree)

#include<map>
#include<iostream>
using namespace std;
int main(){
    map<string,int>m;
    m.insert({"a",100});
    m.insert({"b",67});
    m.insert({"c",6});
    m.insert({"d",92});
    m.insert({"x",1100});
    for(auto it=m.begin();it!=m.end();it++){
 cout<< (*it).first <<"--"<<(*it).second<<endl;
    }
    

   //updation
   cout<<"Update Operation...."<<endl; ;
    m["d"]=12;
    for(auto it=m.begin();it!=m.end();it++){
 cout<< (*it).first <<"--"<<(*it).second<<endl;
    }

cout<<"Erase Operation"<<endl;
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