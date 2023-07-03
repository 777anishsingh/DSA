#include <bits/stdc++.h>
using namespace std;

/*
STL for character array
1. for length= strlen(arrayName);
2. fror checking 2 strings are equal if equal gives 0 if not gives -1 = strcmp(arr1,arr2);
3. for copying 1 char array to other = strcpy(destination,source);
4.
*/
/*
// ***********************length of character array**************************
int getlength(char arr[])
{
    int index = 0;
    while (arr[index] != '\0')
    {
        index++;
    }
    return index;
}

int main()
{
    char arr1[10] = "anish";
    char arr2[10] = "babbar";
    cout << getlength(arr1)<<endl;
    cout<<strcmp(arr1,arr2);
    return 0;
}*/
/*
//reverse character array
void reverseArr(char arr[])
{
    int e = strlen(arr) - 1;
    int s = 0;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    cout << arr;
} 

int main()
{
    char arr[20] = "Anish Singh Butola";
    reverseArr(arr);
    return 0;
}*/

