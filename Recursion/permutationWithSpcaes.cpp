/*
Given a string s, you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings.

Example 1:

Input:
s = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C



*/
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

    // First choice: add space before the next character
    op1.push_back(' ');
    op1.push_back(ip[0]);

    // Second choice: add the character without a space
    op2.push_back(ip[0]);

    // Remove the first character from the input string
    ip.erase(ip.begin());

    // Recursive calls with the two options
    solve(ip, op1);
    solve(ip, op2);
}

int main() {
    string ip;
    cin >> ip;
    
    string op = "";
    op.push_back(ip[0]);  // First character in the output
    ip.erase(ip.begin()); // Remove the first character from input
    
    solve(ip, op); 
    
    return 0;
}


/*Analogy:
Choice Diagram for "ABC":
Initial state: The first character A is always included in the output (op), and then recursion starts from the remaining string "BC".

Step 1: For the string "BC", two choices are made:

Add a space after A.
Do not add a space after A.
Step 2: This process repeats for each remaining character in the string, branching into two choices at each step (add a space or don't).


                                        "A"
                                       /   \
                                      /     \
                            "A B"             "AB"
                           /    \            /    \
                    "A B C"   "A BC"   "AB C"    "ABC"



*/