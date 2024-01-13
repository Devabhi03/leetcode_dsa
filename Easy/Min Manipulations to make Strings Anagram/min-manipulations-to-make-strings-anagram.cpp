//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minManipulation (int N, string S1, string S2)
{
     unordered_map<char,int>aman;
        int answer=0;
        for(auto i:S1)aman[i]++;
        for(auto i:S2)aman[i]--;
        for(auto i:aman)answer+=abs(i.second);
        return answer/2;
}