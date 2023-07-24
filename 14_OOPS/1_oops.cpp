#include <bits/stdc++.h>
using namespace std;

class animal
{
private:
    int weight;

public:
    // ******************************state or properties******************************
    int age;
    string name;

    // ******************************constructors********************************

    // 1.constructor
    animal()
    {
        this->weight = 0;
        this->age = 0;
        this->name = "";
        cout << "Construtor Called" << endl;
    }

    // 2.parameterised constructor
    animal(int age)
    {
        this->age = age;
        cout << "Parameterised constructor 1 called "
             << "Weight-> " << age << endl;
    }

    animal(int age, string name)
    {
        this->age = age;
        this->name = name;

        cout << "Parameterised constructor 2 called "
             << "Weight-> " << age << " Name->" << name << endl;
    }

    animal(int age, string name, int weight)
    {
        this->age = age;
        this->name = name;
        this->weight = weight;
        cout << "Parameterised constructor 3 called "
             << "Weight-> " << age << " Name->" << name << " Weight-> " << weight << endl;
    }

    // 3. Copy Constructor
    animal(animal &obj)
    {
        this->age = obj.age;
        this->name = obj.name;
        this->weight = obj.weight;
        cout << " Inside The Copy Constructor "
             << "Weight-> " << age << " Name->" << name << " Weight-> " << weight << endl;
    }

    // ****************************** Destructor ********************************

    // 1. Desctuctor
    ~animal()
    {
        cout << "Inside destructor" << endl;
    }

    // ******************************behaviour or methods******************************
    void eat()
    {
        cout << "eating" << endl;
    }

    void sleep()
    {
        cout << "sleeping" << endl;
    }

    // ******************************getters & setters******************************
    int getWeight()
    {
        return weight;
    }

    void setweight(int weight)
    {
        this->weight = weight;
    }
};

int main()
{
    // object

    // ************************static allocation**********************************
    /*
        // calling properties
        animal ramesh;
        ramesh.age = 12;
        ramesh.name = "Lion";
        cout << "The age of ramesh is " << ramesh.age << endl;
        cout << "The name of ramesh is " << ramesh.name << endl;

        // calling functions or behavior
        ramesh.eat();
        ramesh.sleep();

        // getters & setters for acces of private datamembers
        ramesh.setweight(101);
        cout << "Weight of ramesh is " << ramesh.getWeight() << endl;
    */

    // ************************dynamic allocation*****************************

    /*
    animal *suresh = new animal(1000);

    // (*suresh).age=15;
    // (*suresh).name="billi";

    // or we use

    suresh->age = 17;
    suresh->name = "billi";

    suresh->eat();
    suresh->sleep();
    */

    //******************************* constructors *********************************

    animal a(420);
    animal *b = new animal(1000);
    // animal *c = new animal(1004, "Oppenheimer");
    // animal *d = new animal(1008, "Oppenheimer", 48);

    // copy constructor
    animal x = a;
    animal y(x);

    // manually destructor called
    delete b;
    // delete c;
    // delete d;

    return 0;
}
