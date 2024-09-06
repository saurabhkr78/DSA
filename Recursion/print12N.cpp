// #include<iostream>
// using namespace std;

// void print(int n){
//     if(n>0||n==1) 
//     print(n-1);//step 2 =1 2 3 4 5 6
//     cout<<n;//step1=7
//     return;
// }

// int main(){
//     int n;
//     cin>>n;
//    print(n);
// }
//reverse order
#include<iostream>
using namespace std;

void print(int n){
    if(n>0||n==1) 
    
    cout<<n;//step1=7
    print(n-1);//step 2 =6 5 4 3 2 1
    return;
}

int main(){
    int n;
    cin>>n;
   print(n);
}