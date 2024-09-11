vector<int> v;
stack<int> s;

for (int i = 0; i < n; i++)
{
    if (s.empty())
        v.push_back(-1);
    else if (!s.empty() and s.top() > arr[i])
        v.push_back(st.top());
    else if (!s.empty() and s.top() < arr[i])
    {
        while (!s.empty() and s.top() <= arr[i])
        {
            s.pop()
        }
        if (!s.empty())
            v.push_back(-1);
        else
            v.push_back(s.top());
    }
    print vector but dont reverse it;
}