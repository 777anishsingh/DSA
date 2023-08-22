#include <bits/stdc++.h>
using namespace std;

class animal
{
private:
    // perfect encapsulation
    int age;
    int weight;

public:
    void eat()
    {
        cout << "Eating" << endl;
    }

    int getage() //getter
    {
        return age;
    }
    void setage(int age) //setter
    {
        this->age = age;
        cout << "Age of Ramesh is - " << age;
    }
};

int main()
{

    animal *ramesh = new animal;
    ramesh->setage(69);

    return 0;
}