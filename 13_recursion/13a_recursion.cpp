#include <bits/stdc++.h>

using namespace std;

// Q1
int factorial(int num) // factorial of a number
{

    if (num == 1)
        return 1;

    int smallerProblemAns = factorial(num - 1);
    int biggerProblemAns = num * smallerProblemAns;

    return biggerProblemAns;

    // return num * factorial(num - 1);
}

// Q2
void countNo(int n) // counting the numbers
{
    // base condition
    if (n < 1)
        return;

    // rec. call
    countNo(n - 1);

    // Printing
    cout << n << " ";
}

// Q3
int maxNo(int arr[], int size) // max of an array
{

    if (size <= 1)
    {
        return arr[0];
    }

    return max(arr[size - 1], maxNo(arr, size - 1));
}

// Q4
int fastExp(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int prob = fastExp(n / 2);

    if (n & 1)
    {
        return prob * prob * 2;
    }
    else
    {
        return prob * prob;
    }
}

// Q5
int fiboSeries(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fiboSeries(n - 1) + fiboSeries(n - 2);
}

// Q6
int countDistinctWays(int n)
{

    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    return countDistinctWays(n - 1) + countDistinctWays(n - 2);
}

// Q7
void sayNo(int num)
{
    // string mapping
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // base condition
    if (num == 0)
        return;

    // processing
    int ans = num % 10;

    // recursive call
    sayNo(num / 10);

    // output
    cout << arr[ans] << " ";
}

// Q8
bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
        return isSorted(arr + 1, size - 1);
}

// Q9
int sumOfArr(int arr[], int size, int sum)
{
    if (size == 0)
        return 0;

    if (size == 1)
        return arr[0];

    sum = arr[0] + sumOfArr(arr + 1, size - 1, sum);

    return sum;
}

int main()
{

    // int n;
    // cout << "Enter the number " << endl;
    // cin >> n;

    // cout << "The factorial of " << n << " is => " << factorial(n) << endl;
    // countNo(n);

    // int arr[] = {4, 2, 6, 45, 1, 0, 12};
    // int size = 7;

    // cout << maxNo(arr, size);

    // cout << fastExp(n);

    // cout << fiboSeries(n);

    // cout << countDistinctWays(n);

    // sayNo(n);

    // int size;
    // cout << "Enter the size of array" << endl;
    // cin >> size;

    // int *arr = new int[size];
    // cout << "Enter the array elements" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> arr[i];
    // }

    // if (isSorted(arr, size))
    //     cout << "The array is Sorted" << endl;
    // else
    //     cout << "The array is unsorted" << endl;

    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;

    int sum = 0;

    int *arr = new int[size];
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "The sum of array is - " << sumOfArr(arr, size, sum) << endl;

    return 0;
}