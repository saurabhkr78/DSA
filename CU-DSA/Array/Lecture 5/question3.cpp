#include <bits/stdc++.h> 
using namespace std;

vector<int> merge(vector<int> &array1, vector<int> &array2){
    int n1 = array1.size();
    int n2 = array2.size();

    int i = 0, j = 0;
    vector<int> result;
    while(i < n1 && j < n2){
        if(array1[i] < array2[j]){
            result.push_back(array1[i]);
            i++;
        }else{
            result.push_back(array2[j]);
            j++;
        }
    }
    while(i < n1) result.push_back(array1[i++]);    
    while(j < n2) result.push_back(array2[j++]);
    return result;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int>temp = kArrays[0];
    for(int i = 1 ; i < k ; i++){
        temp = merge(temp, kArrays[i]);
    }
    return temp;
}

int main(){
    int k;
    cin >> k;
    vector<vector<int>> kArrays;
    for(int i = 0 ; i < k ; i++){
        int n;
        cin >> n;
        vector<int> temp;
        while(n--){
            int tmp;
            cin >> tmp;
            temp.push_back(tmp);
        }
        kArrays.push_back(temp);
    }

    vector<int> result = mergeKSortedArrays(kArrays, k);
    for(auto num : result){
            cout << num << ' ';
    }
    cout << endl;
    return 0;
}