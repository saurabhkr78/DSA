#include<iostream>
using namespace std;

int fib(int n){
    if(n==1||n==2)
    return(1);
 return(fib(n-1)+fib(n-2));
    
}
int main(){
  int i;
  for(i=1;i<10;i++){
      cout<<fib(i) <<" "<<endl;
  }
  int n;
  cout<<"enter the term you wanna access"<<endl;
  cin>>n;
  
  cout<<n<<"th term is="<<fib(6);
    return 0;
}