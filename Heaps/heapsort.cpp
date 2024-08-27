/*Heapsort is a comparison-based sorting algorithm that leverages a binary heap data structure.
 It sorts an array in-place and has a time complexity of O(nlogn)
 -uses a binary heap
 - which is a complete binary tree where every parent node is either greater than or equal to (in a max-heap) or less than or equal to (in a min-heap) its child nodes.


  */


#include<iostream>

using namespace std;

int heapSort(int arr[],int n){

}
 void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}