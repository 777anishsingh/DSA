#include <iostream>
using namespace std;
/*
int main(){
    int n = 3;
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/

// if only zero is present in array
/*int main(){
    int n = 3;
    int arr[3][3]={0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/

// to check if only one value is present in the 2d array
/*int main(){
    int n = 3;
    int arr[3][3] = {1};

      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/

// printing an array
/*
    int main(){
        int arr[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 9}};

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        return 0;
    } */
// linear search in 2d array
/*

bool linearSearch(int arr[3][3], int size1, int size2, int target)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int target;
    cout << "Enter the target value\n";
    cin >> target;
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    linearSearch(arr, 3, 3, target);
    if (linearSearch(arr, 3, 3, target))
    {
        cout << "element found\n";
    }
    else
    {
        cout << "element not found\n";
    }

    return 0;
}*/

// row wise sum
/*
void sumOfColn(int arr[][4], int row, int coln)
{

    for (int i = 0; i < row; i++)
    {
        int sumCol = 0;
        for (int j = 0; j < coln; j++)
        {
            sumCol = sumCol + arr[i][j];
        }
        cout << "Sum of " << (i + 1) << " row : " << sumCol << endl;
    }
}

int main()
{
    int arr[3][4] = {{3, 5, 11, 2}, {7, 9, 8, 0}, {5, 0, 1, 3}};
    sumOfColn(arr, 3, 4);
    return 0;
}
*/
// column wise sum

// void sumOfColn(int arr[][4], int row, int coln)
// {

//     for (int i = 0; i < coln; i++)
//     {
//         int sumCol = 0;
//         for (int j = 0; j < row; j++)
//         {
//             sumCol = sumCol + arr[j][i];
//         }
//         cout << "Sum of " << (i + 1) << " column: " << sumCol << endl;
//     }
// }

// int main()
// {
//     int arr[3][4] = {{3, 5, 11, 2}, {7, 9, 8, 0}, {5, 0, 1, 3}};
//     sumOfColn(arr, 3, 4);
//     return 0;
// }


// rotate array by 90 degree

void rotateArray(int arr[][3], int row, int coln)
{
    for (int i = 0; i < row; i++)
    { 
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main()
{
    int arr[3][3] = {{3, 5, 11}, {7, 9, 8}, {5, 0, 1}};
    rotateArray(arr, 3, 4);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


//spirally print an array
