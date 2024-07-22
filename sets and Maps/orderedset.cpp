// follows maths set property
// always elements are inserted in increasing order
// unique elements
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(4);
    s.insert(1);
    s.insert(9);
    s.insert(2);

    // Printing elements
    for (const auto &x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
