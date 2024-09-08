#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cin >> st;
    string s1 = "";

    // Convert uppercase letters to lowercase and collect all characters
    for (auto x : st) {
        if (x >= 'a' && x <= 'z') {
            s1.push_back(x);
        } else {
            int diff=x-'A';
            char ch = (char)('a'+diff); 
            s1.push_back(ch);
        }
    }

    // Print the resulting string with spaces between characters
    for (auto y : s1) {
        cout << y << " ";
    }
    cout << endl; // Ensure a newline at the end

    return 0;
}
