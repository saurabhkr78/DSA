#include<bits/stdc++.h>
using namespace std;

string stringNumber(int val){
    string numbers [10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return numbers[val];
}

string numberToText(string number){
    if(number.length() < 10 || number.length() > 10)
        return "not a valid number";

    int term = 1;
    char value = number[0];
    string strNumber = "";

    for(int i = 1 ; i < number.length() ; i++){
        if(number[i] == value){
            term++;
        }
        else{
            if(term == 3) strNumber += "triple ";
            if(term == 2) strNumber += "twice ";
            strNumber += (stringNumber(value - '0') + ' ');
            term = 1;
            value = number[i];
        }

        if(term == 3){
            strNumber += "triple";
            strNumber += (stringNumber(value - '0') + ' ');
            term = 1;
            value = number[++i];
        }
    }
    if(term == 3) strNumber += "triple";
    if(term == 2) strNumber += "twice";
    strNumber += (stringNumber(value - '0') + ' ');

    return strNumber;
}

int main() {

    string number;
    cin >> number;

    cout << "Your mobile Number is: " << numberToText(number) << endl;
    return 0;
}