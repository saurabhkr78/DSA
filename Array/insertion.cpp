#include<iostream>
using namespace std;
void insertAtEnd(int arr[], int &size, int ele) {
    // Insert the new element at the end
    arr[size] = ele;
    // Increase the size of the array
    size++;
}
void insertAtStart(int arr[], int &size, int ele) {
    // Shift all elements one position to the right
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element at the start
    arr[0] = ele;
    // Increase the size of the array
    size++;
}
void insertAtIndex(int arr[], int &size,int idx, int ele){
    if(idx==0)insertAtStart(arr,size,ele);
    if(idx==size) insertAtEnd(arr,size,ele);
    if(idx<0||idx>size){
         cout<<"index out of bound"<<endl;
         return;
    }
    //shift element to right to make space for new ele
    for(int i=size;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[idx]=ele;//Insert the new element at the given index
    size++;// Increase the size of the array


}

int main() {
    cout << "Enter size: ";
    int n;
    cin >> n;

    // Assume we can insert one extra element
    int arr[n + 1]; // Allocate one extra space to accommodate the new element

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element you want to insert: ";
    int ele;
    cin >> ele;

    insertAtStart(arr, n, ele);
    insertAtEnd(arr, n, ele);

    cout << "Array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
