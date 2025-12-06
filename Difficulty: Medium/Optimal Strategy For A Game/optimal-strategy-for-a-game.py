class Solution:

    def maximumAmount(self, arr):

        n = len(arr)
        sum = 0
        dp = [0] * n
        for i in range(n - 1, -1, -1):

            # Calculating the sum of all the elements
            sum += arr[i]
            for j in range(i, n):
                if i == j:

                    # If there is only one element then we
                    # can only get arr[i] score
                    dp[j] = arr[j]
                else:

                    # Calculating the dp states
                    # using the relation
                    dp[j] = max(arr[i] - dp[j], arr[j] - dp[j - 1])

        # Equating and returning the final answer
        # as per the relation
        return (sum + dp[n - 1]) // 2