//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        auto it = lower_bound(arr.begin(), arr.end(),x);
        
        //if x is present in array, we will not consider it
        if(*it == x) arr.erase(it);
        
        vector<int> ans;
        
        //iterator of number greater than x
        auto ahead = it;
        
        //iterator of number lesser than x
        auto behind = it-1;
        
        while(k--){
            //if no number at end go to numbers behind x
            if(ahead == arr.end()){
                ans.push_back(*behind);
                behind--;
            }
            //if no number at start go to numbers ahead of x
            else if(behind == arr.begin()-1){
              ans.push_back(*ahead);
                ahead++;  
            }
            //if ahead is closer, take ahead and increment ahead iterator
            else if(*ahead -x <= x - *behind){
                ans.push_back(*ahead);
                ahead++;
            }
            //if behind number is closer, take behind and decrement behind iterator
            else{
                ans.push_back(*behind);
                behind--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends