/*
longest substring with k at most K distinct chars==longest substring with k distinct chars.
longest substring with k at least K distinct chars
fruits and basket



*/

/*
mummy ji ki conditions:
1. line s uthao --> mtlb substring
2. max k types --> max k unique characters in the substring
3. so k=2 as he can only pick 2 types of toys
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{

    vector<int> fruits = {1, 2, 1, 2, 3};

    int i = 0;
    int j = 0;

    // Variable to store the maximum length of subarrays with at most two distinct fruit types
    int mx_len = 1;

    // Hash map to keep track of the frequency of each fruit type in the current window
    unordered_map<int, int> mp;

    // Traverse the fruits vector using the right pointer
    while (j < fruits.size())
    {
        // Increment the frequency of the fruit at position j in the map
        mp[fruits[j]]++;

        // If the current window contains at most 2 distinct fruit types
        if (mp.size() <= 2)
        {
            // Update the maximum length of such a window
            mx_len = max(mx_len, j - i + 1);
        }

        // If the current window contains more than 2 distinct fruit types
        if (mp.size() > 2)
        {
            // Shrink the window from the left by moving the left pointer i
            while (mp.size() > 2)
            {
                mp[fruits[i]]--; // Decrease the frequency of the fruit at i
                // If the frequency of a fruit becomes zero, remove it from the map
                if (mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++; // Move the left pointer to the right
            }
        }

        j++; // Move the right pointer to the next fruit
    }

    cout << "Maximum number of fruits: " << mx_len << endl;

    return 0;
}
