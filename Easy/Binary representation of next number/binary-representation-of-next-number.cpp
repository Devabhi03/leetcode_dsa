//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int x = s.size();
 
        reverse(s.begin(),s.end());
        for(int i=x-1;i>=0;i--){
            if(s[i] == '1'){        
                break;
            }
            s.pop_back();
        }
        reverse(s.begin(),s.end());
// using the above code we first remove the starting zeroes present in a string.eg- 0011 to 11
        
        int n = s.size();
        int count=0;
        int a = 1;
       
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                a=0;
                s[i] = '1';
                break;
            }
            s.pop_back();
            count+=1;
        }
// above code is used to find out the no of ones present from the last and counted its no and pop the element at th same time because after adding 1 to 1 we get 10 so that means poping out that element and replacing it with zero in the next steps 
        if(a==1){
            s.push_back('1');
        }
// using count we push back elements 0 till count no
        for(int i=n-count+a;i<n+a;i++){
            s.push_back('0');
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends