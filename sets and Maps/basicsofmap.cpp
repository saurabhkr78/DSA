
// #include<iostream>
// #include<unordered_map>//random order printing and pair data type
// using namespace std;

// int main() {
//     unordered_map<string, int> m;

//     // Pair data
//     pair<string, int> p;
//     p.first = "Saurabh";
//     p.second = 10;
//     pair<string, int> p1;
//     p1.first = "Saurabh1";
//     p1.second = 20;
//     pair<string, int> p2;
//     p2.first = "Saurabh2";
//     p2.second = 30;
//     pair<string, int> p3;
//     p3.first = "Saurabh3";
//     p3.second = 40;

//     // Insert
//     m.insert(p);
//     m.insert(p1);
//     m.insert(p2);
//     m.insert(p3);

//     // Print
//     for (const auto& ele : m) {
//         /*
//         const: This indicates that the variable will not be modified. It's a promise that the code will not change the values of the elements in the collection.
//         auto: This keyword tells the compiler to automatically deduce the type of the variable. This is particularly useful when dealing with complex types, such as the elements of a map.
//         &: This denotes a reference. Instead of making a copy of the element, the loop variable refers to the actual element in the collection. This can improve performance by avoiding unnecessary copies, especially for large or complex objects.

//         */
//         cout << ele.first << " " << ele.second << endl;
//     }

//     return 0;
// }

// second method

#include <iostream>
#include <unordered_map> //random order printing and pair data type
using namespace std;

int main()
{
    unordered_map<string, int> m;

    // Pair data
    pair<string, int> p;
    p.first = "Saurabh";
    p.second = 10;

    // Insert
    m.insert(p);      // 1st method
    m["Raghav"] = 15; // 2nd method to insert
    m["shyam"] = 20;

    // Print
    for (const auto &ele : m)
    {
        cout << ele.first << " " << ele.second << endl;
    }

    // size
    cout << "size of map is:" << m.size() << endl;
    // erase data with key only
    m.erase("Saurabh");
    // SIZE AFTER ERASING
    cout << "size of map is:" << m.size() << endl;

    // get value using key
    cout << "value of raghav is:" << m["raghav"];

    return 0;
}
