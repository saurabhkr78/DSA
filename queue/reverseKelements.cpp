#include<iostream>
#include<queue>
#include<stack>
using namespace std;
   void reverseK(int k, queue<int> &q) {
    stack<int> st;
    // Step 1: Push the first k elements into the stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }
    // Step 2: Push the elements back into the queue in reverse order
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    // Step 3: Move the remaining elements to the back of the queue
    int n = q.size();
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}



void display(queue<int> &q)
{
    int n = q.size();
    for (int i = 0; i <n; i++)
    {
        int x = q.front();
        cout << x << " ";
        q.push(x);
        q.pop();
    }
    cout << endl;
}
int main(){
queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.push(60);
display(q);
int k=2;
reverseK(k,q);
display(q);

}