#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data,rowIndex, colIndex;
    node(int data,int row, int col){
        this->data=data;
        rowIndex=row;
        colIndex=col;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> minRangeinKlists(vector<vector<int>>& arr){
    priority_queue<node*, vector<node*>, compare> pq;
    int mini = INT_MAX;
    int maxi =INT_MIN;

    for(int i=0; i<arr.size();i++){
        int element = arr[i][0]; //only first element of each array
        node* temp = new node(element, i ,0);
        pq.push(temp);
        maxi=max(maxi, element);
        mini=min(element,mini);
    }
    int startAns=mini;
    int endAns=maxi;

    while(!pq.empty()){
        node* topNode = pq.top();
        pq.pop();

        mini = topNode->data;
        int topRow = topNode->rowIndex;
        int topCol = topNode->colIndex;

        if( maxi - mini < endAns - startAns){
            startAns=mini;
            endAns=maxi;            
        }

        if( topCol + 1 < arr[topRow].size() ){
            node* newNode = new node(arr[topRow][topCol+1], topRow, topCol + 1);
            maxi = max(maxi, arr[topRow][topCol+1]);
            pq.push(newNode);
        }
        else{
            break;
        }

    }
    vector<int> ans;
    ans.push_back(startAns);
    ans.push_back(endAns);
    return ans;
}

 
int main(){

    vector<vector<int>> arr{
                {4,10,15,24,26},
                {0,9,12,20},
                {5,18,22,30}
    };

    vector<int> ans = minRangeinKlists(arr);

    cout<<"The min Range that covers atleast one element of each array =  [ ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    

    return 0;
}