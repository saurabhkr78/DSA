// copy constructor 
//A Copy constructor is an overloaded constructor used to declare and initialize an object from another object.
//it takes a reference to an object of the same class as itself as an argument
//two types
//If the user defines no copy constructor, compiler supplies its constructor.it's default constructor
// user defined copy constructor



// #include<iostream>
// using namespace std;
// class A{
//     int a,b;
//     public:
//     A(int x,int y){
//         a=x;b=y;

//     }
//     //copy constructor
//     A(A *ref){
//         a=ref->a;
//         b=ref->b;
//     }
//     void show(){
//         cout<<"a:"<<a<<endl<<"b"<<b<<endl;
//     }
// };
// int main(){
//     A obj(10,20);
//     A obj2(&obj);
//     obj.show();
// }

// #include<iostream>
// using namespace std;
// class code{
// int id;
// public:
// //default
// code(){

// }
// //parametrized 
// code(int a){
//     id=a;
// }
// //copy
// code(code &x){//reference variable is used as an argument
//     id=x.id;
// }
// void display(){
//     cout<<id;
// }
// };
// int main(){
//     code A(100);
//     code B(A);//copy constructor called
//     code C=A;//copy called again
//     code D;//D object is created but not initalized
//     D=A;//copy constructor not called
// cout<<"id of A:";
// A.display();
// B.display();
// C.display();
// D.display();

//     return 0;
// }
/*WAP to create database of the following items: Name of the student (String), Roll number of the student (int), Height of the student (cm), Weight of the student (kg/gms)

1) Create a Constructor to initialize values

2) Create display () function to display the details

3) Illustrate the use of copy constructor

4) Also implement the concept of destructor.
*/
#include<iostream>
using namespace std;
int count=0;
class student{
 string name;
 int roll;
 int height;
 int weight;
 public:
  student(string n,int r,int h,int w){
    count++;

    name=n;
    roll=r;
    height=h;
    weight=w;

  }
  student(student &x){
    count++;
    cout<<"Number of object created"<<count<<endl;
   name= x.name;
   roll=x.roll;
   height=x.height;
   weight=x.weight;

  }
  void display(){
    cout<<"Name:"<<name<<endl<<"RollNo"<<roll<<endl<<"height"<<height<<endl<<"Weight"<<weight<<endl;
  }
  ~student(){
    cout<<"Destructor is called"<<endl;
    count--;
    cout<<"number of object destroyed"<<count<<endl;
  }

};

int main(){
    student s("saurabh",11917,6,62);
    student  s1(s);
    s1.display();
    return 0;
}


