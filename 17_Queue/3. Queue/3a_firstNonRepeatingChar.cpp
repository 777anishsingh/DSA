#include<bits/stdc++.h>
using namespace std;
 
int firstUniqChar(string s) {
        int freq[26]={0};
       
        queue<int> q;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            freq[ch-'a']++;
            q.push(i);

            while(!q.empty()){
                char letter=s[q.front()];
                if(freq[letter -'a']>1)
                    q.pop();
                else
                    break;
            }
        }

        if(q.empty())
            return -1;
        else
            return q.front();
    }

int main(){

    return 0;
}