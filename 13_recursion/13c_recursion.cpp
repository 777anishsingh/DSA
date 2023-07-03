#include <bits/stdc++.h>
using namespace std;

// INCLUSION AND EXCLUSION
// Q1 Power set of all subsets
void printPowerSet(string input, int index, string output)
{
    if (index == input.length())
    {
        cout << output << endl;
        return;
    }

    char ch = input[index];

    // exclude ch
    printPowerSet(input, index + 1, output);

    // include ch
    output.push_back(ch);
    printPowerSet(input, index + 1, output);
}

void findCombination(string input, int index, string output)
{
    if (index == input.length())
    {
        cout << output << endl;
        return;
    }

    char ch = input[index];
    // exclusion ==> No space
    output.push_back(ch);
    findCombination(input, index + 1, output);

    // Inclusion of space ==> Adding space
    output.push_back(' ');

    if (input[index + 1] != '\0')
    {
        findCombination(input, index + 1, output);
    }
}

// Q2 combination in a string of digits

int main()
{
    // Q1
    //  string str;
    //  cout << "Enter the String " << endl;
    //  cin >> str;
    //  string output = "";

    // printPowerSet(str, 0, output);

    // Q2
    string str;
    cout << "Enter the Number String " << endl;
    cin >> str;
    string output = "";

    findCombination(str, 0, output);
    return 0;
}