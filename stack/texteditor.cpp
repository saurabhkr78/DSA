#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    string S;
    stack<pair<string, int>> history; // To keep track of the string state and the type of operation
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // Append string w to S
            string w;
            cin >> w;
            history.push({S, 1}); // Save current state and operation type
            S += w;
        } 
        else if (type == 2) {
            // Delete the last k characters from S
            int k;
            cin >> k;
            history.push({S, 2}); // Save current state and operation type
            S.erase(S.size() - k, k);
        } 
        else if (type == 3) {
            // Print the k-th character of S (1-based index)
            int k;
            cin >> k;
            cout << S[k - 1] << endl;
        } 
        else if (type == 4) {
            // Undo the last operation
            if (!history.empty()) {
                auto [prev_state, op_type] = history.top();
                history.pop();
                S = prev_state;
            }
        }
    }
    
    return 0;
}
