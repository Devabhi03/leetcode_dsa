class Solution:
    def minSuperSeq(self, X: str, Y: str) -> int:
        n, m = len(X), len(Y)
        
        # Create DP table for LCS
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        
        # Fill DP table
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if X[i - 1] == Y[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        lcs_length = dp[n][m]
        
        # Length of Shortest Common Supersequence
        return n + m - lcs_length