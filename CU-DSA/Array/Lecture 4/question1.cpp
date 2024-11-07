#include<bits/stdc++.h>

using namespace std;

// Function to add two positive numbers represented as strings
string addition(string num1, string num2) {
    int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
    string result;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

// Function to subtract two positive numbers represented as strings (num1 >= num2)
string subtraction(string num1, string num2) {
    int i = num1.length() - 1, j = num2.length() - 1, borrow = 0;
    string result;

    while (i >= 0 || j >= 0 || borrow) {
        int diff = (i >= 0 ? num1[i--] - '0' : 0) - (j >= 0 ? num2[j--] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    // Remove leading zeros
    while (result.length() > 1 && result.back() == '0') result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}

// Function to multiply two positive numbers represented as strings
string multiplication(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) product.push_back(num + '0');
    }
    return product.empty() ? "0" : product;
}

// Function to handle signs and perform operations accordingly
string add(string num1, string num2);
string subtract(string num1, string num2);
string multiply(string num1, string num2);

string add(string num1, string num2) {
    bool neg1 = num1[0] == '-', neg2 = num2[0] == '-';
    if (neg1) num1 = num1.substr(1);
    if (neg2) num2 = num2.substr(1);

    if (neg1 && neg2) return '-' + addition(num1, num2);
    if (!neg1 && !neg2) return addition(num1, num2);
    if (neg1 && !neg2) return subtraction(num2, num1);
    if (!neg1 && neg2) return subtraction(num1, num2);
    return 0;
}

string subtract(string num1, string num2) {
    bool neg1 = num1[0] == '-', neg2 = num2[0] == '-';
    if (neg1) num1 = num1.substr(1);
    if (neg2) num2 = num2.substr(1);

    if (neg1 && neg2) return subtraction(num2, num1);
    if (!neg1 && !neg2) return subtraction(num1, num2);
    if (neg1 && !neg2) return '-' + addition(num1, num2);
    if (!neg1 && neg2) return addition(num1, num2);
    return 0;
}

string multiply(string num1, string num2) {
    bool neg1 = num1[0] == '-', neg2 = num2[0] == '-';
    if (neg1) num1 = num1.substr(1);
    if (neg2) num2 = num2.substr(1);

    string result = multiplication(num1, num2);
    if ((neg1 && !neg2) || (!neg1 && neg2)) return '-' + result;
    return result;
}

int main() {
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "Sum: " << add(num1, num2) << endl;
    cout << "Difference: " << subtract(num1, num2) << endl;
    cout << "Product: " << multiply(num1, num2) << endl;

    return 0;
}
