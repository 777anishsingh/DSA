#include <bits/stdc++.h>
using namespace std;

int main()
{

    // creation
    unordered_map<string, int> mapping;

    // insertion
    pair<string, int> p = make_pair("love", 1);
    pair<string, int> q("Shubham", 25);
    pair<string, int> r = {"Anish", 7};

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["babbar"] = 51;

    // Access
    cout << "size of " << mapping.size() << endl;
    cout << mapping.at("Anish") << endl;
    cout << mapping["Anish"] << endl;

    // Searching
    cout << mapping.count("Anish") << endl; // Returns 1 if element present

    if (mapping.find("Babbar") != mapping.end()) // agr end tk pohohc gya to not found and nhi pohocha to found
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    cout << "Mapping Size before: " << mapping.size() << endl;
    // New methods
    cout << mapping["Kumar"] <<   endl; // [] inke bich ke agr entry present hogi to print ho jaegi nhi to create ho jaegi new entry
    cout << "Mapping Size after: " << mapping.size() << endl;

    return 0;
}