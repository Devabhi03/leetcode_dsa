//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &a) {
        vector<int>l=a;
        vector<int>r=a;
        
        for(int i=1;i<a.size();i++){
            l[i]=max(l[i],l[i-1]);
        }
        for(int i=a.size()-1;i>=1;i--){
            r[i-1]=max(r[i],r[i-1]);
        }
        int sum=0;
        for(int i=1;i<a.size()-1;i++){
            sum+=max(0,min(l[i],r[i])-a[i]);
        }
        return sum;
        
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends