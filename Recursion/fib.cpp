#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int sum = 0;
    return sum = fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cout << "enter no of terms" << endl;
    cin >> n;
    cout << fib(n);
}