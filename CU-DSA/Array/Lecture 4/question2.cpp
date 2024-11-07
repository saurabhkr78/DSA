# include<bits/stdc++.h>

using namespace std;

pair<string, int> longDivision(string divident, int divisior){
    string quotient = "";
    int remainder = 0;
    int n = divident.size();

    for(int i = 0 ; i < n ; i++){
        remainder = remainder * 10 + (divident[i] - '0');
        while(i < n-1 && divisior > remainder){
            i++;
            remainder = remainder * 10 + (divident[i] - '0');
            if(quotient != "")
                quotient += '0';
        }
        if(remainder > divisior){
            quotient += (remainder / divisior) + '0';
            remainder %= divisior;
        }
    }
    quotient = quotient == "" ? "0" : quotient;
    return {quotient, remainder};
}

int main(){
    string dividend;
    int divisor;

    cout << "Please enter the dividend (a very large number): ";
    cin >> dividend;

    cout << "Please enter the divisor (1-100): ";
    cin >> divisor;

    if (divisor < 1 || divisor > 100) {
        cerr << "Error: The divisor must be between 1 and 100." << endl;
        return 1;
    }

    auto [quotient, remainder] = longDivision(dividend, divisor);

    cout << "The result of the division is:" << endl;
    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;

    return 0;
}