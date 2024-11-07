#include<bits/stdc++.h>
using namespace std;

char numberString(string val){
    if(val == "zero") return '0';
    if(val == "one") return '1';
    if(val == "two") return '2';
    if(val == "three") return '3';
    if(val == "four") return '4';
    if(val == "five") return '5';
    if(val == "six") return '6';
    if(val == "seven") return '7';
    if(val == "eight") return '8';
    if(val == "nine") return '9';
    return -1;

}

string textToNumber(string &strNumber){
    int time = 1;
    string number = "";
    string num = "";
    int n = strNumber.length();
    for(int i = 0 ; i <= n ; i++){
        if(strNumber[i] == ' ' || i == n){
            if(num == "triple"){
                time = 3;
            } else if(num == "double"){ 
                time = 2;
            } else {
                while(time--){
                    number += numberString(num);
                }
                time = 1;
            }
            num = "";
        }else num += strNumber[i];
    }
    if(number.length() < 10 || number.length() > 10)
        return "not a valid number";
    return number;
}

int main() {
    string strNumber = "triple eight seven one three five two double seven";
    cout << "Your mobile number is: " << textToNumber(strNumber) << endl;

    strNumber = "double nine triple eight eight six triple zero";
    cout << "Your mobile number is: " << textToNumber(strNumber) << endl;

    strNumber = "nine eight seven";
    cout << "Your mobile number is: " << textToNumber(strNumber) << endl;
    return 0;
}