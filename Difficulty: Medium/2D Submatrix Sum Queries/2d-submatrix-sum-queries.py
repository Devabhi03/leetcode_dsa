class Solution:
     def prefixSum2D(self, mat, queries):
        m, n = len(mat), len(mat[0])
        suffix_sums = [[0] * (n + 1) for _ in range(m + 1)]
        for x in reversed(range(m)):
            suffix_sums[x][n - 1] = suffix_sums[x + 1][n - 1] + mat[x][n - 1]
        for y in reversed(range(n)):
            suffix_sums[m - 1][y] = suffix_sums[m - 1][y + 1] + mat[m - 1][y]
        for x in reversed(range(m - 1)):
            for y in reversed(range(n - 1)):
                suffix_sums[x][y] = (
                    suffix_sums[x + 1][y]
                    + suffix_sums[x][y + 1]
                    - suffix_sums[x + 1][y + 1]
                    + mat[x][y]
                )
        answers = []
        for x1, y1, x2, y2 in queries:
            answers.append(
                suffix_sums[x1][y1]
                - suffix_sums[x2 + 1][y1]
                - suffix_sums[x1][y2 + 1]
                + suffix_sums[x2 + 1][y2 + 1]
            )
        return answers