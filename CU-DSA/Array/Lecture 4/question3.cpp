#include<bits/stdc++.h>
using namespace std;

string formet_number(string &disturb_number){
    bool sign = false;
    bool integer = false;

    string number;
    for(auto digit : disturb_number){
        if(!sign && !integer && (digit == '+' || digit == '-')){
            number += digit == '-' ? '-' : '\0';
            sign = true;
        }
        if(digit >= '0' && digit <= '9'){
            number += digit;
            integer = true;
        }
    }
    return number;
}

int main() {
    string number;
    cout << "Enter disturb number:" << endl;
    cin >> number;
    cout << "Formeted Number is:" << endl;
    cout << formet_number(number) << endl;
    return 0;
}