#include<bits/stdc++.h>
using namespace std;

string convert(string &s, int numRows) {
    if(numRows == 1)
        return s;
    string zigzag;
    int length = s.size();
    int diff1 = (numRows+(numRows-2));
    int diff2 = 0;
    for(int row = 0 ; row < numRows ; row++){
        bool turn = true;
        int col = row;
        while(col < s.length()){
            zigzag += s[col];
            if(turn){
                col += (diff1 == 0) ? diff2 : diff1;
                turn = false;
            }else {
                col += (diff2 == 0) ? diff1 : diff2;
                turn = true;
            }
        }
        diff1 -= 2;
        diff2 += 2;
    }
    return zigzag;
}

int main() {
    string str = "PAYPALISHIRING";
    int numRows = 3;
    string result = convert(str, numRows);
    cout << str << " of zigzag conversion " << result << endl;
    return 0;
}