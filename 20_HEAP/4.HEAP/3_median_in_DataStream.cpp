#include <bits/stdc++.h>
using namespace std;

void solve(double& median,priority_queue<int>& maxi, priority_queue<int,vector<int>,greater<int>>& mini, int element){

	if(maxi.size()==mini.size()){
		if(element > median){
			mini.push(element);
			median = mini.top();
		}
		else{
			maxi.push(element);
			median = maxi.top();
		}
	}

	else if(maxi.size()==mini.size()+1){
		if(element > median){
			mini.push(element);
		}
		else{
			int maxTop = maxi.top(); 
            maxi.pop();
			mini.push(maxTop);
			maxi.push(element);
		}
		median = (mini.top() + maxi.top())/2.0;
	}

	else if(mini.size()==maxi.size()+1){
		if(element > median){
			int miniTop = mini.top(); mini.pop();
			maxi.push(miniTop);
			mini.push(element);
		}
		else{
			maxi.push(element);
		}
		median = (maxi.top() + mini.top())/2.0;
	}

}




int main(){

    int arr[]={12,10,8,4,2,3,15};
    int n=7;

	double median = 0;
	priority_queue<int> maxi;
	vector<int> ans;
	priority_queue<int,vector<int>,greater<int>> mini;

	for(int i=0;i<n;i++){
		int element = arr[i];
		solve(median, maxi, mini, element);
		cout<<median<<" ";
        
	}
}
