//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  string str;
    int n;
    vector<int>man;
    
    void manacher(){
        
        int mid=-1;
        int sz=0;
        
        for(int i=0;i<n;i++){
            
            int len=0;
            
            if(i<=mid+sz){
                len=min(man[mid-(i-mid)],mid+sz-i);
            }
            
            int left=i-len-1;
            int right=i+len+1;
            
            while(left>=0 && right<n && str[left]==str[right]){
                left--;
                right++;
                len++;
            }
            
            man[i]=len;
            
            if(mid+sz<i+len){
                mid=i;
                sz=len;
            }
            
        }
        
    }

  public:
    int countPS(string &s) {
        // code here
        
        str+='#';
        for(auto&c:s){
            str+=c;
            str+='#';
        }
    
        n=str.length();
        man.resize(n,0);
        
        manacher();
        
        int ans=0;
        for(int i=0;i<n;i++){
            
            if(str[i]=='#'){
                ans+=man[i]/2;   
            }
            else {
                ans+=(man[i]-1)/2;
            }
            //cout<<man[i]<<" ";
        }
        //cout<<"\n";
        
        return ans;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends