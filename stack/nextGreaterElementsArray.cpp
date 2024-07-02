#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// if arr[i]<=st.top() then pop that element
//else element is st.top is greater element than arr[i] then push it in ans[i];
//and arr[i] element ko push karo stack mein because probability of being next greater element of next number of arr[i]
//if stack is empty then mark ans[i]=-1;

int main() {
    int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    stack<int> st;
    int ans[size];
    //make last element of array -1 bcoz no next greater element than last element
    ans[size-1]=-1;
    st.push(arr[size-1]);
//initially push last element of array into stack

    for (int i = size-2; i >=0; i--) {
       //pop all the element smaller than arr[i]
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop(); 
        }
        //marks the ans array
        if(!st.size()) ans[i]=-1;
        else ans[i]=st.top();
        //push the element arr[i]
        st.push(arr[i]);
    }


    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
