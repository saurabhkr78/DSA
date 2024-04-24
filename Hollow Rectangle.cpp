/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

******
*    *
*    *
******
*******************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"ROw:";
     cin>>n;
    cout<<"column:";
    cin>>m;
 
    
 for(int i=1;i<=n;i++)
 {
    
      for(int j=1;j<=m;j++)
      {
          if((i==1||i==n||j==1||j==m))
          {
            cout<<"* ";
          }
             
      else
      cout<<"  ";
      }  
      cout<<endl;
 }

 
 
 
 return 0;
}


