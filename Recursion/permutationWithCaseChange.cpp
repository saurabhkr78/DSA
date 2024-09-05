#include<iostream>
using namespace std;

void solve(string ip, string op) {
    if(ip.length() == 0) {
        cout << op << "\n";  // base condition: print the result with a new line
        return;
    }
    
    // Two choices for the output string
    string op1 = op;
    string op2 = op;

    // Option 1: add the current character as is (lowercase)
    op1.push_back(ip[0]);
    
    // Option 2: add the current character in uppercase
    op2.push_back(toupper(ip[0]));

    // Remove the first character from the input string
    ip.erase(ip.begin());

    // Recursive calls with the two options
    solve(ip, op1);
    solve(ip, op2);
}

int main() {
    string ip;
    cin >> ip;
    
    // Starting point: two options for the first character
    string op1 = "", op2 = "";
    op1.push_back(ip[0]);              // First character as is (lowercase)
    op2.push_back(toupper(ip[0]));     // First character in uppercase
    
    ip.erase(ip.begin());  // Remove the first character from input
    
    // Call solve for both starting options
    solve(ip, op1);  // Proceed with lowercase first character
    solve(ip, op2);  // Proceed with uppercase first character
    
    return 0;
}
