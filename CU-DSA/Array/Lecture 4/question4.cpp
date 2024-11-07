#include <bits/stdc++.h> 
using namespace std;


vector<vector<int>> leftRotationsOfArray(vector<int> &nums, vector<int> &queries) {
    vector<vector<int>> results;
    int size = nums.size();
    for(auto query : queries){
        vector<int> temp;
        if (size == query || size == 1) {
          results.push_back(nums);
          continue;
        }
        if(size < query){
            query %= size; 
        }
        for(int i = query ; i < size ; i++)
            temp.push_back(nums[i]);
        for(int i = 0 ; i < query ; i++)
            temp.push_back(nums[i]);
        results.push_back(temp);
    }
    return results;
}

int main (){
    int time;
    cin >> time;
    while(time--){
        int n,q;
        cin >> n >> q;

        vector<int> nums;
        for(int i = 0 ; i < n ; i++){
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        vector<int> queries;
        for(int i = 0 ; i < q ; i++){
            int temp;
            cin >> temp;
            queries.push_back(temp);
        }

        vector<vector<int>> results = leftRotationsOfArray(nums, queries);
        for(auto result : results){
            for(auto value: result){
                cout << value << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}