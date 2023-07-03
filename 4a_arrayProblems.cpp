#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
#define MAX 500


/*void printArr(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " \n";
    }
}

// void util(int arr[],int size){
//      arr[0]=23;
//     cout<<"util arr\n";
//     printArr(arr,3);
// }

// int main(){
//     //creation
//    int  arr[]={88,34,4};
//     // int arr2[]={99,32,4,3,23};
//     // int arr3[10]={69,96};

// //     printArr(arr,5);
// // cout<< sizeof(arr[5])
// util(arr,3);
// cout<<"printing arr from main function\n";
// printArr(arr,3);

//     //access

// return 0;
// }

// linear search

bool search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return true;
    }
    return false;
}

int main()
{
    int arr[100];
    int n;
    cout << "enter the size of array\n";
    cin >> n;
    // taking input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "printing the no of arr\n";
    printArr(arr, n);

    if (search(arr, n, 18))
    {
        cout << "element found\n";
    }
    else
    {
        cout << "element not found\n";
    }
}*/


/*// reverse an array
void reverseArr(int arr[], int n)
{
    int i = 0; // LOGIC
    int j = n - 1;

    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    int arr[] = {2, 43, 5, 4, 3, 33, 69};

    reverseArr(arr, 7);

    // printing the array
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
        // cout<<endl;
    }
}*/

// Maximum of a number
/*
#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i]);
    }
    return ans;
}

int main()
{

    int arr[] = {1, 23, 41, 69, 43, 22, 4};
    cout << "The Max no is\n"<< getMax(arr, 7);
}*/

// Minimum of a number
/*
#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, arr[i]);
    }
    return ans;
}

int main()
{

    int arr[] = {1, 23, 41, 69, 43, 22, 4};
    cout << "The Max no is\n"<< getMax(arr, 7);
} */
// swaping alternative elemts in array
/*
#include<iostream>
using namespace std;



void swapAltArr(int arr[],int n){
    int i = 0;

    while(i<n){
        if(i+1<n)
        swap(arr[i],arr[i+1]);
        i+=2;

    }
}

int main(){
    int arr[]= {12,44,1,33,2,21,69};

    swapAltArr(arr,7);

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}
    */

// sorting an array of 0s, 1s, 2s

/*#include <iostream>
using namespace std;

void sortZeroOneTwo(int arr[], int n)
{
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        else if (arr[i] == 1)
        {
            one++;
        }
        else if (arr[i] == 2)
        {
            two++;
        }
    }

    int i = 0;
    while (zero--)
    {
        arr[i] = 0;
        i++;
    }
    while (one--)
    {
        arr[i] = 1;
        i++;
    }
    while (two--)
    {
        arr[i] = 2;
        i++;
    }

}

int main()
{
    int arr[] = {1, 0, 0, 2, 1, 2, 1, 1};

    sortZeroOneTwo(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}
*/

// check its a palindrom
/*
bool checkPalindrom(int arr[], int num)
{
    int i = 0;
    int j = num - 1;
    while (i < j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {1, 1, 3, 4, 4, 2, 1, 1};
    checkPalindrom(arr, 8);
    cout << checkPalindrom(arr, 8);
}
*/

// Union of a sorted array
/*
void checkUnion(int arr1[], int arr2[], int num1, int num2)
{
    int i = 0, j = 0;
    while (i < num1 && j < num2)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    while (i < num1)
    {
        cout << arr1[i] << " ";
        i++;
    }
    while (j < num2)
    {
        cout << arr2[j] << " ";
        j++;
    }
}

int main()
{
    int arr1[] = {2, 3, 5, 7, 9};
    int arr2[] = {3, 4, 5, 6, 7};
    checkUnion(arr1, arr2, 5, 5);
}
*/

