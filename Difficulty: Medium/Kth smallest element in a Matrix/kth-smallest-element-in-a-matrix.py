class Solution:
    def kthSmallest(self, mat, k):
        # code here
        l=[]
        for i in mat:
            l+=i
        l.sort()
        return l[k-1]