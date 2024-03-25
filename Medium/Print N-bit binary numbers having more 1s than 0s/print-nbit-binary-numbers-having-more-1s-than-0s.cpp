//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<string> ans;
    void cal(int n , string h, int o , int z){
        if(o<z){ // check if 1s is less than 0s
            return;
        }
        if(h.size()==n){
            ans.push_back(h);
            return;
        }
        cal(n,h+'1',o+1,z); // add 1 first to ensure 1 as prefix
        cal(n,h+'0',o,z+1);
    }
vector<string> NBitBinary(int n)
{
    // Your code goes here
    cal(n,"",0,0);
    return ans;
}
};



//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends