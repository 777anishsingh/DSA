#include <bits/stdc++.h>
using namespace std;

// void fn(int *p)
// {
//     p = p + 1; // call by value concept
//     cout << p << " " << *p << " 1" << endl;
// }

// void fn2(int *p)
// {
//     *p = *p + 1; // editing through the adress of p
//     cout << p << " " << *p << " 1" << endl;
// }

// void dummy(int *arr, int n)
// {
//     cout << sizeof(arr) << endl   // size of adress of array
//          << sizeof(*arr) << endl  // size of array
//          << sizeof(&arr) << endl; // size of adress of array
// }
int main()
{
    // int a = 90;
    // int *p = &a;
    // fn(p);
    // fn2(p);
    // cout << p << " " << *p << " 2" << endl;

    // int arr[4] = {12, 23, 34, 45};
    // // cout<<*(arr)<<endl<<*(arr+1)<<endl<<*(arr+2)<<endl<<*(arr+3);
    // dummy(arr, 4);

    // char ch[]="abb";
    // char * p= &ch;
    // cout<<*p<<endl<<&p<<endl<<p<<endl<<ch;

    // char chr = 'B';
    // char *ctr = &chr;
    // cout << ctr << endl
    //      << *ctr << endl;
    
/****************************************************************************/
    int arr[] = {1, 2, 3, 4};
    cout << arr << endl;
    cout << arr + 1 << endl; //=> 4 bytes se aage

    cout << &arr << endl;     //=> pointing to whole array
    cout << &arr + 1 << endl; //=> pure array ke aage bdh jate hia ex yaha 16 bytes aage bdh jayege
/****************************************************************************/

    // // Q1
    // int *p1;
    // cout << "Q1" << endl
    //      << p1 << endl;
    // cout << *p1 << endl;
    // cout << &p1 << endl;

    // // Q2
    // int *p2 = 0;
    // cout << "Q2" << endl
    //      << p1 << endl;
    // cout << *p1 << endl;
    // cout << &p1 << endl;

    // // Q3
    // if (cout << " '' " << endl)
    // {
    //     cout << "1" << endl;
    // }
    // else
    // {
    //     cout << "2" << endl;
    // }

    // Q4
    // char sentence[] = "my name is anish";
    // char *p = sentence;

    // cout << p << endl
    //      << *p << endl
    //      << &p << endl;

    return 0;
}