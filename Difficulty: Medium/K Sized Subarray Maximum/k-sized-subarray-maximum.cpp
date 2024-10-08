//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        // APPROACH -1 TLE , 5 TEST CASES LEFT
        // vector<int>ans;
        // int i=0,j=0;
        // while(j<arr.size()){
        //     if(j-i+1<k){
        //         j++; // i just expanded the window size
        //     }else if(j-i+1==k){
        //         vector<int> temp(arr.begin()+i,arr.begin()+j+1);
        //         ans.push_back(*max_element(temp.begin(),temp.end()));
        //         i++;j++;
        //     }
        // }
        // return ans;
        

         // APPROACH -2 USING DEQUEUE        


        deque<int> dq;
        vector<int> ans;
        
        for (int i = 0; i < arr.size(); i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove elements from the back of the deque that are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            // Add the current element index to the deque
            dq.push_back(i);
            
            // Once we have a full window, the front of the deque is the maximum element for that window
            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends