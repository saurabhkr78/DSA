#include<iostream>
using namespace std;

void print(int n){
    print(n-1);
    cout<<n;//step1=7
}

int main(){
    int n;
    cin>>n;
   print(n);
}