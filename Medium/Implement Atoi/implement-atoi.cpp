//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
int atoi(string s) {
    int sign = 0;
    long int out = 0;  // Using long int to handle potential overflow
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 && s[i] == '-') {
            sign = 1;
            continue;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            if (i == 0)
                out = s[i] - '0';
            else
                out = out * 10 + (s[i] - '0');
        } else {
            return -1;  // Invalid character encountered
        }
    }

    if (sign == 1)
        out = -out;

    return static_cast<int>(out);  // Convert long int to int
}
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends