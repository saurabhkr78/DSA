
// #include<iostream>
// using namespace std;
// class student
// {
//     private:
//     int marks;

//     public:
//     student(){
//         marks=0;

//     }
//     void display(){
//         cout<<"marks="<<marks;

//     }
//     friend void input(student &s);


    
// };
// void input(student &s){
// s.marks=s.marks+10;
// }
// int main()
// {
//     student s;
//     s.display();
//     input(s);
//     s.display();


//     return 0;
// }

//add members of two different class using friend function

// #include<iostream>
// using namespace std;
// class cal2;
// class cal{
// private:
// int num;
// public:
// cal(){
//     num=2;
// }
// friend int add(class cal,class cal2);
// };
// class cal2{
//     private:
//     int num2;
//     public:
//     cal2(){
//        num2=9;
//     }
// friend int add(class cal,class cal2);
// };
// int add(cal a,cal2 b){
//     return(a.num+b.num2);
// }
// int main(){
//     cal a;
//     cal2 b;
//     cout<<"total="<<add(a,b);
// }



// #include<iostream>
// using namespace std;
// class student2;
// class student{
//     private:
//     int marks;
//     public:
//     // student(){
//     //     cout<<"enter marks of student1:"<<endl;
//     //     cin>> marks;
//     // }
//     // student():marks(10){}
//     student(int m){
//         marks=m;
//     }
//     friend void add(class student,class student2);

// };
// class student2{
// private:
// int marks2;
// public:

// // student2(){
// //     // marks2=20;
// //     cout<<"enter marks of student 2:"<<endl;
// //     cin>>marks2;
// // student2():marks2(20){}
// student2(int n){
//     marks2=n;
// }

// friend void add(class student,class student2);


// };
// void add(student a,student2 b){
//    cout<< a.marks+b.marks2;
// }
// int main(){
//     student a(10);
//     student2 b(20);
//     add(a,b);
// }

//wap to swap private data members of two class using friend function
// #include<iostream>
// using namespace std;
// class B;

// class A{
//     private:
//     int num;
//     public:
//     A():num(10){}
//     void display(){
//         cout<<"value of class A="<<num<<endl;
//     }
//     friend void swap(class A,class B);
// };
// class B{
//     private:
//     int num2;
//     public:
//     B():num2(20){}
//     void display(){
//         cout<<"value of class B="<<num2<<endl;
//     }
//  friend void swap(class A,class B);   
// };
// void swap(A x,B y){
//     int n;
//    n=y.num2;
//     y.num2=x.num;
//     x.num=n;
// x.display();
// y.display();

// }
// int main(){
//     A x;
//     B y;
//     cout<<"Values before Swap="<<endl;
//     x.display();
//     y.display();
//     cout<<"value after swap="<<endl;
//     swap(x,y);

//     return 0;
// }

//pointers ke sath arrow(->)operator use hota hai 
// and simple object ke sath dot operator  (.) use hota hai

//wap to swap private data members of two class using friend function without using pointer/reference

#include<iostream>
using namespace std;
class B;

class A{
    private:
    int num;
    public:
    A():num(10){}
    void display(){
        cout<<"value of class A="<<num<<endl;
    }
    friend void swap(class A*,class B*);
};
class B{
    private:
    int num2;
    public:
    B():num2(20){}
    void display(){
        cout<<"value of class B="<<num2<<endl;
    }
 friend void swap(class A*,class B*);   
};
void swap(A *x,B *y){
    //for pointer
    int n;
   n=y->num2;
    y->num2=x->num;
    x->num=n;
    //for simple object
    //  int n;
//    n=y.num2;
//     y.num2=x.num;
//     x.num=n;


}
int main(){
    A x;
    B y;
    cout<<"Values before Swap="<<endl;
    x.display();
    y.display();
    cout<<"value after swap="<<endl;
    swap(&x,&y);
x.display();
y.display();
    return 0;
}

//class ke baad and object se pehle * lagaya jaata hai

// WAP to create a class complex to represent complex numbers. The complex class should use a function to add two complex numbers which are passed as arguments. The function should return an object of type complex representing the sum of two complex numbers.

#include<iostream>
using namespace std;
class complex{
    float real,img;
    public:
    void set(float r,float i){
       real=r;
       img=i;
       
    } 

    //using constructor
    // complex()
    // {
        
    // }
    // complex(float r,float i){
    //     real=r;
    //     img=i;
    // }
   complex add(complex c) {
      complex temp;
      temp.real = real + c.real;
      temp.img = img+ c.img;
      return temp;
    }

    void display(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
};
int main(){
//using constructor
//     complex c1(2.6,3.6);
//     complex c2(3.6,2.6);
//   complex  c3=c1.add(c2);
// cout<<"Complex No1"<<endl;
//      c1.display();
//      cout<<"complex no2"<<endl;
//      c2.display();
//      cout<<"complex no3"<<endl;
//      c3.display();

//using member fxn
complex c1,c2,c3;
c1.set(2.0,3.0);
cout<<"Complex No1"<<endl;
c1.display();

c2.set(3.0,2.0);
cout<<"complex no2"<<endl;
c2.display();

cout<<"Complex Number After Addition"<<endl;
c3=c1.add(c2);

c3.display();
    
     
     


return 0;
}