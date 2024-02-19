//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int sol(unordered_map<char,int>&mp) {
        int ans = 0;
        for(auto it:mp) {
            ans+=(it.second*it.second);
        }
        return ans;
    }
    int minValue(string s, int k){
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        for(auto it:mp) pq.push({it.second,it.first});
        
        while(k-- and !pq.empty()) {
            char ch = pq.top().second;
            int freq=pq.top().first;
            freq--;
            mp[ch]--;
            pq.pop();
            pq.push({freq,ch});
        }
        if(k>0) return 0;
        return sol(mp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends