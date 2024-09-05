// not a  comparison based algo
//given n input size(defined input set) and range k is defined
//not an inplace algo we make a new array of one xtra size(max element in array+1) to work upon.
// traverse and check occurence of each element and update their count in array at their index in new array
//time-O(n+k) and space-O(k)
//limitations:restricted to range and extra space if a greater number appears e.g 2 3 2000 5
//stable

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findMax(const vector<int>& arr) {
    int mx = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > mx) 
            mx = arr[i];
    }
    return mx;
}

void countSort(vector<int>& arr) {
    int mx = findMax(arr);
    vector<int> count(mx + 1, 0); // Initialize count array with zero

    // Store the count of each element
    for(int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    // Refill the original array with sorted elements
    int index = 0;
    for(int i = 0; i <= mx; i++) {
    for(int j=0;j<count[i];j++) {
            arr[index++] = i;
        }
    }
}

int main() {
    vector<int> arr = {1, 4, 5, 2, 2, 5};
    
    cout << "Original array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countSort(arr);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//application:different flights leaving a airport at different time 
