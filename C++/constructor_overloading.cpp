//wap to calculate area of rectangle using constructor overloading
#include<iostream>
using namespace std;
class rectangle{
    private:
    int area,length,breadth;

    public:
    rectangle(){
        
    }
    rectangle(int l,int b){
        length=l;
        breadth=b;
    }
    void calc();
    void display();
    ~rectangle();

    

};
void rectangle::calc(){
     area=length*breadth;
}
void rectangle:: display(){
    cout<<"Area Of Rectangle="<<area<<endl;
}
rectangle::~rectangle(){
    cout<<"destructor Executed"<<endl;
}


int main(){
    int length,breadth;
    rectangle r;
    r.calc();
    r.display();
    cout<<"Enter Length"<<endl;
    cin>>length>>breadth;
    rectangle r2;
    r2.calc();
    r2.display();



    return 0;
}

/*
#include<iostream>
using namespace std;
class rectangle{
    int area,length,breadth;

    public:
    rectangle(){
        cout<<"Enter Length ";
        cin>>length;
        cout<<"Enter breadth ";
        cin>>breadth;
        
    }
    rectangle(rectangle &x){
        area=x.length*x.breadth;
    }
    void calc();
    void display();
    

};
void rectangle::calc(){
     area=length*breadth;
}
void rectangle:: display(){
    cout<<"Area Of Rectangle="<<area<<endl;
}
int main(){
    rectangle r;
    rectangle r2(r);
    r2.display();


    return 0;
}
*/