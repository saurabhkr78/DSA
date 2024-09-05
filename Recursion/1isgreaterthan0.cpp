//Print N-bit binary numbers having more 1’s than 0’s for any prefix
//if n==0 base case
//when no of one is greater than zero then choice of zero
//and choice for one is always available
////when no of one is equal to no of zero then no choice of zero
#include <bits/stdc++.h>

using namespace std;

void solve(int one, int zero, int n, string op) {
    if (n == 0) {
        cout << op << endl;
        return;
    }
    
    // Always add '1' choice
    string op1 = op;
    op1.push_back('1');
    solve(one + 1, zero, n - 1, op1);

    // Add '0' choice only if there are more '1's than '0's
    if (one > zero) {
        string op2 = op;
        op2.push_back('0');
        solve(one, zero + 1, n - 1, op2);
    }
}

int main() {
    int n;
    cin >> n;
    string op = "";
    int one = 0;
    int zero = 0;

    solve(one, zero, n, op);

    return 0;
}
