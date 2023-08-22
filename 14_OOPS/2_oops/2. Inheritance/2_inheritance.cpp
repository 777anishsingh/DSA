#include <bits/stdc++.h>
using namespace std;

class animal
{
private:
    void sleep()
    {
        cout << "sleeping" << endl;
    }

public:
    int age = 69;
    int weight = 28;

    void eat()
    {
        cout << "eating" << endl;
    }
};

// syntax of inhertance
// child class: mode of inheritance parent class
class dog : protected animal
{
public:
    void print()
    {
        cout << this->age << endl;
    }
};

int main()
{
    dog d1;
    d1.print();

    return 0;
}