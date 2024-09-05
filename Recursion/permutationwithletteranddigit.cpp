#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(string ip, string op, vector<string> &result) {
        if(ip.length() == 0) {
            result.push_back(op);
            return;
        }

        // Check if the current character is a digit
        if(isdigit(ip[0])) {
            // If it's a digit, no case change is required, just add it to the output
            string op1 = op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin());
            solve(ip, op1, result);  // Continue with the next character
        } else {
            // If it's a letter, we have two options: lowercase or uppercase
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));  // add lowercase letter
            op2.push_back(toupper(ip[0]));  // add uppercase letter

            ip.erase(ip.begin());  // Remove the processed character from input

            // Recursive calls with both options
            solve(ip, op1, result);
            solve(ip, op2, result);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string op = "";
        solve(s, op, result);  // Start the recursion
        return result;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    
    vector<string> result = sol.letterCasePermutation(s);
    
    // Print the result
    for(auto str : result) {
        cout << str << " ";
    }

    return 0;
}
