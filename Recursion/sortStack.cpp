// // using vector
// #include <iostream>
// #include <vector>

// using namespace std;
// void insert(vector<int> &v, int temp)
// {
//     if (v.empty() || v.back() <= temp)
//     {
//         v.push_back(temp);
//         return;
//     }
//     int last = v.back();
//     v.pop_back();
//     insert(v, temp);
//     v.push_back(last);
// }
// void print(const vector<int> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }
// void sort(vector<int> &v)
// {
//     if (v.size() <= 1)
//         return;

//     int temp;
//     temp = v.back();
//     v.pop_back();
//     sort(v);
//     insert(v, temp);
// }
// int main() {
//     int n;
//     cout << "Enter size of vector: ";
//     cin >> n;

//     vector<int> v(n);
//     cout << "Enter elements of the vector:" << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }

//     sort(v);
//     cout << "Sorted vector: ";
//     print(v);

//     return 0;
// }

//using stack
#include <iostream>
#include<stack>

using namespace std;
void insert(stack<int> &st, int temp)
{
    if (st.empty() || st.top() <= temp)
    {
        st.push(temp);
        return;
    }
    int last = st.top();
    st.pop();
    insert(st, temp);
    st.push(last);
}
void print(stack<int> st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
    cout << endl;
}
void sort(stack<int> &st)
{
    if (st.size() <= 1)
        return;

    int temp=st.top();
    st.pop();
    sort(st);
    insert(st,temp);
}
int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;

    stack<int>st;

    cout << "Enter elements of the stack:" << endl;
    for (int i = 0; i < n; i++) {
        int ele;
        cin>>ele;
        st.push(ele);
    }

    sort(st);
    cout << "Sorted stack: ";
    print(st);

    return 0;
}