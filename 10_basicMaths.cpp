#include <bits/stdc++.h>
using namespace std;

/*
//  seive of Eratos  T.C= O[n*log(log n)] & S.C= O(n)
int soe(int n)
{
    int count = 0;

    // sare no ko initally prime maan liya
    vector<bool> prime(n + 1, true);

    // 0 and 1 ko no prime mark kr do
    prime[0] = prime[1] = false;

    // table wise non prime mark kr do
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            count++;
        // table wise vali game hai ye
        for (int j = 2 * i; j < n; j = j + i)
        {
            prime[j] = 0;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "enter the Number = ";
    cin >> n;
    cout << "No. of primes are = " << soe(n);

    return 0;
}
*/
// GCD or HCF using euclid's Algo
int gcd(int a, int b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    cout << "Enter the numbers whos GCD you wan to find - ";
    int a, b;
    cin >> a >> b;
    cout << "The GCD of The following numbers is - " << gcd(a, b);

    return 0;
}
