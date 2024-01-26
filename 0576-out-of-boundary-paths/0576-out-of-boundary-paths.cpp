class Solution {
public:
    int mod = 1000000007;

    int solve(int m, int n, int startRow, int startColumn, int maxmoves, vector<vector<vector<int>>>& dp) {
        if (startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n)
            return 1;

        if (maxmoves <= 0)
            return 0;
        
        if (dp[startRow][startColumn][maxmoves] != -1) {
            return dp[startRow][startColumn][maxmoves];
        }

        long count = 0;
        count += solve(m, n, startRow - 1, startColumn, maxmoves - 1, dp);
        count += solve(m, n, startRow + 1, startColumn, maxmoves - 1, dp);
        count += solve(m, n, startRow, startColumn - 1, maxmoves - 1, dp);
        count += solve(m, n, startRow, startColumn + 1, maxmoves - 1, dp);

        return dp[startRow][startColumn][maxmoves] = count % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(m, n, startRow, startColumn, maxMove, dp) % mod;
    }
};