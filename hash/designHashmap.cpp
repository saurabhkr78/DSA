#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Hashmap
{
    vector<list<int>> hashtable;
    int buckets;

public:
    Hashmap(int size) // Constructor should be public
    {
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key)
    {
        return key % buckets;
    }

    void add(int key)
    {
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key)
    {
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }

    void deleteKey(int key)
    {
        int idx = hashvalue(key);

        auto it = searchKey(key);
        if (it != hashtable[idx].end())
        { // Key is present
            hashtable[idx].erase(it);
            cout << "Key deleted successfully" << endl;
        }
        else
        {
            cout << "Key is not present in the hash table" << endl;
        }
    }
};

int main()
{
    Hashmap h(7); // Create a hashmap with 7 buckets
    h.add(10);
    h.add(20);
    h.add(15);
    
    h.deleteKey(20);
    h.deleteKey(100);

    return 0;
}
