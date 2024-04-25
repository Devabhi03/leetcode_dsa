//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        
        int dx[]={1,-1,-1,-1,1,1};
        int dy[]={0,0,-1,1,-1,1};
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                bool can=true;
                int temp=0;
                for(int k=0;k<6;k++)
                {
                    if(dx[k]+i>=0 && dx[k]+i<n && dy[k]+j>=0 && dy[k]+j<m)
                     { 
                         temp+=mat[dx[k]+i][dy[k]+j];
                       
                     }
                     else
                     {
                           can=false;
                         break;
                     }
                      
                      
                }
                if(can==true)
                {
                    ans=max(ans,temp+mat[i][j]);
                
                }
            }
        }
        
        return ans==INT_MIN?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends