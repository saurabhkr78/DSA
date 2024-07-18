#include<iostream>
using namespace std;
 void toh(int n,char beg,char aux,char end){
     if (n==1){
         
         cout<<"Move  1st Disk from "<<beg <<" to "<<end<<endl;
         return;
     }
    else
       toh(n-1,beg,end,aux);
        cout << "Move "<<n<<"th disk from rod " << beg 
         << " to rod " << end << endl; 
       toh(n-1,aux,beg,end);
    }
 
 int main(){
toh(4,'s','h','d');
    return 0;
 }