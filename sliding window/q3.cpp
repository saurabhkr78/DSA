/*
Gist of the logic:

1.	Create an unordered map for the given pattern. The map stores all the distinct characters of the pattern as keys, and their frequencies as values. Create a variable count, which has the count of all the distinct characters in the pattern, which is the size of the map. Create another variable for storing the actual answer.
2.	Inside the while loop, compare the jth character with the keys of the map. If this character is found in the map, decrement its corresponding value. If the value of any of the keys becomes 0, decrement the value of count. It means that you’ve found one character in its required quantity in your current window. Like this if for every character in the map, the value becomes 0, then the value of count becomes 0, and it signifies that the current window is an anagram of the pattern. We’re using this count variable to signify whether the window is an anagram or not(in O(1) time), otherwise we have to traverse the whole map for checking if every corresponding value has become 0 or not, and it would have taken O(K) time.
3.	When you’ve reached the window size, you need to do 2 things:-
a)	Retrieving the answer- if the count becomes 0, anagram is found, increment the value of ans variable.
b)	Sliding the window- before sliding the window, we need to remove all the calculations regarding the first element in the current window. If it exists in the map, then we need to increment the corresponding value in the map. Why we’re incrementing its value because, this character is not going to be there in our next window, so if it has contributed in making an anagram for our previous window, we need to delete its appearance or significance in the map, which tells that there’s a gap which needs to be filled by the next incoming character to complete this incomplete anagram. And only if the corresponding value in the map has become 1, we’ll increment the value of count, and not for any other case.
For eg:-
Pattern- aaba
Current state of Map – a->3
                         b->1
count=2

window has:- acbe
Current state of Map – a->2
                              b->0
count=1 (what current state of the map signifies is, we need 2 more a's to complete an anagram)
We have to remove this 'a', as it is the first element of the current window, because we need to move ahead now:-
window is: cbe_
Current state of the map- a->3
                                              b->0
count=1  (this state of the map signifies that we need 3 a's to find an anagram)


In such case we’re removing this ‘a’ from the window, so we increment its value to 3, we shouldn’t increment the value of count in this case. Increment the count only if the corresponding value becomes 1 after incrementing it. Because the whole part of ‘a’ is not gone by removing the first element of the previous window, some part of it is gone with it. When the whole part is gone, then we can say that okay, there’s one more character which needs to be found in the next window in its whole quantity.
If we don't restore the frequency of the character at the start before sliding the window, the frequency map will remain incorrect for future windows. This would lead to inaccurate anagram detection since characters that leave the window would still be counted as if they were in it.

Example:
Consider str = "cbaebabacd" and ptr = "abc":

The first window is "cba". We reduce the frequencies for 'c', 'b', and 'a'.
Now, we slide the window to "bae":
Before sliding, we restore the frequency of 'c' because it is no longer part of the window.
This prepares the map correctly for the new window "bae".
*/
// count occurence of anagram

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input strings
    string str = "abab"; // Input string where we will search for anagrams of 'ptr'
    string ptr = "ab";   // Pattern string for which we need to find anagrams

    unordered_map<char, int> mp; // Frequency map to store the count of characters in 'ptr'

    // Build a frequency map for the pattern string 'ptr'
    for (auto it : ptr)
        mp[it]++; // Increment the frequency of each character in 'ptr'

    // Initialize variables
    int DistinctCharCount = mp.size(); // Number of distinct characters in 'ptr' that need to be matched
    int start = 0, end = 0;            // Two pointers for the sliding window
    int windowSize = ptr.size();       // The size of the sliding window, equal to the size of 'ptr'
    int noswindow = 0;                 // Count of valid anagram windows found

    vector<int> resultIndices; // Vector to store the starting indices of all valid anagram windows

    // Traverse the input string using the sliding window approach
    while (end < str.size()) {
        // Check if the current character at 'end' is in the pattern
        if (mp.find(str[end]) != mp.end()) {
            mp[str[end]]--; // Decrease its frequency in the map as it's part of the window
            if (mp[str[end]] == 0)
                DistinctCharCount--; // If frequency becomes 0, we matched one distinct character
        }

        // If the current window size is smaller than the required window size, move 'end' forward
        if (end - start + 1 < windowSize) {
            end++;
        }
        // When the window size matches the size of the pattern 'ptr'
        else if (end - start + 1 == windowSize) {
            // If all distinct characters have been matched, it's a valid anagram window
            if (DistinctCharCount == 0) {
                noswindow++;                // Increment the count of valid anagram windows
                resultIndices.push_back(start); // Store the starting index of this valid window
            }

            // Before sliding the window, restore the frequency of the character at the 'start' of the window
            if (mp.find(str[start]) != mp.end()) {
                mp[str[start]]++; // Restore the frequency as the character leaves the window
                if (mp[str[start]] == 1)
                    DistinctCharCount++; // If its frequency becomes positive, we need this character again
            }

            // Slide the window by moving both 'start' and 'end' one step forward
            start++;
            end++;
        }
    }

 
    cout << "Number of anagrams found: " << noswindow << endl; 
    cout << "Starting indices of anagrams: "<<endl;
    for (int idx : resultIndices) {
        cout << idx << " "; 
    }
    cout << endl;

    return 0;
}
