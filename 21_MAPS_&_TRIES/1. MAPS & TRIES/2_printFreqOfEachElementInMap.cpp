#include <bits/stdc++.h>
using namespace std;

void countCharacters(unordered_map<char, int> &mapping, string str)
{
    for (char ch : str)
    {
        mapping[ch]++;
    }
}

int main()
{

    string str;
    getline(cin,str);


    unordered_map<char, int> mapping;
    countCharacters(mapping, str);

    for (auto i : mapping)
    {
        cout << i.first << "->" << i.second << endl;
    }

    return 0;
}