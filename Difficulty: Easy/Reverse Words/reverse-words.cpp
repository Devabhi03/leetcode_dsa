//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        reverse(str.begin(),str.end());
        int n=str.length(),j=0;
        str.push_back('.');
        for(int i=0;i<=n;i++)
        {
            if(str[i]=='.')
            {
                reverse(str.begin()+j,str.begin()+i);
                j=i+1;
            }
        }
        str.pop_back();
        return str;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends