//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(), citations.end());
        int n=citations.size()-1;
        int cnt=0;
        int maxii = INT_MIN;
        for(int i=n;i>=0;i--){
            cnt ++;
            
            if(cnt >= citations[i]){
                
                return max(maxii,min(cnt,citations[i]));
            }
            maxii = max(maxii, cnt);
        }
        return maxii;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends