class Solution:
     def matrixChainOrder(self, arr):
        n = len(arr)
        dp = [[float("inf")] * n for _ in range(n)]
        backtrack = [[None] * n for _ in range(n)]
        for i in range(n - 1):
            dp[i][i + 1] = 0
            backtrack[i][i + 1] = chr(ord("A") + i)
        for length in range(2, n):
            for start in range(n - length):
                end = start + length
                for mid in range(start + 1, end):
                    cost = dp[start][mid] + dp[mid][end] + arr[start] * arr[mid] * arr[end]
                    if cost < dp[start][end]:
                        dp[start][end] = cost
                        backtrack[start][end] = (start, mid, end)
        
        def reconstruct(start, end, acc=[]):
            if start + 1 == end:
                acc.append(backtrack[start][end])
            else:
                start, mid, end = backtrack[start][end]
                acc.append("(")
                reconstruct(start, mid, acc)
                reconstruct(mid, end, acc)
                acc.append(")")
            return acc
        
        return "".join(reconstruct(0, n - 1))