// complete binary tree
// left to right
//  if n node given height of complete binary tree is log n
// using level order printing of tree in array
// parent of any node is present at which index of array=[current node(i)/2];
//  left child node of current node=i*2;
// right child node=i*2+1;

// insert
// insert new node in array at empty index which is next to the total elements filled in array
// arrange elements in such a way that it follows heap property
//  index of new inserted element is less than or greater than parent node[i/2].
//  in case of max heap if parent is smaller than new node then swap and keep checking ...untill it maintains heap property.
// insert+delete ---logn

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Inserts a new value into the max-heap.
 *
 * This function inserts a new element into a max-heap and maintains the heap property
 * by performing a "heapify-up" operation. The newly inserted element is compared with
 * its parent, and if it is larger, they are swapped. This process continues until the
 * heap property is restored.
 *
 * @param arr[] Array representing the heap.
 * @param n Reference to the current size of the heap.
 * @param value The value to be inserted into the heap.
 */
void insert(int arr[], int &n, int value)
{
    n = n + 1;      // Increase size as we are adding one element
    arr[n] = value; // Insert the value at the last position

    int i = n; // Start from the newly inserted element
    while (i > 1)
    {                       // Continue until the root node is reached
        int parent = i / 2; // Find the parent index
        if (arr[parent] < arr[i])
        {                              // If the parent is smaller than the current element
            swap(arr[parent], arr[i]); // Swap parent and current element
            i = parent;                // Move up to the parent's position
        }
        else
        {
            return; // Stop if the heap property is satisfied
        }
    }
}

/**
 * @brief Deletes the maximum element (root) from the max-heap.
 *
 * This function removes the root element from a max-heap and maintains the heap property
 * by performing a "heapify-down" operation. The last element in the heap replaces the root,
 * and then it is compared with its children. If it is smaller than either child, it is swapped
 * with the larger child. This process continues until the heap property is restored.
 *
 * @param arr[] Array representing the heap.
 * @param n Reference to the current size of the heap.
 */
void deleteMax(int arr[], int &n)
{
    arr[1] = arr[n]; // Move the last element to the root position
    n = n - 1;       // Decrease size as we are removing the root

    int i = 1; // Start from the root
    while (i <= n)
    {                          // Continue until we reach the end of the heap
        int left = 2 * i;      // Left child index
        int right = 2 * i + 1; // Right child index
        int larger = i;        // Assume the current node is the largest

        if (left <= n && arr[left] > arr[larger])
        {
            larger = left; // If the left child is larger, update the largest index
        }
        if (right <= n && arr[right] > arr[larger])
        {
            larger = right; // If the right child is larger, update the largest index
        }

        if (larger != i)
        {                              // If the current node is not the largest
            swap(arr[i], arr[larger]); // Swap with the largest child
            i = larger;                // Move down to the child's position
        }
        else
        {
            return; // Stop if the heap property is satisfied
        }
    }
}

/**
 * @brief Main function to demonstrate heap operations.
 *
 * The main function initializes a max-heap, performs several insertions, and then
 * deletes the maximum element. The heap is printed before and after the deletion to
 * show the result of the operations.
 *
 * @return int 0 if the program completes successfully.
 */
int main()
{
    int arr[100]; // Assuming heap will have max 100 elements
    int n = 0;    // Current size of the heap, initially empty

    // Inserting elements into the heap
    insert(arr, n, 50);
    insert(arr, n, 30);
    insert(arr, n, 20);
    insert(arr, n, 60);
    insert(arr, n, 10);

    // Printing the heap after insertions
    cout << "Heap after insertions: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deleting the maximum element (root) from the heap
    deleteMax(arr, n);

    // Printing the heap after deletion
    cout << "Heap after deletion: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
