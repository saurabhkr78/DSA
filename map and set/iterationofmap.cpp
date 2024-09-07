#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    unordered_map<string, int> mp; // unordered_map to store key-value pairs
    mp["a"] = 1;
    mp["b"] = 2;
    mp["c"] = 3;
    mp["d"] = 4;
    mp["e"] = 5;
    mp["f"] = 6;

    // Iterating through the unordered_map
    unordered_map<string, int>::iterator it = mp.begin();
    while (it != mp.end())
    {
        // Use '->' to access key-value from iterator, as it points to a pair
        cout << "Key: " << it->first << " and Value: " << it->second << endl;
        it++;
    }

    // Using the find function to get an iterator to element with key "a"
    unordered_map<string, int>::iterator it3 = mp.find("a");

    // Erasing a single element (the one at iterator 'it3')
    if (it3 != mp.end())
    {
        mp.erase(it3); // Erase the element at it3
    }

     // Display remaining elements after erasure
    cout << "Map after erasing 'a':" << endl;
    for (auto &pair : mp)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Erasing entire map from the element at iterator 'it3' to the end
    if (it3 != mp.end())
    {
        mp.erase(it3, mp.end()); // Erase from 'it3' to the end of the map
    }

    // Display remaining elements after erasure
    cout << "Map after erasing 'a':" << endl;
    for (auto &pair : mp)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Example with vector
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int>::iterator it2 = v.begin();
    while (it2 != v.end())
    {
        cout << *it2 << endl;
        it2++;
    }
}
