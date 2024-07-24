//using stack
#include<iostream>
#include<stack>
using namespace std;
int sum(stack<int>&st){
    int Tsum=0;
    stack<int>temp;
    temp=st;
    while(!temp.empty()){
        Tsum+=temp.top();
        temp.pop();
    }
    return Tsum;
}
void check(stack<int>& st1,stack<int>& st2,stack<int>& st3){
    int sum1= sum(st1);
    int sum2= sum(st2);
    int sum3= sum(st3);

    while(!(sum1==sum2&&sum2==sum3))
    {
        if (sum1 >= sum2 && sum1 >= sum3){
            sum1-=st1.top();
            st1.pop();
        }
         else if(sum2 >= sum1 && sum2 >= sum3){
            sum2-=st2.top();
            st2.pop();
        }
        else if(sum3 >= sum1 && sum3 >= sum2){
            sum3-=st3.top();
            st3.pop();
        }
        
    }
    cout<<"Height of Stacks is Equalised"<<endl;

}
int main(){
    stack<int> st1,st2,st3;
    st1.push(1);
    st1.push(3);
    st1.push(2);

    st2.push(1);
    st2.push(4);
    st2.push(1);
    st2.push(1);

    st3.push(1);
    st3.push(9);
    st3.push(1);
    st3.push(6);
    

    check(st1,st2,st3);
    return 0;
}

//using vector
#include <bits/stdc++.h>
using namespace std;

int sumArray(vector<int> &arr) {
    int Tsum = 0;
    for (int i : arr) {
        Tsum += i;
    }
    return Tsum;
}

void check(vector<int> &st1, vector<int> &st2, vector<int> &st3) {
    int sum1 = sumArray(st1);
    int sum2 = sumArray(st2);
    int sum3 = sumArray(st3);

    while (!(sum1 == sum2 && sum2 == sum3)) {
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= st1[0];
            st1.erase(st1.begin());
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= st2[0];
            st2.erase(st2.begin());
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= st3[0];
            st3.erase(st3.begin());
        }
    }
    cout << "Stacks are Equalised" << endl;
}

int main() {
    vector<int> st1 = {3, 2, 1};
    vector<int> st2 = {4, 3, 2};
    vector<int> st3 = {1, 1, 4, 1};

    check(st1, st2, st3);
    return 0;
}


