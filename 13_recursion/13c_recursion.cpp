#include <bits/stdc++.h>
using namespace std;

// INCLUSION AND EXCLUSION
// Q1 Power set of all subsets
void printPowerSet(string input, int index, string output)
{
    if (index == input.length())
    {
        cout << output << endl;
        return;
    }

    char ch = input[index];

    // exclude ch
    printPowerSet(input, index + 1, output);

    // include ch
    output.push_back(ch);
    printPowerSet(input, index + 1, output);
}

// Q2 combination in a string of digits
void findCombination(string input, int index, string output)
{
    if (index == input.length())
    {
        cout << output << endl;
        return;
    }

    char ch = input[index];
    // exclusion ==> No space
    output.push_back(ch);
    findCombination(input, index + 1, output);

    // Inclusion of space ==> Adding space
    output.push_back(' ');

    if (input[index + 1] != '\0')
    {
        findCombination(input, index + 1, output);
    }
}

// Q3 find all even binary equence with same sum of first & second half bits

void findCount(int leftSum, int rightSum, char *arr, int i, int j, int &count)
{
    if (i > j)
    {
        if (leftSum == rightSum)
        {
            cout << "value " << count++ << " ==> " << arr << endl;
        }
        return;
    }

    // 0,0
    arr[i] = '0';
    arr[j] = '0';
    findCount(leftSum, rightSum, arr, i + 1, j - 1, count);

    // 0,1
    arr[i] = '1';
    arr[j] = '0';
    findCount(leftSum + 1, rightSum, arr, i + 1, j - 1, count);

    // 1,0
    arr[i] = '0';
    arr[j] = '1';
    findCount(leftSum, rightSum + 1, arr, i + 1, j - 1, count);

    // 1,1
    arr[i] = '1';
    arr[j] = '1';
    findCount(leftSum + 1, rightSum + 1, arr, i + 1, j - 1, count);
}
void compute_value(int n)
{
    char *arr = new char[2 * n];
    int count = 1;
    return findCount(0, 0, arr, 0, 2 * n - 1, count);
}

// Q4 Rat in a maze
//{ Driver Code Starts
// Initial template for C++

bool isSafe(int x,int y,int n, vector<vector<int>> visited, vector<vector<int>> &m){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;}
        else{
            return false;}
    }
        
void solve(vector<vector<int>> &m,int n,vector<string>& ans,int x,int y,
                vector<vector<int>> visited, string path){
        
        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y]==1;
        
        //4 choices - D, L, R, U
        
        //down
        int newX=x+1;
        int newY=y;
        if(isSafe(newX,newY,n,visited,m)){
            path.push_back('D');
            solve(m,n,ans,newX,newY,visited,path);
            path.pop_back();
        }
        
        //Left
        newX=x;
        newY=y-1;
        if(isSafe(newX,newY,n,visited,m)){
            path.push_back('L');
            solve(m,n,ans,newX,newY,visited,path);
            path.pop_back();
        }
        
        //right
        newX=x;
        newY=y+1;
        if(isSafe(newX,newY,n,visited,m)){
            path.push_back('R');
            solve(m,n,ans,newX,newY,visited,path);
            path.pop_back();
        }
        
        //up
        newX=x-1;
        newY=y;
        if(isSafe(newX,newY,n,visited,m)){
            path.push_back('U');
            solve(m,n,ans,newX,newY,visited,path);
            path.pop_back();
        }
    
            visited[x][y]==0;
    }
    
vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0]==0)
            return ans;
        
       
        int x=0,y=0;
        vector<vector<int>> visited = m;
        //initilized with zero
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        
        string path="";
        solve(m,n,ans,x,y,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }

int main()
{
    // Q1
    //  string str;
    //  cout << "Enter the String " << endl;
    //  cin >> str;
    //  string output = "";
    // printPowerSet(str, 0, output);

    // Q2
    // string str;
    // cout << "Enter the Number String " << endl;
    // cin >> str;
    // string output = "";
    // findCombination(str, 0, output);

    // Q3

    // int n;
    // cin >> n;
    // compute_value(n);


    //Q4
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

    return 0;
}