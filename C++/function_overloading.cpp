/*If any class have multiple functions with same names but different parameters then they are said to be overloaded.
 Function overloading allows you to use the same name for different functions, to perform, either same or different functions in the same class.

Function overloading is usually used to enhance the readability of the program. If you have to perform one single operation but with different number or types of arguments, then you can simply overload the function.*/

/*Different ways to Overload a Function
By changing number of Arguments.
By having different types of argument.
*/

// Different Number of Arguments
/*In this type of function overloading we define two functions with same names but different number of parameters of the same type. For example, in the below mentioned program we have made two sum() functions to return sum of two and three integers.*/

// #include<iostream>
// using namespace std;
// class student
// {
//   public:
//  int add(int a)
//  {
//   return a;
//  }
//   int add(int a,int b){
//     return a+b;

//   }
//    int add(int a,int b,int c){
//     return a+b+c;

//   }
// };
// int main()
// {
//   student s;
  // cout<<s(1)<<endl;
//   cout<<s.add(1,2)<<endl;
//   cout<<s.add(1,2,3);
//     return 0;
// }

// using namespace std;
// class student
// {
//   public:
//   void add(int a,int b){
    
//     cout<<"a+b="<<(a+b)<<endl;

//   }
//   void add(int a,int b,int c){
//     cout<<"a+b+c="<<(a+b+c);
  
//   }
// };
// int main()
// {
//   student s;
//   s.add(1,2);
//   s.add(1,2,3);
//     return 0;
// }


//here sum fxn is overloaded as it has two definition one of them is having two args and another one is having three arguments which fxn will be called is depends on number of args



//Different Datatype of Arguments
/*In this type of overloading we define two or more functions with same name and same number of parameters, but the type of parameter is different. For example in this program, we have two sum() function, first one gets two integer arguments and second one gets two double arguments.*/
// #include<iostream>
// using namespace std;
// class student
// {
//   public:
//   void sum(int a, int b)
// {
//     cout<< a+b;
// }


// void sum(double a, double b)
// {
//     cout << a+b;
// }
// };

// int main()
// {
//   student s;

//    s.sum (10,20);
//     s.sum(10.5,20.5);
//     return 0;
// }


#include<iostream>
using namespace std;
 class A{
  public:
  int sum(int a)
  {
   return a;
  }
  int sum(int a,int b){
    return a+b;

  }
  double sum(double a,double b){
    return a+b;
  }
 };
 int main(){
    A a;
    cout<<a.sum(10)<<endl;
    cout<<a.sum(10,20)<<endl;
    cout<<a.sum(10.10,20.20)<<endl;

  return 0;

 }

// The fun(int a, int b=7) can be called in two ways: first is by calling the function with one argument, i.e., fun(10) and another way is calling the function with two arguments, i.e., fun(10,20).

//pass by reference






/*benefits of function overloading in C++.

1) The programmer can create functions with distinct purposes but the same name by using function overloading.

2) It speeds up the program's execution.

3) The code is clearer and simpler to comprehend.

4) It reduces memory utilization and makes programs reusable.*/


