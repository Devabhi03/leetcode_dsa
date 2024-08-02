//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
      if(i==str1.length()&&j!=str2.length()){
          return str2.length()-j;
      }
      
      if(j==str2.length()&&i!=str1.length()){
          return str1.length()-i;
      }
      
      if(i==str1.length()&&j==str2.length()){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      
      int ans=0;
      if(str1[i]==str2[j]){
          return solve(str1,str2,i+1,j+1,dp);
      }else{
          // insert
          int insert=solve(str1,str2,i,j+1,dp)+1;
          // remove
          int remove=solve(str1,str2,i+1,j,dp)+1;
         // replace
         int replace=solve(str1,str2,i+1,j+1,dp)+1;
         
         dp[i][j]=min(insert,min(remove,replace));
      }
      return dp[i][j];
      
      
  }
    int editDistance(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=solve(str1,str2,0,0,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends