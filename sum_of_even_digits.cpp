//WAP to print the sum of all the even digits of a given number.
#include <iostream>


using namespace std;

int main()
{
    int num;
    cout<<"Number\n";
    cin>>num;
   int sum=0; 
   

   while(num>0){
    int x=num%10;
 
    sum+=(x%2==0 ? x :0);
    
    num=num/10;
    
   }
    cout<<sum;

    return 0;
}


