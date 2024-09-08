//Print first ‘n’ fibonacci numbers.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int first=0, second=1, next, num;
    cout << "Enter the number of terms: ";
    cin >> num;
    cout << first << " " << second << " "; // printing 0 and 1

    for(int i=2; i<num; i++) // loop starts from 2 because 0 and 1 are already printed
    {
        next = first + second;
        cout << next << " ";
        first = second; // update values of first and second
        second = next;
    }

    return 0;
}