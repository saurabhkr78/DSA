#include <iostream>
#include <unordered_set> //no duplicacy
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(1);
    for (int ele : s)
    { // only for each loop
        cout << ele << " ";
    }
    cout << endl;
    cout << "Size:" << s.size() << endl;

    int target = 40;
    // s.find->if elements not found returns last element
    if (s.find(target) != s.end())
    { // target exists
        cout << "exists" << endl;
    }
    else
        cout << "not exists" << endl;

    s.erase(7);
}