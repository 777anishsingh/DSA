#include <iostream>
using namespace std;
//square pattern
 int main()
{
    cout<<"hello world";
}

//     int n = 4;

//     for (int rows = 1; rows <= n; rows++)
//     {
//         for (int col = 1; col <= n; col++)
//         {
//             cout << "* ";
//         }
//         cout << "\n";
//     }
// }

// half pyramid

//     int
//     main()
// {

//     int n = 5;

//     for (int i = 1; i < +n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }
// inverted pyramid int main()
// {
//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = n; j >= i; j--)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }

// invert pyramid with spaces first int main()
// {

//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         // spaces
//         for (int j = 1; j <= n - i; j++) // n - i
//         {
//             cout << " ";
//         }
//         // star
//         for (int g = 1; g <= i; g++) // row
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }
// // pyramid with spaces

// int main()
// {

//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         // spaces
//         for (int j = 1; j <= i - 1; j++) // row - 1
//         {
//             cout << " ";
//         }
//         // star
//         for (int g = 1; g <= n - i + 1; g++) // n - row +1
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

// // pyramid

// int main()
// {

//     int n = 10;

//     for (int i = 1; i <= n; i++)
//     {

//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << " ";
//         }

//         for (int g = 1; g <= i; g++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }
// inverted pyramid int main()
// {

//     int n = 10;

//     for (int i = 1; i <= n; i++)
//     {

//         for (int j = 1; j <= i - 1; j++)
//         {
//             cout << " ";
//         }

//         for (int g = 1; g <= n - i; g++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }

// solid rhombus******************************************************************************
// int main()
// {

//     int n = 5;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int k = 1; k <= n - i; k++)
//         {
//             cout << " ";
//         }

//         for (int x = 1; x <= i; x++)
//         {
//             cout << "* ";
//         }
//         for(i=n;i>0;i--){
//              for (int j = 1 ; j <= i - 1; j++)
//         {
//             cout << " ";
//         }

//         for (int g = 1; g <= n - i +1; g++)
//         {
//             cout << "* ";
//         }
//         }

//         cout << endl;
//     }
// }*************************************************************

// hollow inverted triangle

// int main()
// {

//     int n = 17;
//     for (int i = 1; i <= n; i++)
//     {

//         if (i == 1 || i == n)
//         {
//             for (int k = 1; k <= n - i + 1; k++)
//                 cout << "* ";
//         }
//         else
//         {
//             cout << "* ";
//             for (int j = 1; j <= n - i - 1; j++)
//             {
//                 cout << "  ";
//             }
//             cout << " *";
//         }
//         cout << endl;
//     }
// }

// // Hollow pyramid

// int main()
// {

//     int n = 6;
//     for (int i = 1; i <= n; i++)
//     {

//         if (i == n)
//         {
//             for (int b = 1; b <= i; b++)
//             {
//                 cout << "* ";
//             }
//         }
//         else
//         {

//             for (int j = 1; j <= n - i; j++)
//             {
//                 cout << " ";
//             }
//             cout << "*";

//             for (int m = 3; m <= i; m++)
//             {
//                 cout << "  ";
//             }
//             if (i == 1)
//             {
//                 cout << " ";
//             }
//             else
//             {
//                 cout << " *";
//             }
//         }

//         cout << endl;
//     }
// }

// //Hollow half pyramid

//     int
//     main()
// {
//     int n = 5;

//     for (int i = 1; i < n; i++)
//     {
//         if (i == 1 || i == n)
//         {
//             for (int c = 1; c <= i; c++)
//             {
//                 cout << c;
//             }
//         }

//         cout << endl;
//     }
// }
/* pascal triangle
int factorial(int row)
{
    int ans = 1;
    for (int i = 1; i <= row; i++)
    {
        ans = ans * i;
    }
    return ans;
}

int nCr(int row, int coln)
{
    int val1 = factorial(row);
    int val2 = factorial(row - coln);
    int val3 = factorial(coln);

    int ans = (val1) / (val2 * val3);
    return ans;
}

int main()
{
    long long int row;
    cin >> row;
    int x = factorial(row);
    int val;
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            val = nCr(i, j);
            cout << val << " ";
        }
        cout << endl;
    }
}
*/

//butterfly
