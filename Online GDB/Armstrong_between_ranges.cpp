/*print out all Armstrong numbers between 1 and 500. If the sum of cubes of
each digit of the number is equal to the number itself, then the number is called an Armstrong
number. For example, 153 = ( 1 * 1 * 1 ) + ( 5 * 5 * 5 ) + ( 3 * 3 * 3 )*/
#include <iostream>

using namespace std;

int main()
{
    int range1,range2;
 cout<<"enter ranges\n";
 cin>>range1>>range2;
for(int i=range1;i<=range2;i++){
   int cube=0;
   int temp=i;
   while(temp>0)
   {
  int digit= temp%10;
  cube+=digit*digit*digit;
  temp/=10;
       
   }
   if(cube==i)
   cout<<i<<" ";
}
}
    

