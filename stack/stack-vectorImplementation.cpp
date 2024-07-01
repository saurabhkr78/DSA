#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
    vector<int> v;
    int idx = -1;

    void push(int val) {
        idx++;
        v.push_back(val);
    }

    void pop() {
        if (idx == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }
        v.pop_back();
        idx--;
    }

    int top() {
        if (idx == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return v[v.size()-1];//v.size()-1 return vector last element
    }

    int size() {
        return v.size();
    }

    void display() {
        for (int i = 0; i <= idx; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    cout << st.top() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    st.display();

    return 0;
}
