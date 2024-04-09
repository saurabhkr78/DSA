#include<iostream>
#include<limits.h>
using namespace std;
void maxElement(int arr[],int size,int idx,int max){
    if(idx==size){
        cout<<max;
        return ;
    } 
if(arr[idx]>max) max=arr[idx];
cout<<max;
maxElement(arr,size,idx+1,max);
}



int main(){
    
    int size;
    cin>>size;
    int arr[]={1,2,3,4,5,6};
    maxElement(arr,size,0,INT_MIN);
return 0;
}