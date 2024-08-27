// #include<iostream>
// #include<unordered_map>

// using namespace std;

// int main(){
//     unordered_map<int,int>mp;
//     mp[1]=80;
//     mp[2]=40;
//     mp[3]=50;
//     mp[4]=60;
//     mp[5]=70;
//     mp[6]=80;

//     //print key
//     for(auto it:mp){
//         cout<<it.first<<" "<<"-"<<it.second<<" "<<endl;;

//     }
// }
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> mp;
    mp["RAM"] = 80;
    mp["Shyam"] = 40;
    mp["Radha"] = 50;
    mp["Bhola"] = 60;
    mp["Vishnu"] = 70;
    mp["Indra"] = 80;

    // print key
    for (auto it : mp)
    {
        cout << it.first << " " << "-" << it.second << " " << endl;
        ;
    }
}