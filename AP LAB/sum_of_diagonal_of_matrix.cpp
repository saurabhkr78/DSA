#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int arr[n][n];
    int RDSum = 0;
    int LDSum = 0;

    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        RDSum += arr[i][i];
        LDSum += arr[i][n-i-1];
    }

    int absoluteDiff = abs(RDSum - LDSum);

    cout << "Left-to-right diagonal sum = " << RDSum << endl;
    cout << "Right-to-left diagonal sum = " << LDSum << endl;
    cout << "Their absolute difference is: " << absoluteDiff << endl;

    return 0;
}
