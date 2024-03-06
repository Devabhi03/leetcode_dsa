//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        vector<int> zFunction(const string& s) {
            int n = s.length();
            vector<int> z(n);
            for (int i = 1, l = 0, r = 0; i < n; ++i) {
                if (i <= r) {
                    z[i] = min(r - i + 1, z[i - l]);
                }
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    ++z[i];
                }
                if (i + z[i] - 1 > r) {
                    l = i;
                    r = i + z[i] - 1;
                }
            }
            return z;
        }
        vector <int> search(string p, string t)
        {
            int m = p.size();
            string concat = p + "$" + t;
            vector<int> z = zFunction(concat);
            vector<int> ind;
            for (int i = m + 1; i < concat.size(); ++i) {
                if (z[i] == m) {
                    ind.push_back(i - m - 1 + 1);
                }
            }
            return ind;
        }
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends