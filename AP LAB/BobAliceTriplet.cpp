#include <bits/stdc++.h>

using namespace std;

int main() {
    int a1, a2, a3, alicePoints = 0, b1, b2, b3, bobPoints = 0;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    alicePoint = ((a1 > b1? 1:0)) + ((a2 > b2? 1:0)) + ((a3 > b3? 1:0));
    bobPoint = ((a1 < b1? 1:0)) + ((a2 < b2? 1:0)) + ((a3 < b3? 1:0));
    cout << alicePoints << " " << bobPoints ;
    return 0;
}