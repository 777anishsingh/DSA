#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

/*//taking input
int main(){
    string str;
    getline(cin,str); //for taking i/p of more than 1 word
    cout<<"the string is = "<<str;
    return 0;
}*/

/*// Check wheather anagram
int checkAnagram(string str1, string str2)
{

    // WORKS LIKE ALPHABET FROM A TO Z
    int freq[26] = {0};

    // for increment in freq
    for (int i = 0; i < str1.length(); i++)
    {
        char ch = str1[i];
        // ch-'a' gives maping of integer with characters
        freq[ch - 'a']++; // for incriment
    }
    // for decrement in freq
    for (int i = 0; i < str2.length(); i++)
    {
        char ch = str2[i];
        // ch-'a' gives maping of integer with characters
        freq[ch - 'a']--; // for decrement
    }
    bool flag = true;

    // for checking the counts of characters
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}
//new approach
int checkAnagram(string str1, string str2)
{

    map<char, int> m;

    for (int i = 0; i < str1.length(); i++)
    {
        char ch = str1[i];
        m[ch]++;
    }

    for (int i = 0; i < str2.length(); i++)
    {
        char ch = str2[i];
        m[ch]--;
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        if (m[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string str1;
    cout << "Enter the string 1 - ";
    getline(cin, str1);
    string str2;
    cout << "Enter the string 2 - ";
    getline(cin, str2);
    if (checkAnagram(str1, str2))
        cout << "The strings are an Anagram\n";
    else
        cout << "The string is not an anagram\n";
}
*/
/*
//Minimum Number of Flips to Make the Binary String Alternating
char flip(char expected){
    if(expected=='0')
    return '1';
    else
    return'0';
}
int bitflipper(string s,char bit){
    int cntFlip=0;
    for (int i=0;i<s.length();i++){
        if(s[i]!=bit)
            cntFlip++;

    bit=flip(bit);

    } return cntFlip;
}
    int minFlips(string s) {
        int ans0=bitflipper(s,'0');
        int ans1=bitflipper(s,'1');
        return min(ans0,ans1);
    }

int main(){
    string str1;
    cout << "Enter the string -  ";
    getline(cin, str1);
    cout<<"Min no of flips are - "<<minFlips(str1);
    return 0;
}
*/
/*/ check if plaindrom
bool checkPalindrome(string s)
{
    int st = 0;
    int e = s.length() - 1;

    while (st <= e)
    {
        if (s[st] != s[e])
        {
            return 0;
        }
        else
        {
            st++;
            e--;
        }
    }
    return 1;
}
int main()
{
    string s;
    cout << "Enter The String\n";
    getline(cin, s);
    if (checkPalindrome(s))
    {
        cout << "palindrom found\n";
    }
    else
    {
        cout << "palindrom not found\n";
    }
}
*/
/*// check an array is roated or not
//******npos =no match***********
//https://en.cppreference.com/w/cpp/string/basic_string/npos

bool lengthstr(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    return true;
}
bool rotated(string str1, string str2)
{
    string temp = str1 + str1;
    if (temp.find(str2) == std::string::npos)
    {
        return false;
    }
    else
        return true;
}

int main()
{
    string str1;
    getline(cin, str1);
    string str2;
    getline(cin, str2);
    if (rotated(str1, str2) && lengthstr(str1,str2))
    {
        cout << "is roatated";
    }
    else
    {
        cout << "Not roatated";
    }
}
*/

