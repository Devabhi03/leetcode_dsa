//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) 
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            string num = to_string(i);
            if(num.find('4') != string::npos)
            {
                ans++;
            }
        }
        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends