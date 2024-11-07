#include<bits/stdc++.h>
using namespace std;

bool isRotationBruteForce(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;

    int n = s1.size();
    for (int i = 0; i < n; i++) {
        bool isRotation = true;
        for (int j = 0; j < n; j++) {
            if (s1[(i + j) % n] != s2[j]) {
                isRotation = false;
                break;
            }
        }
        if (isRotation) return true;
    }
    return false;
}

bool isSubstring(const string& str1, const string& str2) {
    return str1.find(str2) != string::npos;
}

bool isRotationOptimal(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;

    string s1s1 = s1 + s1;

    return isSubstring(s1s1, s2);
}

int main() {
    // Test cases
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << (isRotationBruteForce(s1, s2) ? "True" : "False") << endl;
    cout << (isRotationOptimal(s1, s2) ? "True" : "False") << endl;

    s1 = "hello";
    s2 = "llohe";
    cout << (isRotationBruteForce(s1, s2) ? "True" : "False") << endl;
    cout << (isRotationOptimal(s1, s2) ? "True" : "False") << endl;


    s1 = "hello";
    s2 = "lleho";
    cout << (isRotationBruteForce(s1, s2) ? "True" : "False") << endl;
    cout << (isRotationOptimal(s1, s2) ? "True" : "False") << endl;

    return 0;
}
