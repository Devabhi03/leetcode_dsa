//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
    int count = 0; // To count the number of octets
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '.') return 0; // Check if the first character is a '.'

        long sum = 0;
        int digitCount = 0; // To count the number of digits in an octet

        // Handle leading zeros
        if (str[i] == '0' && (i + 1 < str.size() && str[i + 1] != '.')) {
            return 0;
        }

        while(i < str.size() && str[i] != '.') {
            if(!isdigit(str[i])) return 0; // Non-digit characters are not allowed
            int digit = str[i] - '0';
            sum = sum * 10 + digit;
            digitCount++;
            i++;
        }

        if(sum < 0 || sum > 255 || digitCount > 3 || digitCount == 0) return 0;

        count++;

        if (i < str.size() && str[i] == '.' && i + 1 == str.size()) return 0; // Check if there's a trailing dot
    }

    return count == 4; // A valid IP address should have exactly 4 octets
}
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends