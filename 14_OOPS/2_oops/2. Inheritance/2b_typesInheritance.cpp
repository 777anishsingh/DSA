#include<bits/stdc++.h>
using namespace std;
//************************************** Multiple Inheritance ***************************************
/*
class A{
    public:
        int physics;
};

class B{
    public:
        int chemistry;
};

class C:public A,public B{
    public:
        int maths;
};

int main(){

    C obj;
    cout<<obj.physics<<endl<<obj.chemistry<<endl<<obj.maths<<endl;

    return 0;
}

*/

//*********************************** IMP:-> Diamond Problem ? must try******************************************
//Ans-> We use scope Resolution operator [ :: ] for this
class A{
    public:
        int Land;

    A(){
        Land=6969;
    }
};

class B{
    public:
        int Mountain;
        int Land;

    B(){
        Land=1001;
    }
};

class C:public A,public B{
    public:
        int Earth;
};

int main(){

    C obj;
    cout<<"Scope of A "<<obj.A::Land<<endl<<"Scope of B "<<obj.B::Land<<endl;

    return 0;
} 