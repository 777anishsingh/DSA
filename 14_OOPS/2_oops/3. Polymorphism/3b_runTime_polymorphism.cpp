#include<bits/stdc++.h>
using namespace std;

//*************************************************** Run-Time Polymorphism **********************************************

//1. Fn overiding
class animal{
public:
    virtual void speak(){
        cout<<"speaking\n";
    }
};


//overiding -> expilicitly changing the speak fn
class dog:public animal{
public:
    void speak(){
        cout<<"Barking\n";
    }
};

int main(){

    // dog d1;
    // d1.speak();

    // animal* a=new animal();
    // a->speak();

    // dog* d=new dog(); 
    // d->speak();

//*************************Up-casting****************
    animal* a =new dog();
    a->speak();

//*************************Down-casting****************
    dog* b =(dog*)new animal(); //forcibally downcasting
    //dog* b =new animal(); //gives error

    a->speak();

    return 0;
}  