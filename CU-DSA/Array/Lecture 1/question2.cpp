#include<bits/stdc++.h>
using namespace std;

int bruteforce_majority(vector<int> arr){
    sort(arr.begin(), arr.end());
    int count = 1;
    int val = arr[0];
    int maxCount = 1;
    int majority = val;
    for(int i = 1; i < arr.size() ; i++){
        if(val == arr[i]){
            count++;
        }else{
            val = arr[i];
            count = 1;
        }
        if(count > maxCount){
            maxCount = count;
            majority = val;
        }
    }
    return majority;
}

int optimal_majority(vector<int> arr){
    int count = 1;
    int val = arr[0];

    for(int i = 1; i < arr.size() ; i++){
        if(val == arr[i]){
            count++;
        }else count --;
        if(count == 0){
            val = arr[i];
            count = 1;
        }
    }
    return val;
}

int main() {
    cout << bruteforce_majority(arr) << endl;
    cout << optimal_majority(arr) << endl;
    return 0;
}