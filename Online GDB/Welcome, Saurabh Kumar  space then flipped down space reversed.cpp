#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
 
    
 for(int i=1;i<=n;i++)
 {
     //spaces
      for(int j=1;j<=n-i;j++)
      {
         
         cout<<" ";
         
         }
         //stars
         for(int k=1;k<=i;k++){
             cout<<"*";
        
          
             
      }
      cout<<endl;
 }
 
 n-=1;
 for(int i=1;i<=n;i++)
 {
     //spaces
      for(int j=1;j<=i;j++)
      {
         
         cout<<" ";
         
         }
         //stars
         for(int k=1;k<=n-i+1;k++){
             cout<<"*";
        
          
             
      }
      cout<<endl;
 }


 return 0;
}
