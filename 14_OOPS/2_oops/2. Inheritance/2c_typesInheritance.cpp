#include<bits/stdc++.h>
using namespace std;

//****************************************** Heridetry Inhertance *************************************

class Car{
    public:
        int age;
        int weight;
        string name;

        void speedUp(){
                cout<<"Speeding up"<<endl;
        }   
};

class Scorpio:public Car{
    
};

class Fortuner:public Car{
    
};

int main(){
    Scorpio S11;
    S11.speedUp();

    Fortuner legender;
    legender.speedUp();
    return 0;
}