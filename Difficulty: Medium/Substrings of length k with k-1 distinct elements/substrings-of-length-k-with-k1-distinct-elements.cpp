class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int hash[26]={0};
        int n = s.length();
        int i=0;
        int cnt=0;
        int j=0;
        
        int ans = 0;
        while(i<k){
            if(hash[s[i] - 'a'] == 0){
                cnt++;
            }
            hash[s[i]-'a']++;
            
            i++;
            
        }
        if(cnt==k-1){
            ans++;
        }
        
        for(i=k;i<n;i++){
            
            hash[s[j]-'a']--;
            if(hash[s[j]-'a']==0){
                cnt--;
            }
            
            if(hash[s[i] - 'a'] == 0){
                cnt++;
            }
            hash[s[i]-'a']++;
            
            j++;
            if(cnt==k-1){
                ans++;
            }
            
        }
        return ans;
    }
};