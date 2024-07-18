#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream o;
    o.open("saurabh.txt");
    o<<"How ARE YOU";
    o.close();
    
    ifstream o2;
    char c;
    o2.open("saurabh.txt");
  while(!o2.eof()){
    o2.get(c);
  
    cout<<c;
  }

}

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream o;
    o.open("Saurabh.txt");
    o<<"hello World";
    o.close();


   ofstream o2;
   o2.open("new file.txt");
char c;

 ifstream o3;
 o3.open("Saurabh.txt");
 while(o3){
    o3.get(c);
    o2<<c;
 }
}


#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    private:
    char name[20];
    int age;
    public:
    void get()
    {
        cout<<"Enter name and age of student ";
        cin>>name;
        cin>>age;
    }
    void show()
    {
        cout<<endl<<name<<endl<<age;
    }
}o,r;
using namespace std;
int main()
{
  fstream obj;
	

	ofstream o2("Gurmehar.txt",ios::app);
	obj.open("Gurmehar.txt",ios::in|ios::out|ios::ate);
	for(int i=0;i<2;i++)
	{
	    o.get();
	    obj.write((char*)&o,sizeof(o));
	}
    obj.seekg(0,ios::beg);
    while(obj)	{
	    obj.read((char*)&r,sizeof(r));
	   	 r.show();
	
	}


}


//character count
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main()
{
ofstream o;
o.open("Uzaif.txt");
string A;

cout<<"Enter What You want to Enter In file"<<endl;
cin>>A;

o<<A;
o.close();


ifstream o2;
o2.open("Uzaif.txt");

int c=0;
char B;
while(o2)
{
	o2.get(B);
	if((B>='a'  && B<='z')||(B>='A'  && B<='Z'))
	c++;
}
cout<<"Count = "<<c;
o2.close();
}


//find word or character in file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string d,b;
    int count=0,countv=0;
    char c;
	ofstream o("Gurmehar.txt");
	
	o<<"Hello i am Gurmehardeep Singh my UID is 22BCS13666, I am from Amritsar and I am 19 years old";
	o<<"I like learning coding because its fun and my dream is to explore many different places";
	o<<"I am planning to go to australia after my BTECH so i can futher study";
	o<<"Currently I am in 2nd semester and improving my marks";
	o<<"My friend is going to leave the university after 1st year is over to go to Germany and do his studies there ";
	o<<"Studies in Germany are completely";
	o.close();
	
	cout<<"Write the word/character you wanna find"<<endl;
    cin>>d;
    
    ifstream a;
    a.open("Gurmehar.txt");
    while (getline(a,b))
    {
       
       if(b.find(d)!=string::npos)
       cout<<"Found";
    	
    	
	}


    return 0;
}