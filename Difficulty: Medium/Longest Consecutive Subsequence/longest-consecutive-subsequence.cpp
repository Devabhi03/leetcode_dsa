//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
   public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int mx=0;
        for(auto i:arr){
            mx=max(i,mx);
        }
        vector<int>hash(mx+1,0);
        for(auto i:arr){
            hash[i]=1;
        }
        int pre=0;
        int ans=0;
        for(int i=0;i<hash.size();i++){
            if(hash[i]==0){
                pre=i+1;
            }
            else{
                ans=max(ans,i-pre+1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends