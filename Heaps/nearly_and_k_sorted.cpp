// Q:given an arry where each element is at most k way from its target position.

#include <bits/stdc++.h>
using namespace std;
void sortksorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            arr[j] = minh.top();
            minh.pop();
            j++;
        }
    }
    while (!minh.empty())
    {
        arr[j] = minh.top();
        minh.pop();
        j++;
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    sortksorted(arr, n, k);
    cout << "the sorted array:" << endl;
    print(arr, n);
    return 0;
}