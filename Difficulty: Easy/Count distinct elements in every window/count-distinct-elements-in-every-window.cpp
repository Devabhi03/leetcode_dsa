//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int i = 0;
        int j = 0;
        unordered_map<int,int>mpp;
        vector<int>ans;
        while(j < arr.size())
        {
            mpp[arr[j]]++;
            if(j-i+1 == k)
            {
                ans.push_back(mpp.size());
            }
            else if(j-i+1 > k)
            {
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0)
                {
                    mpp.erase(arr[i]);
                }
                i++;
                ans.push_back(mpp.size());
            }
            j++;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends