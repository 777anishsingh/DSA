#include <bits/stdc++.h>
using namespace std;

// *****************************************************Time complexity of Binary search = O(logn);*************************************************************

/*  *********************************************************************Binary search****************************************************************************

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    // int mid = (start + end) / 2;  This can cause intergr overflow.Therefore,
    //  We can use mid= (start/2) + (End/2);  OR  mid ={start +[(End-Start)/2]};

    int mid = start +(end-start)/2;

    while (start <= end)
    {
        int midElement = arr[mid];

        // element found
        if (midElement == target)
        {
            return mid;
        }

        // element is in left part
        if (target < midElement)
        {
            end = mid - 1;
        }

        // element in right part
        if (target > midElement)
        {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    return -1;
}

int main()
{

    int target;
    cout << "Enter the Target\n";
    cin >> target;

    int size;
    cout << "Enter the size of an array\n";
    cin >> size;

    int arr[size];
    cout << "Enter the array Elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "element found at index no: " << binarySearch(arr, size, target);

    return 0;
}*/
/*
// ************************************************************to find the first occurance of the target element*******************************************************
int firstElement(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        int midElement = arr[mid];

        if (midElement == target)
        {
            ans = mid;
            end = mid - 1;
        }
        if (target < midElement)
        {
            end = mid - 1;
        }
        if (target > midElement)
        {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    return ans;
}

int main()
{

    int target;
    cout << "Enter the Target\n";
    cin >> target;

    int size;
    cout << "Enter the size of an array\n";
    cin >> size;

    int arr[size];
    cout << "Enter the array Elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "element found at index no: " << firstElement(arr, size, target);

    return 0;
}
*/
// *********************************************************************fixed point question***************************************************************************
/*
int firstOccurance(int arr[], int size)
{

    int start=0;
    int end=size-1;

    int mid= end + (start-end)/2;

    while(start<=end){
        if(arr[mid]==mid){
            return mid;
        }

        if(arr[mid]>mid){
            end=mid-1;
        }
        else{
            start=mid+1;
        }

        mid= end + (start-end)/2;

    }
    return -1;

}

int main()
{

    int size;
    cout << "Enter the size of an array\n";
    cin >> size;

    int arr[size];
    cout << "Enter the array Elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "element found at index no: " << firstOccurance(arr, size);

    return 0;
}*/

// ***************************max height of chain saw to get the exact or more sum of cutted height of tree (search space reduction problem)*****************************
/*
bool isPossible(int arr[], int size, int target, int mid)
{
    int sum = 0, diff = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > mid)
        {
            diff = arr[i] - mid;
        }
        sum = sum + diff;
    }

    if (sum >= target)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getMaxHeightOfSaw(int arr[], int size, int target)
{

    sort(arr, arr + size);

    int s = 0, e = arr[size - 1];
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s / 2);

        if (isPossible(arr, size, target, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}

int main()
{

    int arr[4] = {15, 8, 18, 6};
    int target = 30;
    cout << getMaxHeightOfSaw(arr, 4, target);
    return 0;
}
*/

// *******************************************************************2D ARRAY ME BINARY SEACRH **********************************************************************
/*
bool binaryS(int arr[][3], int n, int m, int row, int target)
{
    int s = 0;
    int e = m - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[row][mid] == target)
        {
            cout << row << " " << mid << endl;
            return true;
        }
        else if (arr[row][mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}

bool binSearch(int arr[][3], int n, int m, int target)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid][0] == target)
        {
            return true;
        }
        else if (arr[mid][m - 1] == target)
        {
            return true;
        }
        else if (target > arr[mid][0] && target < arr[mid][m - 1])
        {
            bool ans = binaryS(arr, n, m, mid, target);
            return ans;
        }
        else if (target < arr[mid][0])
        {
            e = mid - 1;
        }
        else if (target > arr[mid][m - 1])
        {
            s = mid + 1;
        }
    }
    return false;
}

int main()
{
    int arr[3][3] = {1, 5, 9, 14, 20, 23, 30, 34, 43};
    int target = 34;
    cout << binSearch(arr, 3, 3, target) << endl;
}
*/

//**********************************************************Sqrt of x including the floating numbers*******************************************************************

int isBinary(int x){
    long long int s=0;
    long long int e=x;
    long long int ans=-1;
    while(s<=e){
        long long int mid=s+(e-s)/2;
        long long int square=pow(mid,2);
        if(square==x){
            return mid;
        }
        else if(square>x){
            e=mid-1;
        }
        else if(square<x){
            ans=mid;
            s=mid+1;
        }
    }
    return ans;
}

void preciseAns(int x,int precision,int temp){
    double ans=temp;
    double fact=1;
    for(int i=0;i<precision;i++){
        fact=fact/10;
        for(double j=ans;j*j<x;j=j+fact){
            ans=j;
        }
    }
    cout<<ans<<endl;
}



int main()
{
    int x;
    cout<<"Enter the Number\n";
    cin>>x;
    int precision;
    cout<<"Enter the value to which sqrt should be precised\n";
    cin>>precision;
    int temp=isBinary(x);
    preciseAns(x,precision,temp);

}