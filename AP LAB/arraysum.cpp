#include <iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter size"<<endl;
    cin>>size;
    
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"elements of arrays are: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    cout<<"sum of the given array is"<<sum;
}




