#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float> &arr)
{
    int n = arr.size(); // Get the size of the input array
    if (n <= 0) // Check if the input array is empty or has a non-positive size
        return;

    // Create n empty buckets (vectors)
    // We use a vector of vectors (2D vector) where each bucket is a vector of floats
    vector<vector<float>> buckets(n);

    // Put array elements into different buckets
    for (int i = 0; i < n; i++) // Iterate over each element in the input array
    {
        int bucketIndex = arr[i] * n; // Calculate the index of the bucket where the current element should go
        buckets[bucketIndex].push_back(arr[i]); // Place the element into the corresponding bucket
    }

    // Sort each individual bucket
    // Each bucket is sorted using a comparison-based sorting algorithm (std::sort)
    for (int i = 0; i < n; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all the sorted buckets back into the original array
    int index = 0; // Initialize index to keep track of the position in the original array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++) // Iterate through each element in the current bucket
        {
            arr[index++] = buckets[i][j]; // Place the sorted elements back into the original array
        }
    }
}

int main()
{
    // Input array containing float values uniformly distributed between [0, 1)
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    // Display the original array
    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the Bucket Sort function to sort the array
    bucketSort(arr);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
