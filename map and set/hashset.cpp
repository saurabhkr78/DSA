#include<iostream>
#include<unordered_set>

using namespace std;


int main(){
    unordered_set<int>s;// no duplicacy
    s.insert(1);
    s.insert(11);
    s.insert(12);
    s.insert(11);
    s.insert(1);
    s.insert(11);
    s.insert(12);
    s.insert(11);
    s.insert(13); //last inserted element is displayed first
    cout<<s.size()<<endl;//4 only
    s.erase(11);
    cout<<s.size()<<endl;//4 only

    //for each loop
    for(auto it:s){
        cout<<it<<" ";
    }

    //searching an element
    int target=4;
    if(s.find(target)!=s.end()){ //target exists and vice versa
    //find searches in entire set if not found then it returns last element of set.
    //from above s.find(target)!=s.end() means find searched in entire set and if not found it returns last element of set and if the returned value is equal to  end element of set then it exists in set
    cout<<"exists";
    }
    else cout<<"Not Exists"<<endl;
}