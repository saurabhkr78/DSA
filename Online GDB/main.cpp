/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

//Print index of a given element in an array. If not present, print -1.

*******************************************************************************/
#include <iostream>
#include <vector> 
using namespace std;

int index(vector<int> &a, int CurrentIndex, int n, int element){
    if(CurrentIndex == n) return -1;
    
    if(a[CurrentIndex] == element){
        return CurrentIndex;
    }
    return index(a, CurrentIndex+1, n, element);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int element;
    cin >> element;
    cout << index(a, 0, n, element);
    return 0;
}
