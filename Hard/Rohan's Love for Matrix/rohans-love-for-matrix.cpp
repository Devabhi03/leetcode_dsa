//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     int firstElement(int n) {
        /* 1 1 2 3 5 8 13*/
        int mod = 1000000007; 
        int a = 1,b = 1,c = 1 ; 
        for(int i=3;i<=n;i++){
            c = (a+b)%mod; 
            a = b ;
            b = c ; 
        }
        return c; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends