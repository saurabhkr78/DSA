
#include <iostream>
using namespace std;
void display(int size){
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"enter the index of which you want to see the elemets"<<endl;
    int idx;
    cin>>idx;
    cout<<"the element @index"<<idx<<"is:"<<arr[idx];
}
int main()
{
    display(5);
    

    return 0;
}