// checkIntersection for sorted array
/*
void checkIntersection(int arr1[], int arr2[], int num1, int num2)
{
    int i = 0, j = 0;
    while (i < num1 && j < num2)
    {
        if (arr1[i] < arr2[j])
        {

            i++;
        }
        else if (arr1[i] > arr2[j])
        {

            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int arr1[] = {2, 3, 5, 7, 9};
    int arr2[] = {3, 4, 5, 6, 7};
    checkIntersection(arr1, arr2, 5, 5);
}
*/
// keep negative at one corner in array
/*
void checkNegative(int arr[], int num)
{
    int i = 0, j = 0;
    for (i = 0; i < num; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, -3, 5, -4, -3, -4, 5};
    checkNegative(arr, 7);

    return 0;
}
*/

// Find the Duplicate Number (n+1 integrs)

/*
int checkExtra(int arr[], int num)
{
    int sum1 = 0;
    for (int i = 0; i < num; i++)
    {
        sum1 += arr[i];
    }
    int sum2 = ((num - 1) * ((num - 1) + 1)) / 2;

    int ans = sum1 - sum2;

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5,6,7,8,9,9,10,11,12};
    checkExtra(arr, 13);

    cout << checkExtra(arr, 13) << " ";

    return 0;
}
*/

// pair of number whos sum is number given
/*

int main()
{
    int arr[] = {3, 1, 4, 5, 9, 13, 11};

    sort(arr, arr + 7);
    int target = 14;
    int count = 0;
    int i = 1, j = 6;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            count++;
            cout << "No of Pair found = " << count << " => (" << arr[i] << ", " << arr[j] << ")\n";

            break;
        }

        if (arr[i] + arr[j] > target)
            j--;

        if (arr[i] + arr[j] < target)
            i++;
    }
}
*/
// triplet of number whos sum is number given
/*
void triplet(int arr[], int target, int num)
{
    sort(arr, arr + num);

    for (int k = 0; k < 5; k++)
    {
        int start = k + 1;
        int end = num - 1;

        while (start < end)
        {
            if (arr[k] + arr[start] + arr[end] == target)
            {
                cout << "(" << arr[start] << "," << arr[k] << "," << arr[end] << ")";
                break;
            }
            if (arr[k] + arr[start] + arr[end] > target)
                end--;
            if (arr[k] + arr[start] + arr[end] < target)
                start++;

        }
    }
}

int main()
{
    int arr[] = {1, 6, 33, 4, 2, 9};
    int target = 12;
    triplet(arr, target, 6);
    return 0;
}
*/
/*
// Factorial of a large number
// if segmentation problem occurs incerase arr[MAX] in global scope
int multiply(int n, int arr[], int size)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int ans = arr[i] * n + carry;
        arr[i] = ans % 10;
        carry = ans / 10;
    }
    while (carry)
    {
        arr[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}
void facto(int num)
{
    int arr[MAX];
    int size = 1;
    arr[0] = 1;
    for (int i = 2; i <= num; i++)
        size = multiply(i, arr, size);

    for (int i = size - 1; i >= 0; i--)
        cout << arr[i] << " ";
}
int main()
{
    facto(5);
    return 0;
}
*/
// minimun swap required to sort array less than k
// This is a type of slidimg window question
int minSwap(int arr[], int size, int k)
{
    // finding the no of elemts greater than k
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= k)
            count++; // jitne elements k se chote hai unhii ka count krege kyuki vhii elemts window bnaege
    }
    // creating first window
    int bigger = 0; // these are no greater than k
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
            bigger++;
    }
    // finding other windows
    int ans = bigger;
    for (int i = 0, j = count; j < size; i++, j++)
    {
        if (arr[i] > k) // check old element
            bigger--;
        if (arr[j] > k)
            bigger++;
        ans = min(ans, bigger);
    }
    return ans;
}

int main()
{
    int arr[] = {2, 1, 5, 6, 3};
    int k = 3;

    minSwap(arr, 5, 3);
    cout << minSwap(arr, 5, 3) << " ";

    return 0;
}