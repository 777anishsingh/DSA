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

// Q2 combination in a string of digits
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

// Q3 find all even binary equence with same sum of first & second half bits

void findCount(int leftSum, int rightSum, char *arr, int i, int j, int &count)
{
    if (i > j)
    {
        if (leftSum == rightSum)
        {
            cout << "value " << count++ << " ==> " << arr << endl;
        }
        return;
    }

    // 0,0
    arr[i] = '0';
    arr[j] = '0';
    findCount(leftSum, rightSum, arr, i + 1, j - 1, count);

    // 0,1
    arr[i] = '1';
    arr[j] = '0';
    findCount(leftSum + 1, rightSum, arr, i + 1, j - 1, count);

    // 1,0
    arr[i] = '0';
    arr[j] = '1';
    findCount(leftSum, rightSum + 1, arr, i + 1, j - 1, count);

    // 1,1
    arr[i] = '1';
    arr[j] = '1';
    findCount(leftSum + 1, rightSum + 1, arr, i + 1, j - 1, count);
}
void compute_value(int n)
{
    char *arr = new char[2 * n];
    int count = 1;
    return findCount(0, 0, arr, 0, 2 * n - 1, count);
}

int main()
{
    // Q1
    //  string str;
    //  cout << "Enter the String " << endl;
    //  cin >> str;
    //  string output = "";
    // printPowerSet(str, 0, output);

    // Q2
    // string str;
    // cout << "Enter the Number String " << endl;
    // cin >> str;
    // string output = "";
    // findCombination(str, 0, output);

    // Q3

    int n;
    cin >> n;
    compute_value(n);

    return 0;
}