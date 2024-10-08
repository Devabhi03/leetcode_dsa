//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int help(int n, int x, int y, int z, vector<int> &dp)
    {
       
        if(n == 0)
            return 0;
        
        int ans = INT_MIN;
        
        if(dp[n] != -1)
            return dp[n];
            
        if(n >= x)
            ans = max(ans, 1 + help(n-x, x, y, z, dp));
        if(n >= y)
            ans = max(ans, 1 + help(n-y, x, y, z, dp));
        if(n >= z)
            ans = max(ans, 1 + help(n-z, x, y, z, dp));
        return dp[n] = ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(10007,-1);
        int ans = help(n, x, y, z, dp);
        if(ans < 0)
            return 0;
        return ans;//Your code here
    }


};


//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends