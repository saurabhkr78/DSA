#include <iostream>

using namespace std;

int main()
{
    int x1,x2,y1,y2,x3,y3,slope1,slope2;
    cout<<"x1"<<"x2"<<"y1"<<"y2"<<"x3"<<"y3";
    cin>>x1>>x2>>y1>>y2>>x3>>y3;
    slope1=(y2-y1)/(x2-x1);
    slope2=(y3-y2)/(x3-x2);
    
    if(slope1==slope2)
    cout<<"same line";
    else
    cout<<"not lies on same line";

    return 0;
}