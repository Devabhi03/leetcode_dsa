//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x){
        deque<int> min_q, max_q;
        int left = 0, ans = 0, i = 0, j = 0;
        
        for(int right = 0; right < arr.size(); ++right){
            while(!min_q.empty() && arr[right] < arr[min_q.back()]){
                min_q.pop_back();
            }
            while(!max_q.empty() && arr[right] > arr[max_q.back()]){
                max_q.pop_back();
            }
            
            min_q.push_back(right);
            max_q.push_back(right);
            
            while(arr[max_q.front()] - arr[min_q.front()] > x){
                if(min_q.front() == left) min_q.pop_front();
                if(max_q.front() == left) max_q.pop_front();
                ++left;
            }
            
            if(ans < right - left + 1){
                ans = right - left + 1;
                i = left; j = right;
            }
        }
        
        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends