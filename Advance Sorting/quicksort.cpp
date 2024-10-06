#include<iostream>
using namespace std;
int partition(int arr[],int si,int ei){
    int pivotElement=arr[si];
    int count=0;
    for(int i=si+1;i<=ei;i++){
        if(arr[i]<=pivotElement) count++;
    }
    int pivotIdx=count+si;
    swap(arr[si],arr[pivotIdx]);
    int i=si;
    int j=ei;
    while(i<=pivotIdx&& j>pivotIdx){
        if(arr[i]<=pivotElement) i++;
        if (arr[j]>pivotElement) j--;
        if(arr[i]>pivotElement&&arr[j]<=pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
}



void quicksort(int arr[],int si,int ei){
    if(si>=ei) return;
    int pivotIndex=partition(arr,si,ei);
    quicksort(arr,0,pivotIndex-1);
    quicksort(arr,pivotIndex+1,ei);
}




int main(){
    int arr[]={8,4,11,13,2,6,1,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}