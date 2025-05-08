//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:

    int findMissing(vector<int> &arr) {
        // code here
        int diff=arr[1]-arr[0];
        
        if(diff>0){
        for(int i=1;i<arr.size()-1;i++)
        {
            int d=arr[i+1]-arr[i];
            if(d==diff) continue;
            if(diff>d) return arr[i]-d;
            else if(diff<d) return arr[i]+diff;
        }
        }
        else{
            for(int i=1;i<arr.size()-1;i++)
           {
            int d=arr[i+1]-arr[i];
            if(d==diff) continue;
            if(diff<d) return arr[i]-d;
            else if(diff>d) return arr[i]+diff;
           }
            
        }
        return *(arr.end()-1)+diff ;
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
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends