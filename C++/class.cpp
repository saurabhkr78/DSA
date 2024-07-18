//class that has three fields/data members: id ,salary and name. It creates instance of the class, initializes the object and prints the object value.


// #include<iostream>
// using namespace std;
// class student
// {
//   public:
//   string name;
//   int uid;
//   float salary;
// };

// int main()
// {
//   student s;
//   s.name="saurabh";
//   s.uid=2211917;
//   s.salary=120000;
//   cout<<"Name="<<s.name<<endl;
//   cout<<"UID="<<s.uid<<endl;
//   cout<<"Salary="<<s.salary<<endl;

//     return 0;
// }


//initializing and displaying object through method.

#include<iostream>
using namespace std;
class student
{
  public:
  string name;
  int uid;
  float salary;
  void get(int i,string n,float s){
    uid=i;
    name=n;
    salary=s;
  }
  void display(){
    cout<<"name="<<name<<endl<<"UID="<<uid<<endl<<"Salary"<<salary<<endl;
  }
};

int main()
{
  student s;
  student s1;
 s.get(2211917,"Saurabh",120000);
 s1.get(2214667,"shanu",120000);
 s.display();
 s1.display();

    return 0;
}