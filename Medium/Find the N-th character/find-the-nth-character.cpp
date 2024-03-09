//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        
        // THIS IS THE CORRECT AND OPTIMISED CODE
        int j = r, num = n+1; // r times divide and n+1 for 0 based indexing
        while(j--) num = (num+1)/2; // for odd-even management
        s.resize(num);
        
        for(int i=1; i<=r; i++){ // r times multiply
            string ss;
            for(auto ch: s) ss += (ch == '1') ? "10" : "01";
            s = ss;
        }
        return s[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends