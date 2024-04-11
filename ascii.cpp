#include <iostream>
using namespace std;

int main()
{ 
    char ch;
    cout << "Enter character or digit: ";
    cin >> ch;
    int val = (int) ch;
    cout << val << endl;
    
    if (val >= 48 && val <= 57) {
        cout << "It's a digit." << endl;
    } else if ((val >= 65 && val <= 90) || (val >= 97 && val <= 122)) {
        cout << "It's a character." << endl;
    } else {
        cout << "It's a special character." << endl;
    }
    return 0;
}

