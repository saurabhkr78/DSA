#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout<<"x:"<<"y:";
    cin>>x>>y;
    if(x==0&&y==0)
    cout<<"origin";
    else if(x>0&&(y>=0 ||y<0))
    cout<<"X-axis";
    
    else
    cout<<"Y-Axis";

    return 0;
}