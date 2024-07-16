//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string printString(string s, char ch, int count) {
        // Your code goes here
        int cur = 0;
        string rem = "";
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == ch)
                cur++;
            if(cur == count)
            {
                rem = s.substr(i+1, s.length());
                break;
            }
        }
        return rem;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends