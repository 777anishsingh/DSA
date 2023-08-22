#include <bits/stdc++.h>
using namespace std;
//************************************ MultiLevel Inheritance **************************************

class car
{
public:
    string name;
    int weight;
    int age;

    void speedUp(){
        cout << "Speeding up" << endl;
    }

    void breakMaro(){
        cout << "Break Mardi" << endl;
    }
};

// 1. single level inheritance->ex: Scorpio ->[is a]-> car
class Scorpio : public car{

};
// 2. Multi Level Inheritance->ex: Alphonso ->[is a]-> Mango ->[is a]-> Fruit
class fruit{
    public:
        string name="meraFruit";

};

class mango:public fruit{
    public:
        int weight=69;
};

class alphonso:public mango{
    public:
        int sugarLevel=90; 
};

int main(){

    Scorpio butolaWali;
    butolaWali.speedUp();

    alphonso a;
    cout<<"This is "<<a.name<<endl
        <<"With weight "<<a.weight<<endl
        <<"With Sugar level "<<a.sugarLevel<<endl;

    return 0; 
}