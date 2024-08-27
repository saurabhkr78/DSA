#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMax(vector<int> &arr)
{
    int mx = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    { 
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(vector<int> &arr, int placeValue)
{
    int n = arr.size();
    vector<int> count(10, 0); // Since the digits are 0-9
    vector<int> output(n);

    // Count the occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / placeValue) % 10]++;
    }

    // Calculate prefix sum
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Place the elements in the output array in sorted order by reverse loop in the original array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / placeValue) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr)
{
    int mx = findMax(arr);
    // Apply counting sort to each digit place
    for (int placeValue = 1; mx / placeValue > 0; placeValue *= 10)
    {
        countSort(arr, placeValue);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
