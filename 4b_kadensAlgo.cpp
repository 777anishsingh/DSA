// implementation of kadens algo
#include <iostream>
#include <climits>
using namespace std;
/*
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < 8; i++)
    {
        sum += arr[i]; // storing sum with each element of array
        ans = max(ans, sum);//comparing the sum with previous ans so as it get highest number
        if (sum < 0) //agr sum 0 se chota hua to use dubara zero krege taki sahi sum mil ske
            sum = 0;
    }
    cout << ans;
    return 0;
}*/
// printing the largest sum of sub array with its sum
//  Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int sum = 0;
    int ans = INT_MIN;
    int track = 0, start = 0, end = 0;
    for (int i = 0; i < 8; i++)
    {
        sum += arr[i];

        ans = max(ans, sum);
        start = track; // niche vala loop btaega staring kaha se hai
        end = i;       // ending to hmesha index value hi btaega

        if (sum < 0)
        {
            sum = 0;
            track = i + 1; // jitni bar is loop me ghusenge utni bar nyi window bnani pdegi isliye staring of window yhii btaega
        }
    }
    cout << "{ ";
    for (int i = start; i < end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "} = " << ans << endl;

    return 0;
}