class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        """
        :type arr: List[int]
        :type mat: List[List[int]]
        :rtype: int
        """
        num_to_pos = {}
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                num_to_pos[mat[i][j]] = (i, j)
        
        row_count = [0] * len(mat)
        col_count = [0] * len(mat[0])
        
        for index, num in enumerate(arr):
            row, col = num_to_pos[num]
            
            row_count[row] += 1
            col_count[col] += 1
            
            if row_count[row] == len(mat[0]) or col_count[col] == len(mat):
                return index
        
        return -1