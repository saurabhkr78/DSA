#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// if arr[i]<=st.top() then pop that element
//else element is st.top is greater element than arr[i] then push it in ans[i];
//and arr[i] element ko push karo stack mein because probability of being next greater element of next number of arr[i]
//if stack is empty then mark ans[i]=-1;

int main() {
    int arr[] = {100,80, 60, 81, 70, 60, 75, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    stack<int> st;
    //prev greater index array
    int ans[size];
    //make last element of array -1 bcoz no next greater element than last element
    ans[0]=1;
    st.push(0);
//initially push last element of array into stack

    for (int i = 1; i <size; i++) {
       //pop all the element smaller than arr[i] by comparing index
       //maintaining a index of stack elements
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop(); 
        }
        //marks the ans array
        if(!st.size()) ans[i]=-1;
        else ans[i]=st.top();
        //ans[i]=i-ans[i];
        
        //push [i] if arr
        st.push(i);
    }
     for (int i = 1; i < size; i++) {
        ans[i]=i-ans[i];
    }
        
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
