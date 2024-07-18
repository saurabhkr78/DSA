//rules
// the operator overloading feature of C++ allows it to give the operators a special meaning specific to a data type
//It is the concept of providing an existing C++ operator with additional meaning while maintaining its original meaning.
//provide flexibility to create new meaning to most of the c++ operator
// we can't overload .,*,::,sizeof,?:
// return type will be the type of value returned by the operation
//operator function must be either member function or friend function
//binary arithmatic operators must explicitly return  a value
/*
basic difference between friend and member function is that friend function will have one arg for unary operator and two for binary operator
while member fxn has no arg for unary operator and only one for binary operator.
this is because object used to invoke member fxn is passed implicitly while
in friend fxn args may be passed either by value or reference
*/

/*
where friend fxn cannot be used
==,(),[],->

*/

//unary operator overloading

//overload (-)operator using member fxn 

// #include<iostream>
// using namespace std;
// class overloading{
//     int x,y,z;
//     public:
//     void get(int a,int b,int c){
//        x=a;
//        y=b;
//        z=c; 
//     }
//     void display(){
//         cout<<x;
//         cout<<y;
//         cout<<z;
//     }
//     void operator-(){//takes no arg and -operator fxn changes the sign of data member of object s
//         x=-x;
//         y=-y;
//         z=-z;
//     }
// };
// int main(){
//     overloading o;
//     o.get(10,20,30);
//     cout<<"o: ";
//     o.display();
//     -o;
//     cout<<"o: ";
//     o.display();
//     return 0;
// }
// s2=-s1 won't work because operator-()doesn't return any value it can work if it returns an object

//using friend function
// #include<iostream>
// using namespace std;
// class overloading{
//     int x,y,z;
//     public:
//     void get(int a,int b,int c){
//        x=a;
//        y=b;
//        z=c; 
//     }
//     void display(){
//         cout<<x;
//         cout<<y;
//         cout<<z;
//     }
//     friend void operator-(overloading &o);
       

// };
// void operator-(overloading &o){
//     o.x=-o.x;
//     o.y=-o.y;
//     o.z=-o.z;
// }
// int main(){
//     overloading o;
//     o.get(10,20,30);
//     cout<<"o: ";
//     o.display();
//     -o;
//     cout<<"o: ";
//     o.display();
//     return 0;
// }
//note:same for + operator

//binary operator(two operands)
// for +
// #include<iostream>
// using namespace std;
// class complex{
// float x,y;
// public:
// complex(){

// }
// complex(float real,float img){
//     x=real;
//     y=img;
// }
// complex operator+(complex c){
//     complex temp;
//     temp.x=x+c.x;
//     temp.y=y+c.y;
//     return temp;
// }
// void display(){
//     cout<<x<<"+"<<y<<"i"<<endl;
// }
// };
// int main(){
//     complex c1,c2,c3;
//     c1=complex(10.0,20.0);
//     c2=complex(20.0,30,0);
//     c3=c1+c2;

//     cout<<"C1=";c1.display();
//     cout<<"C1=";c2.display();
//     cout<<"C1=";c3.display();
    
//  return 0;
// }

/*
 Program to demonstrate the unary operator overloading for operator ++.
  Make a class test. Create a default constructor to initialize the variable.
   1) Overload operator ++ (Pre) with definition to pre-increment the value of a variable 
   2) Overload operator ++ (post) with definition to post- increment the value of variable.

*/
#include<iostream>
using namespace std;
class test
{
    private:
    int num;
    public:
    test(){

    }
    test(int n){
        num=n;
    }
    void display(){
        cout<<"num="<<num;

    }
    test operator++(){
        test temp;
        temp.num=++num;
        return temp;
    }
    test operator ++(int){
        num++;
    test temp;
    temp.num=num++;
    return temp;
    
    }


};
int main(){
    test x(20);
    cout<<"before increment"<<endl;
    x.display();

    cout<<"After pre increment"<<endl;
    test y=++x;
    y.display();

    cout<<"After post increment"<<endl;
    test z=++x;
    z.display();
    return 0;
}
