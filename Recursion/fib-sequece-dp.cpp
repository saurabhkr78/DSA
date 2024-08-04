// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> memo;

// int fib(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     if (memo[n] != -1) return memo[n];
//     memo[n] = fib(n - 1) + fib(n - 2);
//     return memo[n];
// }

// void printFibSequence(int n) {
//     for (int i = 0; i < n; ++i) {
//         cout << fib(i) << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n;
//     cout << "Enter the number of terms: ";
//     cin >> n;
//     memo.resize(n + 1, -1); // Initialize the memoization vector with -1
//     printFibSequence(n);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}
void print(int n, int current = 0)
{

    if (current == n)
        return; // Base case: if we've printed n terms, stop the recursion

    cout << fib(current) << " ";
    print(n, current + 1); // Recursive call with the next term
}

int main()
{
    cout << "enter no of terms" << endl;
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    // Print Fibonacci sequence
    print(n);
    cout << endl;
}
