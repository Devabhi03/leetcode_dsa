class Solution:
    def findPeakGrid(self, matrix):
        return max(((i, j) for i in range(len(matrix)) for j in range(len(matrix[0]))),key=lambda x: matrix[x[0]][x[1]])