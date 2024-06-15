//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
 
        vector<long long int>pre(10,1);   // for n=1
        
        for(int i=2;i<=n;i++){
            vector<long long int>curr(10,0); 
            for(int i=1;i<=9;i++){


                curr[i]+=pre[i]; 


                if(i-1>0 && (i-1)%3!=0){
                    curr[i]+=pre[i-1];
                }


                if(i+1<10 && (i+1)%3!=1 ){
                    curr[i]+=pre[i+1];
                    
                }


                if(i-3>0){
                    curr[i]+=pre[i-3];
                }


                if(i+3<10){
                    curr[i]+=pre[i+3];
                }
            }


            curr[0]=pre[8]+pre[0]; // handling execption of 0
            curr[8]+=pre[0];


            pre=curr;
            
        }
        
        long long int ans=0;
        for(int i=0;i<=9;i++){
            ans+=pre[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends