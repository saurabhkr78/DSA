#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
      
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        
        int mx = -1e9, sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            mx = max(mx, v[i]);
            if (sum - mx == mx) count++;
        }
        cout << count << endl;
    }
    return 0;
}
