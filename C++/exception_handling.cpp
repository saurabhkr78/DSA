// exceptions are run time error or unusual conditions that a program may encounter
//purpose of exception handling is to 1)find the problem 2)inform about error 3)receive why error occured 4)take action
// try-generates exceptions
//throw-when an exception detected it throws
//catch -catches the exceptions





//try block throwing an exception
#include<iostream>
// using namespace std;
// int main(){
//     int a,b;
//     cout<<"enter the value of a and b"<<endl;
//     cin>>a>>b;

//     int x=a-b;
//     try{
//         if(x>0){
//             cout<<a/x;

//         }
//         else
//         {//there is an exception
//         throw(x);
//         }
//     }


// catch(int i){
//     cout<<"Exception Caught:x="<<x<<endl;
// }
// return 0;
// }

//invoking fxn that generates exception

// #include<iostream>
// using namespace std;
// void divide(int x,int y,int z){
// if((x-y)>0){
//     int r=z/(x-y);
//     cout<<"result="<<r<<endl;
// }
// else {
//     throw(x-y);
// }
// }
// int main(){
//     try{
//         divide(10,20,30);
//         divide(20,30,40);
//     }
//     catch(int i){
//         cout<<"caught an exception\n";
//     }
//     return 0;
// }

//multiple catch statement


#include<iostream>
using namespace std;
void test(int x){
    try{
        if(x==1) throw x;
        else
        if (x==0) throw 'x';
        else 
        if(x==-1) throw 1.0;
    }
    // catch(int c){
    //     cout<<"caught a integer";
    //     }
    //     catch(char m ){
    //         cout<<"caught a character";
    //         }
    //         catch(double d)
    //         {
    //             cout<<"caught a double";
    //         }
    //     }
int main(){
test(1);
test(2);
test(0);
test(-1);
return 0;
}    

//catch all exceptions
#include<iostream>
using namespace std;
void test(int x){
    try{
        if(x==1) throw x;
        else
        if (x==0) throw 'x';
        else 
        if(x==-1) throw 1.0;
    }

    catch(...){
        
        cout<<"caught a exception";
       
        }
}
int main(){
test(1);
test(2);
test(0);
test(-1);
return 0;
}    
  

// rethrowing exception
  #include<iostream>
using namespace std;
void divide(int x,int y){
    try{
        if(y==0) throw y;
        else
        cout<<"DIvision="<<x/y<<endl;
    }
    catch(int){
        cout<<"caught integer inside the fxn"<<endl;
        throw;
    }
}
int main(){
    try{
        divide(20,10);
        divide(20,0);
    }
    catch(int){
        cout<<"caught int inside main";
    }
    return 0;
}


#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter 2 No.";
    cin>>a>>b;
   
    try
    {
    if(b==0)
        {
            throw 1;
        }
        else{
        cout<<a/b;
        }
    }
   
    catch(int)
    {
        do
        {
           
            cout<<"Enter Second Number Again";
            cin>>c;
           
        }
        while(c==0);
        cout<<a/c;
       
    }
}