//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
 long long ans=0;
        long long int mod=2147483648 ;
        for(int i=0;i<32;i++)
        {
            if(x&1==1)
            {
                ans=ans + mod;
            }
            x>>=1;
            mod = mod / 2;
        }
        return ans;        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends