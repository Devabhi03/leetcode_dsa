//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        
        if(k==n+m){
            return max(arr1[n-1],arr2[m-1]);
        }
        if(k==1){
            return min(arr1[0],arr2[0]);
        }
        if(n>m){
            return kthElement(k,arr2,arr1);
        }
        int low = max(0,k-m), high = min(k,n);
        while(low<=high){
            int mid = (low+high)>>1;
            int idx = k-mid;
            
            int arr1Left = (mid == 0) ? INT_MIN : arr1[mid - 1];
            int arr1Right = (mid == n) ? INT_MAX : arr1[mid];
            int arr2Left = (idx == 0) ? INT_MIN : arr2[idx - 1];
            int arr2Right = (idx == m) ? INT_MAX : arr2[idx];
    
            if (arr1Left <= arr2Right && arr2Left <= arr1Right) {
                return max(arr1Left, arr2Left);
            } else if (arr1Left > arr2Right) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
             
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends