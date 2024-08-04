#include <iostream>
#include <vector>
using namespace std;


// Recursive function to sort the vector
void sort(vector<int> &v)
{
    if (v.size() <= 1)
        return;

    // Remove the last element
    int temp = v.back();
    v.pop_back();

    // Recursively sort the remaining vector
    sort(v);

    // Insert the removed element back in the sorted vector
    insert(v, temp);
}

// Function to insert an element into the sorted part of the vector
void insert(vector<int> &v, int temp)
{
    if (v.empty() || v.back() <= temp)
    {
        v.push_back(temp);
        return;
    }

    // Remove the last element
    int last = v.back();
    v.pop_back();

    // Recursively insert the element
    insert(v, temp);

    // Put the last element back
    v.push_back(last);
}

int main()
{
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v);

    cout << "Sorted vector: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
