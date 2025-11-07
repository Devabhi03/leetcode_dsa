#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e18;

// Type aliases
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl= vector<vl>;
using vpii = vector<pii>;

class Solution {
  public:
    vl dp;
    int n;
    vi precompute;
    int next_idx(int i,vvi &jobs){
        int etime=jobs[i][1];
        int l=i,r=n-1;
        int ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(jobs[mid][0]>=etime){
                ans=mid;
                r=mid-1;
            } else l=mid+1;
        }
        return ans;
    }
    
    int helper(int idx,vvi &jobs){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
    
        int take=0,nottake=0;
        int nidx=precompute[idx];
        take=(jobs[idx][2]+helper(nidx,jobs))%MOD;
    
        nottake=helper(idx+1,jobs)%MOD;
        return dp[idx]=max(take,nottake);
    }
    
    int maxProfit(vvi &jobs){
        n=jobs.size();
        sort(all(jobs));   
        precompute.resize(n,-1);
        for(int i=0;i<n;i++){
            precompute[i]=next_idx(i,jobs);
        }
        dp.resize(n,-1);
        return helper(0,jobs);
    }
};