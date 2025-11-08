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
using vvvi = vector<vvi>;
struct Cell {
    int x;
    int y;
    int z;
};
const int MOD = 1e9 + 7;
const int INF = 1e18;

class Solution {
  public:
    int n,m;
    vvvi dp;
    int helper(int i,int j,int k,vvi &mat){
        auto is_valid=[&](int i,int j){
            return (i>=0 && j>=0 && i<n && j<m);
        };  
        if(i==n-1 && j==m-1) return k==mat[i][j];
        if(dp[i][j][k]!=-1) return dp[i][j][k];
    
        int x=mat[i][j];
        int cnt1=0,cnt2=0;
        if(k>=x){
            if(is_valid(i+1,j) && k-x>=mat[i+1][j])
                cnt1=helper(i+1,j,k-x,mat);
            if(is_valid(i,j+1) && k-x>=mat[i][j+1])
                cnt2=helper(i,j+1,k-x,mat);
        }
        return dp[i][j][k]=cnt1+cnt2;
    }
  
    int numberOfPath(vvi& mat, int k) {
        // Code Here
        n=mat.size(),m=mat[0].size();
        dp.resize(n,vvi(m,vi(k+1,-1)));
        return helper(0,0,k,mat);
    }
};