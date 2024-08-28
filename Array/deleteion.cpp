#include <iostream>
using namespace std;

void deleteAtidx(int arr[], int size, int idx)
{
    if (idx < 0 || idx >= size)
    {
        cout << "Invalid Idx";
        return;
    }
    for (int i = idx; i < size - 1; i++)
    {
        arr[i] = arr[i - 1];
    }
    size--;
}

void deleteAtBeg(int arr[], int size)
{
    if (size == 0)
    {
        cout << "empty array";
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
void deleteAtEnd(int arr[], int size)
{
    if (size == 0)
    {
        cout << "Empty Array";
        return;
    }
    size--;
}
int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the index to delete element" << endl;
    int idx;
    cin >> idx;

    deleteAtidx(arr, size, idx);
    deleteAtBeg(arr, size);
    deleteAtEnd(arr, size);
}
