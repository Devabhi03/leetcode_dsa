#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

class Solution {
  public:
    int n;
    vvi dp;
    int helper(int i,bool buy,vi &arr){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int op1=0,op2=0;
        if(buy){
            op1=-arr[i]+helper(i+1,!buy,arr);
            op2=helper(i+1,buy,arr);
        } else {
            op1=arr[i]+helper(i+2,!buy,arr);
            op2=helper(i+1,buy,arr);
        }
        return dp[i][buy]=max(op1,op2);
    }
    
    int maxProfit(vi& arr) {
        n=arr.size();
        dp.resize(n,vi(2,-1));
        return helper(0,1,arr);
    }
};