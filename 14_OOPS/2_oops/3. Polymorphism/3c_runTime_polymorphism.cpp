#include<bits/stdc++.h>
using namespace std;

// ***********************runtime polymorphism using constructors and destructors*******************************
class animal{
    public:
        animal(){
            cout<<"I am Inside Animal Constructor\n";
        }

        virtual void speak(){
            cout<<"Speaking\n";
        }
};

class dog:public animal{
    public:
    void speak(){
        cout<<"Barking\n";
    }
    dog(){
            cout<<"I am Inside dog Constructor\n";
        }
};

int main(){

    animal* a=new animal(); //single constructor called 
    dog* b=new dog(); //Both constructor called as it was inherited froma animal class
    dog* c=(dog*)new animal(); //[down casted]as animal was type casted to dog only same result as above

    return 0;
}