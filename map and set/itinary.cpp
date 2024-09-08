#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, string> m{{"chennai", "bangalore"}, {"bombay", "delhi"}, {"goa", "chennai"}, {"delhi", "goa"}};
    unordered_map<string, bool> m2;
    
    // Traverse through the map to mark sources and destinations
    for (auto it = m.begin(); it != m.end(); ++it) {
        string source = it->first;
        string dest = it->second;
        
        // Mark the destination as not a source
        m2[dest] = false;
        
        // Mark the source as a source (if not already marked)
        if (m2.find(source) == m2.end()) {
            m2[source] = true;
        }
    }

    vector<string> v;
    
    // Find all the sources (nodes which are marked true in m2)
    for (auto it2 = m2.begin(); it2 != m2.end(); ++it2) {
        if (it2->second == true) {
            v.push_back(it2->first);  // Use it2 instead of it
        }
    }
    
  // Print all destinations corresponding to the sources
    for (const auto& source : v) {
        auto it3 = m.find(source);
        if (it3 != m.end()) {
            cout << it3->second << " ";
        }
    }

    return 0;
}