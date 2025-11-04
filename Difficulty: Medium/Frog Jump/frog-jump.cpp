class Solution {
  public:
    
    int solve(vector<int>& height, int i, vector<int>& dp) {
        
        if (i >= height.size()-1) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int step1 = INT_MAX;
        int step2 = INT_MAX;
        
        if (i+1 < height.size()) {
            step1 = abs(height[i] - height[i+1]) + solve(height, i+1, dp);
        }
        if (i+2 < height.size()) {
            step2 = abs(height[i] - height[i+2]) + solve(height, i+2, dp);
        }
        
        return dp[i] = min(step1, step2);
    }
    int minCost(vector<int>& height) {
        // Code here
        vector<int> dp(height.size()+1, -1);
        return solve(height, 0, dp);
    }
};