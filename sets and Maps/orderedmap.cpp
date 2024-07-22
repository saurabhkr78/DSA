// follows maths set property
// always elements are inserted in increasing order
// unique elements
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    // m[2]=20;
    // m[1]=30;
    // m[3]=70;
    // m[5]=90;
    // m[4]=10;
    m["Saurabh"] = 20; // lexographical sorting here on  key basis
    m["radha"] = 30;
    m["Kashish"] = 70;

    // Printing elements
    for (const auto &x : m)
    {
        cout << x.first << "-" << x.second << endl;
    }
    cout << endl;
    return 0;
}
