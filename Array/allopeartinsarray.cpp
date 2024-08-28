#include<iostream>
using namespace std;

/**
 * @brief Inserts an element at the beginning of the array.
 * 
 * @param arr[] The array where the element is to be inserted.
 * @param size The current size of the array (passed by reference).
 * @param ele The element to insert at the beginning.
 */
void insertAtBeginning(int arr[], int &size, int ele) {
    // Shift all elements one position to the right
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element at the start
    arr[0] = ele;
    // Increase the size of the array
    size++;
}

/**
 * @brief Inserts an element at a specific index in the array.
 * 
 * @param arr[] The array where the element is to be inserted.
 * @param size The current size of the array (passed by reference).
 * @param index The index at which the element should be inserted.
 * @param ele The element to insert at the specified index.
 */
void insertAtIndex(int arr[], int &size, int index, int ele) {
    // Check if the index is valid
    if (index < 0 || index > size) {
        cout << "Invalid index" << endl;
        return;
    }
    // Shift all elements from the index to the right
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the element at the specified index
    arr[index] = ele;
    // Increase the size of the array
    size++;
}

/**
 * @brief Inserts an element at the end of the array.
 * 
 * @param arr[] The array where the element is to be inserted.
 * @param size The current size of the array (passed by reference).
 * @param ele The element to insert at the end.
 */
void insertAtEnd(int arr[], int &size, int ele) {
    // Insert the element at the end
    arr[size] = ele;
    // Increase the size of the array
    size++;
}

/**
 * @brief Deletes the first element of the array.
 * 
 * @param arr[] The array from which the element is to be deleted.
 * @param size The current size of the array (passed by reference).
 */
void deleteAtBeginning(int arr[], int &size) {
    // Check if the array is empty
    if (size == 0) {
        cout << "Array is empty" << endl;
        return;
    }
    // Shift all elements to the left to fill the gap
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrease the size of the array
    size--;
}

/**
 * @brief Deletes an element at a specific index in the array.
 * 
 * @param arr[] The array from which the element is to be deleted.
 * @param size The current size of the array (passed by reference).
 * @param index The index of the element to be deleted.
 */
void deleteAtIndex(int arr[], int &size, int index) {
    // Check if the index is valid
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return;
    }
    // Shift all elements from the index to the left to fill the gap
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrease the size of the array
    size--;
}

/**
 * @brief Deletes the last element of the array.
 * 
 * @param arr[] The array from which the element is to be deleted.
 * @param size The current size of the array (passed by reference).
 */
void deleteAtEnd(int arr[], int &size) {
    // Check if the array is empty
    if (size == 0) {
        cout << "Array is empty" << endl;
        return;
    }
    // Simply decrease the size of the array
    size--;
}

/**
 * @brief Performs a linear search for a key in the array.
 * 
 * @param arr[] The array in which to search for the key.
 * @param size The current size of the array.
 * @param key The element to search for.
 * @return The index of the element if found, otherwise -1.
 */
int linearSearch(int arr[], int size, int key) {
    // Traverse the array to find the key
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Element not found
}

/**
 * @brief Performs a binary search for a key in the array.
 * 
 * @param arr[] The sorted array in which to search for the key.
 * @param size The current size of the array.
 * @param key The element to search for.
 * @return The index of the element if found, otherwise -1.
 */
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found
}

/**
 * @brief Sorts the array using the bubble sort algorithm.
 * 
 * @param arr[] The array to be sorted.
 * @param size The current size of the array.
 */
void bubbleSort(int arr[], int size) {
    // Perform bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Displays all elements of the array.
 * 
 * @param arr[] The array to be displayed.
 * @param size The current size of the array.
 */
void displayArray(int arr[], int size) {
    // Traverse the array and print each element
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100]; // Array with large enough size to accommodate multiple insertions
    int n = 0;    // Current size of the array

    // Insert elements
    insertAtEnd(arr, n, 5);
    insertAtEnd(arr, n, 10);
    insertAtEnd(arr, n, 15);
    insertAtBeginning(arr, n, 1);
    insertAtIndex(arr, n, 2, 8);

    cout << "Array after insertions: ";
    displayArray(arr, n);

    // Delete elements
    deleteAtEnd(arr, n);
    deleteAtBeginning(arr, n);
    deleteAtIndex(arr, n, 1);

    cout << "Array after deletions: ";
    displayArray(arr, n);

    // Search elements
    int index = linearSearch(arr, n, 10);
    if (index != -1)
        cout << "Element 10 found at index " << index << endl;
    else
        cout << "Element 10 not found" << endl;

    // Sort and then perform binary search
    bubbleSort(arr, n);
    cout << "Array after sorting: ";
    displayArray(arr, n);

    index = binarySearch(arr, n, 8);
    if (index != -1)
        cout << "Element 8 found at index " << index << endl;
    else
        cout << "Element 8 not found" << endl;

    return 0;
}
