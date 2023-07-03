#include <bits/stdc++.h>
using namespace std;


//RETURNING THE LARGEST SUM IN CONT.SUBARRAY

void kedaneAlgo(int arr[], int size)
{
    int sum = 0;
    int i = 0;
    int ans = INT_MIN;
    for (i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        ans = max(ans, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << ans;
    //newprint(arr, size, start, end);
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    kedaneAlgo(arr, 8);

    return 0;
}
/*
// RRETURNING THE SUBARRAY ITSELF

void print(int arr[], int size, int a, int b)
{
    cout << "and the subarray is = ";
    for (int i = a; i <= b; i++)
    {
        cout << arr[i] << " ";
    }
}

void kedaneAlgoSubArray(int arr[], int size)
{
    int sum = 0;
    int i = 0;
    int ans = INT_MIN;
    int start = 0, end = 0, mid = 0;
    for (i = 0; i < size; i++)
    {
        sum = sum + arr[i];

        if (sum < 0)
        {
            sum = 0;
            start = i + 1;
        }

        if (ans < sum)
        {
            ans = max(ans, sum);
            end = i;
        }
    }
    cout << "\nLargest sum in continegeous subarray is = " << ans << endl
         << "Starting index = " << start << endl
         << "Ending index = " << end << endl;
    print(arr, size, start, end);
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    kedaneAlgoSubArray(arr, 8);

    return 0;
}
*/