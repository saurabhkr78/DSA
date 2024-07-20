// reorder queue(interleave 1st half with 2nd half) using one stack only.
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void display(queue<int> &q)
{
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int x = q.front();
        cout << x << " ";
        q.push(x);
        q.pop();
    }
    cout << endl;
}
void reorder(queue<int> &q)
{
    stack<int> st;
    // transfer 1st half of the queue to stack
    int n = q.size();
    for (int i = 1; i <= n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    // empty the stack into queue
    while (st.size() > 0)
    {
        q.push(st.top());
        st.pop();
    }
    // pop the second half which is now first half
    for (int i = 1; i <= n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    // interleave
    while (st.size() > 0)
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    // reverse the queue using stack
    while (q.size() > 0)
    {
        st.push(q.front());
        q.pop();
    }
    while (st.size() > 0)
    {
        q.push(st.top());
        st.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    display(q);
    reorder(q);
    display(q);
}