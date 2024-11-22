//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int maximumProfit(vector<int> &p) {
        int n=p.size();
        int b=p[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(p[i]>=b){
                profit=max(profit,p[i]-b);
            }
            else{
                b=p[i];
            }
        }
        return profit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends