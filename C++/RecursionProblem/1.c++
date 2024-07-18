// #include<iostream>
// using namespace std;
 
//  void fun(){
//     cout<<"1";
//     fun();
//  }
//  int main(){
//  fun();
//     return 0;
//  }
// #include<iostream>
// using namespace std;
// int count=0;
// void print(){
//     if(count==3)
//         return;
//     }
//     count++;
//     cout<<count<<endl;
//     print();
// }
// int main(){
//     print();
//     return 0;
// }

//print name n times
#include<iostream>
using namespace std;
void fun(int i,int n){
    if(i>n){
        return ;

    }
    cout<<"Saurabh\n";
    fun(i+1,n);
}


int main(){
    int n;
    cin>>n;

    fun(1,n);
    return 0;

}
//4 to 1 using recursion
#include<iostream>
using namespace std;
void fun(int i,int n){
    if(i<1)
        return;
        cout<<i<<"\n";
    fun(i-1,n);

}
int main(){
    int n;
    cout<<"enter n\n";
    cin>>n;
    fun(n,n);
    
    return 0;
}
//1 to n without using + (backtracing)
#include<iostream>
using namespace std;
void fun(int i,int n){
    if(i<1)
        return;
        cout<<i<<"\n";
    fun(i-1,n);
     cout<<i<<"\n";

}
int main(){
    int n;
    cout<<"enter n\n";
    cin>>n;
    fun(n,n);
    
    return 0;
}

