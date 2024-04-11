#include <iostream>

using namespace std;

int main()
{
    int num,rev,sum=0;
    cout<<"num";
    cin>>num;
    rev=num;
    
    
   while(rev>0)
   {
    sum *= 10;
    sum+=rev%10;
    rev/=10;
    
   }
   
    cout<<num+sum;
   

    return 0;
}
