/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.
*
**
***
****
***
**
*

*******************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
 
    
 for(int i=1;i<=n;i++)
 {
    
      for(int j=1;j<=i;j++)
      {
         cout<<"* ";
        
             
      }
      cout<<endl;
 }
 int m=n-1;
  for(int i=1;i<=m;i++)
 {
    
      for(int j=1;j<=m-i+1;j++)
      {
         cout<<"* ";
        
             
      }
      cout<<endl;
 }
 
 
 
 
 return 0;
}

