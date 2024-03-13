//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        int n = mat.size();
        //  right/down, down-left , down/right, up-right, right/down
        int i = 0, j = 0;
        vector<int> v;
        v.push_back(mat[i][j]);
        while(1){
            // right/down
            
            if(i>=0 && i<n && j+1<n && j+1>=0){
                j++;
                v.push_back(mat[i][j]);
            }
            else if(i+1>=0 && i+1<n && j<n && j>=0){
                i++;
                v.push_back(mat[i][j]);
            }
            else break;
            // down-left
            while(i+1>=0 && i+1<n && j-1<n && j-1>=0){
                i++;
                j--;
                v.push_back(mat[i][j]);
            }
            // down/right
            if(i+1>=0 && i+1<n && j<n && j>=0){
                i++;
                v.push_back(mat[i][j]);
            }
            else if(i>=0 && i<n && j+1<n && j+1>=0){
                j++;
                v.push_back(mat[i][j]);
            }
            else break;
            while(i-1>=0 && i-1<n && j+1<n && j+1>=0){
                j++;
                i--;
                v.push_back(mat[i][j]);
            }
            
        }
        return v;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends