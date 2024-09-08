#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    { //int a=2*i-1;
    for(int j=1;j<=n+1-i;j++)// loop till a
        {
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++)// loop till a
        {
            cout<<j;
        }
        
    
       cout<<endl;
   
}
 return 0;
}

