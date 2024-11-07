#include<bits/stdc++.h>
using namespace std;

    void bruteForce_arrange(long long arr[], int n) {
        long long temp[n];
        for(int i = 0 ; i < n ; i++){
            temp[i] = arr[arr[i]];
        }
        for(int i = 0 ;i < n ; i++)
            arr[i] = temp[i];
    }

    void optimal_arrange(long long arr[], int n){
        for(int i = 0 ; i < n ; i++){
            int val = arr[i];
            arr[i] = val + (arr[val]%n)*n;
        }

        for(int i = 0 ; i < n ; i++)
            arr[i] /= n;
    }

int main() {
    long long nums1[5] = {4,0,2,1,3};
    bruteForce_arrange(nums1, 5);
    for(int i = 0 ; i < 5; i++)
        cout << nums1[i] << ' ';
    cout << endl;

    long long nums2[5] = {4,0,2,1,3};
    optimal_arrange(nums2, 5);
     for(int i = 0 ; i < 5; i++)
        cout << nums2[i] << ' ';
    cout << endl;
    return 0;
}