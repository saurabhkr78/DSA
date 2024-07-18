/*Acess Specifier:
1)Public:from any other class
2)private: can be accessed within the class only
3)protected: within the class and its subclasses

*/

//getter setter method to access private data member
//the getter functions return the data members, and the setter functions are used to ‘set’ or modify the data members.
#include<iostream>
using namespace std;
class student
{
  private:
  int uid;
  public:
  int get(){//getter/acessor fxn
    return this->uid;

  }void get2(){
    
  }

  void set(student *o){//setter/mutator fxn
    this->uid=o->uid;

  }
};
int main()
{
  student s;
  student s2;
  s.set(&s2);
  cout<<"the Value We set In private data member is="<<s.get();


    return 0;
}

//