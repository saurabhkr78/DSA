#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ch char
#define f(i, a, n) for (int i = a; i < n; i++)
#define f2(j, a, n) for (int j = a; j < n; j++)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int32_t main() {
    fast_io; // Set up fast I/O

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ch c;
        int row1 = -1, row2 = -1;
        int col1 = 1e9, col2 = -1;

        f(i, 0, n) { // Loop over rows
            f2(j, 0, m) { // Loop over columns
                cin >> c;
                if (c == '#') {
                    if (row1 == -1) row1 = i + 1;
                    row2 = i + 1;
                    if (col1 > j + 1) col1 = j + 1;
                    if (col2 < j + 1) col2 = j + 1;
                }
            }
        }

        int x = (row1 + row2) / 2;
        int y = (col1 + col2) / 2;
        cout << x << ' ' << y << endl;
    }
    
    return 0;
}
