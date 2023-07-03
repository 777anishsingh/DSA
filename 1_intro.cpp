#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{

    //     //     cout
    //     // << "Placement to lgni hi hai\n";

    //     // size and datatypes and data size
    //     int a = 5;
    //     cout << "value of a is = " << a << endl;

    //     bool b = 0;
    //     cout << "value of b is = " << b << endl;

    //     float c = 1.2;
    //     cout << "value of c is = " << c << endl;

    //     cout << "size of a is " << sizeof(a) << endl;
    //     cout << "size of b is " << sizeof(b) << endl;
    //     cout << "size of c is " << sizeof(c) << endl;

    //      char ch = 67;
    //     cout << "value of ch is  = " << ch << endl;
    // }
    //     cout << "size of ch is " << sizeof(ch) << endl;

    //     // type casting
    //     char d = 'a';
    //     int num = (int)d;

    //     cout << num << endl;
    //     // bitwise operator
    //     int ah = 5;
    //     int cj = 4;

    //     int ss = ah >> 2;
    //     cout << ss << endl;

    //     // condition
    //     int numb;
    //     cout << "enter the number\n";
    //     cin >> numb;
    //     if (numb > 0)
    //     {

    //         cout << "my name is anish\n";
    //     }
    //     if (numb == 5)
    //     {
    //         cout << "the number is 5\n";
    //     }
    //     else
    //     {
    //         cout << "the number was less than 0\n";
    //     }
    //     // loops
    //     // 1 while loop
    //     int bh = 18;
    //     while (bh > 11)
    //     {
    //         cout << "this is while loop\n";
    //         bh--;
    //     }
    //     // 2 for loop
    //     int jo = 7;
    //     for (int x = 0; x < jo; x++)
    //     {
    //         cout << "hello anish\n";
    //     }

    //     for (int i = 0; i <= 10; i++)
    //     {
    //         if ((3 * i) % 2 == 0)
    //         {
    //             continue;
    //         }
    //         cout << 3 * i << endl;
    //     }
    //     // incriment
    //     int v = 5;
    //     cout << v++ << endl;
    //     cout << v << endl;

    //     int s = 8;
    //     cout << ++s << endl;
    //     cout << s << endl;

    //     // (;;) loop

    //     int lon = 7;
    //     for (;;)
    //     {
    //         if (lon > 0)
    //         {
    //             cout << "tera BHAI\n";
    //         }
    //         else
    //         {
    //             break;
    //         }
    //         lon--;
    //     }
    //     cout << "KHTM HO GYA\n";

    //     // digit nikalna (individual)

    // int nom = 12343242;
    // int dig;
    // while (nom != 0)
    // {
    //     dig = nom % 10;
    //     cout << "DIGIT " << dig << endl;

    //     nom = nom / 10;
    // }
    //     cout<<"end\n";
    //      }

    // digit nikalna (reverse)

    // int num = 45698;
    // int reverse=0,rem,ans;
    // while (num != 0)
    // {
    //     rem = num % 10;
    //     if(num<INT_MIN/10 || num>INT_MAX/10){
    //         return false;
    //         }
    //         else{
    //     reverse=reverse*10+rem;
    //     num = num / 10;
    //     }
    // }
    //     cout <<reverse<< endl;
    //     }

    //  decimal to binary

//      int n,store,ans=0,i=0;
//      cin>>n;
//  while(n!=0){
//      store=n%2;
//      ans=(store*pow(10,i)+ans); //same logic as below
//      n=n/2;
//      i++;
//  }cout<<ans;

 //OR


 //}

    // int dec = 7;
    // int bit, i = 0, ans = 0;
    // while (dec != 0)
    // {

    //     bit = dec & 1;
    //     cout << "bit " << bit << endl;
    //     dec = dec >> 1;
    //     ans = (bit * pow(10, i) + ans); same logic as above
    //     i++;
    // }
    // cout << "ans = " << ans << endl;}

    //     // prime
    //     int n;
    //     cin >> n;
    // bool isPrime = true;

    //     for (int i = 2; i < n; i++)
    //         {
    //         if (n % i == 0)
    //         {
    //             cout << "non prime";
    //             isPrime = false;
    //             break;
    //         }
    //     }
    //     if (isPrime == true)
    //     {

    //         cout << "prime";
    //     }

    //     return 0;
    // }

    // BINARY TO DECIMAL
    
//     int n = 1100, store, ans = 0, i = 0;
//     while (n != 0)
//     {
//         store = n % 10;
//         ans = (store * pow(2, i) + ans);
//         n = n / 10;
//         i++;
//     }
//     cout << ans;
// return 0;}