#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    // Remove the top element
    int temp = st.top();
    st.pop();

    // Recursive call
    insert(st, ele);

    // Push the top element back
    st.push(temp);
}

void rev(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }

    // Remove the top element
    int temp = st.top();
    st.pop();

    // Reverse the remaining stack
    rev(st);

    // Insert the removed element at the bottom
    insert(st, temp);
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
    cout << "Enter size: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        st.push(ele);
    }

    // Reverse the stack
    rev(st);

    // Print the reversed stack
    cout << "Reversed stack: ";
    print(st);

    return 0;
}
