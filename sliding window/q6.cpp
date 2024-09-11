#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; // Change variable name to 's' to match user input
    int k;
    
    cout << "Enter the string: ";
    cin >> s;
    
    cout << "Enter the value of k (number of unique characters): ";
    cin >> k;
    
    int n = s.length();
    if (n == 0 || k == 0) { // Handle edge cases
        cout << "Longest substring length with " << k << " unique characters: 0" << endl;
        return 0; // Return 0 if string is empty or k is 0
    }

    unordered_map<char, int> m; // Map to store character frequencies
    int i = 0, j = 0, max_len = 0; // Correct initialization of max_len

    while (j < n) {
        // Add the current character to the map and increment its frequency
        m[s[j]]++;

        // If the number of unique characters is less than k, expand the window
        if (m.size() < k) {
            j++;
        }
        // If the number of unique characters is exactly k
        else if (m.size() == k) {
            // Update max_len with the size of the current window
            max_len = max(max_len, j - i + 1);
            j++;
        }
        // If the number of unique characters exceeds k, shrink the window
        else if (m.size() > k) {
            m[s[i]]--; // Reduce the frequency of the character at the start of the window
            if (m[s[i]] == 0) {
                m.erase(s[i]); // Remove the character if its frequency becomes 0
            }
            i++; // Shrink the window from the left
        }
    }

    cout << "Longest substring length with " << k << " unique characters: " << max_len << endl;
    return 0;
}
