//if class 1 is declared as friend class of class 2.then all the members of class2 can be accessed in class1
#include<iostream>
using namespace std;
class A{
 int x=5;
 friend class B;
};
class B{
public:
void display(A &a){
    cout<<"Value of A="<<a.x;
}
};
int main(){
    A a;
    B b;
    b.display(a);
    return 0;
}
