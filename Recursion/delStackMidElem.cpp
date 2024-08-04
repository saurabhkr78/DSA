#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &st, int k)
{
    if (k == 1)//base
    {

        st.pop();
        return;
    }


    // Remove the top element
    int temp = st.top();
    st.pop();

    // Recursive call to reach the middle element
    solve(st, k - 1);

    // Push the top element back after removing the middle element
    st.push(temp);

}
void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{
    cout << "enter size" << endl;
    int n;
    cin >> n;

    cout << "enter elements" << endl;

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        st.push(ele);
    }
    int k = st.size() / 2 + 1;
    solve(st, k);
    print(st);
}