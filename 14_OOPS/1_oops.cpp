#include <bits/stdc++.h>
using namespace std;

class animal
{
private:
    int weight;

public:
    // state or properties
    int age;
    string name;

    // behaviour or methods
    void eat()
    {
        cout << "eating" << endl;
    }

    void sleep()
    {
        cout << "sleeping" << endl;
    }

    // getters & setters
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

    animal *suresh = new animal;

    // (*suresh).age=15;
    // (*suresh).name="billi";
    // or we use

    suresh->age = 17;
    suresh->name = "billi";

    suresh->eat();
    suresh->sleep();

    return 0;
}
