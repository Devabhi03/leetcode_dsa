class Solution:
    def minCost(self, keys, freq):
        # code here
        from itertools import accumulate
        
        n = len(keys)
        pre_sum = list(accumulate(freq, initial=0))
        
        # dp[i][j] = minimum cost for keys[i..j]
        dp = [[0] * n for _ in range(n)]
        # root[i][j] = index of optimal root for keys[i..j]
        root = [[0] * n for _ in range(n)]
        
        for i in range(n):
            dp[i][i] = freq[i]
            root[i][i] = i
        
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = float('inf')
                total_freq = pre_sum[j + 1] - pre_sum[i]
                
                # Knuth optimization: search only between root[i][j-1] and root[i+1][j]
                left = root[i][j - 1] if j - 1 >= i else i
                right = root[i + 1][j] if i + 1 <= j else j
                
                for k in range(left, right + 1):
                    cost = total_freq
                    if k > i:
                        cost += dp[i][k - 1]
                    if k < j:
                        cost += dp[k + 1][j]
                    
                    if cost < dp[i][j]:
                        dp[i][j] = cost
                        root[i][j] = k
        
        return dp[0][n - 1]