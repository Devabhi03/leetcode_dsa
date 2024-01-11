// class Solution {
// public:
//     int nextIndex(int idx,vector<vector<int>>&a)
//     {
//         int end = a.size(),st=idx+1;
//         while(st<end) {
//             int md = st+(end-st)/2;
//             if(a[md][0]>=a[idx][1])
//             end = md;
//             else
//             st=md+1;
//         }
//         return st;
//     }
//     int f(int idx,vector<vector<int>>&a,vector<int>&dp) {
//         if(idx==a.size())
//             return 0;
//         if(dp[idx]!=-1)
//             return dp[idx];
//         int take = a[idx][2] + f(nextIndex(idx,a),a,dp),notTake = f(idx+1,a,dp);
//         return dp[idx] = max(take,notTake);
//     }
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         vector<vector<int>>a;
//         int n = startTime.size();
//         vector<int>dp(n+1,-1);
//         for(int i=0;i<n;i++)
//         a.push_back({startTime[i],endTime[i],profit[i]});
//         sort(a.begin(),a.end());
//         return f(0,a,dp);
//     }
// };
class Solution {
public:

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = s.size(); 
        vector<pair<int, int>> st(n);
        for(int i = 0; i < n; i++) st[i] = {s[i], i};
        sort(st.begin(), st.end());
        vector<int> dp(n+1, 0); 
        for(int i = n-1; i > -1; i--)
            dp[i] += max(dp[i+1], p[st[i].second] + dp[lower_bound(st.begin() + i, st.end(), make_pair(e[st[i].second], 0)) - st.begin()]);
        return dp[0];
    }
};