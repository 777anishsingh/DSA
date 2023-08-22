#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ****************************************************************refernce varibale***************8*********************************************
    // int i = 5;
    // int &j = i;

    // cout << i << endl;
    // i++;
    // cout << j << endl;
    // j++;
    // cout << i << endl;

    // ****************************************************************dynamically created and inputed varibale***************8*********************************************
    // int *ptr = new int;
    // cin >> *ptr;
    // cout << "The value of ptr stored in heap -> " << *ptr << endl;

    // // ***************************************************************dynamic 1-D array**************************************************************
    // int n;
    // cout << "enter the value of n " << endl;
    // cin >> n;

    // int *arr = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // cout << "printing the array = " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    // delete[] arr;

    //***************************************************************dynamic 2-D array**************************************************************

    cout << "enter the size of row and col \n";
    int col, row;
    cin >> row >> col;

    // creation of 2d array of m*n
    int **arr = new int *[row]; // starting of every row is array of pointers
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    // input
    cout << "enter inputs of array " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // output
    cout << "The output array is " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // deletion of pointer array
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    // ********************************************************************** JACKED ARRAY ***********************************************************

    int x; // pattern of jacked array
    cout << "Enter the pattern of jacked array \n";
    cin >> x;

    cout << "enter the size of row and col \n";
    int col, row;
    cin >> row >> col;

    // creation of 2d array of m*n
    int **arr = new int *[row]; // starting of every row is array of pointers
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[sizeof(i)];
    }

    // input
    cout << "enter inputs of array " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // output
    cout << "The output array is " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // deletion of pointer array
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}