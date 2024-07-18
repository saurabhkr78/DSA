#include<iostream>
#include<vector>
#include <climits>
using namespace std;

bool isSorted(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
       if(a[i]<a[i-1])
        return false;
     
      
    }
   return true; 
}
int main(){
    int a[]={12,1,14,14};
    int n=3;
if(isSorted(a,n)){
    cout<<"array is sorted";
}
else
cout<<"array is not sorted";
return 0;
}