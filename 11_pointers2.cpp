#include <bits/stdc++.h>
using namespace std;

void fun1(int **q)
{
    q = q + 1;
}

void fun2(int **q)
{
    *q = *q + 1;
}

void fun3(int **q)
{
    **q = **q + 1;
}

void sqaure(int *p)
{
    int a = 10;
    p = &a; //=> reinitilized the value of p again with above adress
    *p = (*p) * (*p);
}

int f(int x, int *y, int **z)
{
    int p, q;
    **z += 1;
    q = **z;
    *y += 2;
    p = *y;
    x += 3;
    return x + p + q;
}

void inc(int **p)
{
    (**p)++;
}

int main()
{
    // int a = 5;
    // int *p = &a;
    // int **q = &p;

    // // outputs
    // cout << &a << endl; // adress of a
    // cout << a << endl;  // value of p
    // // cout<<*a<<endl; //error

    // cout << endl;

    // cout << &p << endl; // adress of pointer p
    // cout << p << endl;  // adress of a
    // cout << *p << endl; // value of a

    // cout << endl;

    // cout << &q << endl;  // adress of q
    // cout << q << endl;   // value at p
    // cout << *q << endl;  // value at p i.e. adress of a
    // cout << **q << endl; // value at a

    // cout<<endl<<endl<<endl;

    // cout << "before " << endl
    //      << q << endl
    //      << *q << endl
    //      << **q << endl;
    // fun1(q);
    // cout << "after " << endl
    //      << q << endl
    //      << *q << endl
    //      << **q << endl;
    // fun2(q);
    // cout << "after " << endl
    //      << q << endl
    //      << *q << endl
    //      << **q << endl;
    // fun3(q);
    // cout << "after " << endl
    //      << q << endl
    //      << *q << endl
    //      << **q << endl;

    // // Q1
    // float f = 10.5;
    // float p = 2.5;
    // float *ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout << *ptr << " " << f << " " << p;

    // // Q2
    // int a = 7;
    // int b = 17;
    // int *c = &b;
    // *c = 7;
    // cout << a << " " << b << endl;

    // // Q3
    // int *ptr = 0;
    // int a = 10;
    // *ptr = a;
    // cout << *ptr << endl; // Gives error as it pointd to a non existent value

    // // Q4
    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;
    // cout << *ptr;

    // // Q5
    // int a = 7;
    // int *c = &a;
    // c = c + 1;

    // cout << a << endl
    //      << *c << endl; //=> gives garbage value as we dont know whats there at this memory location

    // // Q6
    // int a = 7;
    // int *c = &a;
    // cout << c << endl;
    // c = c + 3;
    // cout << c;

    // // Q7
    // double a = 10.54;
    // double *d = &a;
    // cout << d << endl;
    // d = d + 1;
    // cout << d;

    // // Q8
    // int a[5];
    // int *c;
    // cout << sizeof(a) << endl
    //      << sizeof(c);

    // // Q9
    // int a[] = {1, 2, 3, 4};
    // cout << *a << endl
    //      << *(a + 1);

    // // Q10
    // int arr[] = {1, 2, 3, 4};
    // int *p = arr++; //=> arr++ means arr=arr+1 i.e we update value of arr which gives error
    // cout << *p;

    // Q11
    // int arr[] = {4, 5, 6, 7};
    // int *p = (arr + 1); //=>here we are just point to to adress of arr + 1 i.e. adress of 5 and not updating it therefore no error
    // cout << *arr + 9;

    /****************************************************************character array questions***************************************************************/

    // Q12
    // char b[] = "xyz";
    // char *c = &b[0];
    // cout << c << endl  //=> prints entire string
    //      << &c << endl //=> prints adress of c
    //      << *c;        //=>prints value at adress b

    // // Q13
    // char s[] = "hello";
    // char *p = s;
    // cout << s << endl
    //      << s[0] << endl
    //      << p[0] << endl;

    // // Q14
    // int a = 10;
    // sqaure(&a);
    // cout << a << endl; //=> this will give 10 becaue it has the value of only main fn not the sqaure function

    /******************************************************************Double Pointers Questions*****************************************************************/
    // int c, *b, **a;
    // c = 4;
    // b = &c;
    // a = &b;
    // cout << f(c, b, a);

    // // Q15
    // int ***r, **q, *p, i = 8;
    // p = &i;
    // (*p)++;
    // q = &p;
    // (**q)++;
    // r = &q;
    // cout << *p << " " << **q << " " << ***r << endl;

    // Q16
    int num = 10;
    int *ptr = &num;
    inc(&ptr);
    cout << num << endl;

    return 0;
}