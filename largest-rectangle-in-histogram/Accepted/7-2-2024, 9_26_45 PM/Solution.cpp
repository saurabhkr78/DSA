// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int size=arr.size();
    /*..next greater element index..*/
         stack<int> st;
    //prev greater index array
    int ans[size];
    //make last element of array n bcoz next greater element than last element 
    ans[size-1]=size;
    st.push(size-1);
//initially push last element of array into stack

    for (int i = size-2; i >=0; i--) {
       //pop all the element smaller than arr[i] by comparing index
       //maintaining a index of stack elements
        while (st.size()>0 && arr[st.top()] >= arr[i]) st.pop(); 
        //marks the ans array
        if(st.size()==0) ans[i]=size;
        else ans[i]=st.top();
        
        //push [i] if arr
        st.push(i);
    }


 /*..previous smaller element index..*/
    stack<int> st1;
    int ans1[size];
     
    ans1[0]=-1;
    st1.push(0);


    for (int i = 1; i <size; i++) {
      
        while (st1.size()>0 && arr[st1.top()] >= arr[i]) st1.pop(); 
    
        if(st1.size()==0) ans1[i]=-1;
        else ans1[i]=st1.top();
        
        st1.push(i);
    }
    int maxArea=-1;
    for(int i=0;i<size;i++){
    int area=arr[i]*(ans[i]-ans1[i]-1);
    maxArea=max(maxArea,area);
    }
    return maxArea;
    }
};