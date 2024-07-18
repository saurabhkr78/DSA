//constructor is a special method which is invoked during object creation
// it is used to initialize data members to new object
// default constructor is invoked when a object is created
// two constructors are there 1)default and 2)parametrized
//The C++ compiler creates a default constructor for the object if a constructor is not specified (expects any parameters and has an empty body).
// constructor cannot be declared virtual
//one cannot inherit a constructor
//constructor address cannot taken into reference


/*
#include<iostream>
using namespace std;
class student
{
  public:
  student(){
    cout<<"Constructor Invoked"<<endl;
  }
};
int main()
{
  student s;

    return 0;
}

parametrized constructor

#include<iostream>
using namespace std;
class student{
  private:
  string name;
  int uid;
  int salary;

  public:
  student(string n,int u,double s){
   name=n;
   uid=u;
   salary=s;

  }
  void display(){
    cout<<"Name="<<name<<endl<<"UID="<<uid<<endl<<"Salary="<<salary<<endl;
  }

};
int main(){
student s=student("Saurabh",2211917,240000);
student s1=student("Deeksha",2214862,240000);
s.display();
s1.display();
  return 0;
}*/

//define class constructor outside the class
#include<iostream>
using namespace std;
class student{
  private:
  string name;
  int uid;
  int salary;

  public:
  student(string,int,double);
  void display();

};
student::student(string n,int u,double s){
   name=n;
   uid=u;
   salary=s;

  }
  void student::display(){
    cout<<"Name="<<name<<endl<<"UID="<<uid<<endl<<"Salary="<<salary<<endl;
  }
int main(){
student s=student("Saurabh",2211917,240000);
student s1=student("Deeksha",2214862,240000);
s.display();
s1.display();
  return 0;
}


//destructor
//~(tilde)
//cannot be overloaded
//no argument is accepted
//  no return type
//it free up the memory used by object which is created by constructor
//defining destructor outside the class 
//classname::~constructor name(){};
/*
#include<iostream>
using namespace std;
class student{
  private:
  string name;
  int uid;
  int salary;

  public:
  student(string n,int u,double s){
   name=n;
   uid=u;
   salary=s;

  }
  void display(){
    cout<<"Name="<<name<<endl<<"UID="<<uid<<endl<<"Salary="<<salary<<endl;
  }
  ~student(){
    cout<<"Destructor invoked"<<endl;
  }

};
int main(){
student s=student("Saurabh",2211917,240000);
student s1=student("Deeksha",2214862,240000);
s.display();
s1.display();
  return 0;
}


*/