//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) 
    {
        int count = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for(int i = 0; i < arr.size() -2; i++)
        {
            int start = i+1;
            int end   = arr.size() - 1;
            while(start < end)
            {
                if(arr[i] + arr[start] + arr[end] == target)
                {
                    //cout << " sum is " <<  arr[i] + arr[start] + arr[end] << endl;
                    //cout << "i " << i << " j " << start << " k " << end << endl;
                    count++;
                    int temp = start+1;
                    while(temp < end && arr[temp] == arr[temp-1])
                    {
                        temp += 1;
                        count++;
                    }
                    end--;
                    
                }
                else if(arr[i] + arr[start] + arr[end] > target)
                    end--;
                else
                    start++;
                
            }
        }
        return count;
        // Code Here
    }


};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends