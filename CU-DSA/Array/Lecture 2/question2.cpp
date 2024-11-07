#include<bits/stdc++.h>
using namespace std;

// with Hashmap
vector<vector<string>> groupAnagrams1(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramMap[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for (auto& pair : anagramMap) {
        result.push_back(pair.second);
    }

    return result;
}

// without hashmap
// Function to group anagrams
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    vector<pair<string, string>> sortedStrs; 

    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        sortedStrs.push_back({sortedStr, str});
    }

    sort(sortedStrs.begin(), sortedStrs.end());

    vector<vector<string>> result;
    vector<string> currentGroup;
    string currentKey = sortedStrs[0].first;
    for (const auto& p : sortedStrs) {
        if (p.first == currentKey) {
            currentGroup.push_back(p.second);
        } else {
            result.push_back(currentGroup);
            currentGroup = {p.second};
            currentKey = p.first;
        }
    }
    result.push_back(currentGroup); 
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams1(strs);

    for (const auto& group : result) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\", ";
        }
        cout << "], ";
    }
    cout << endl;

    result = groupAnagrams2(strs);

    for (const auto& group : result) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\", ";
        }
        cout << "], ";
    }
    cout << endl;

    return 0;
}
