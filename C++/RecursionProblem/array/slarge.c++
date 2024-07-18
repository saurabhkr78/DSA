#include<iostream>
#include<vector>
#include <climits>
using namespace std;

void secondLargest(int a[], int n) {
    int i;
    int largest = a[0];
    int slargest = -1;
    for (i = 0; i < n; i++) {
        if (a[i] > largest) {
            slargest = largest;
            largest = a[i];
        } else if (a[i] < largest && a[i] > slargest) { 6 7 8 9 10
            slargest = a[i];
        }
    }
    cout << "Second Largest=" << slargest << endl;
}

void secondsmallest(int a[], int n) {
    int i;
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for (i = 0; i < n; i++) {
        if (a[i] < smallest) {
            ssmallest = smallest;
            smallest = a[i];
        } else if (a[i] != smallest && a[i] < ssmallest) {
            ssmallest = a[i];
        }
    }
    cout << "Second smallest=" << ssmallest << endl;
}

int main() {
    int arr[] = {10, 5, 8, 20};
    int size = 4;

    secondLargest(arr, size);
    secondsmallest(arr, size);

    return 0;
}
