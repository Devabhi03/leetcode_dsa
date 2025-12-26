class Solution:
    def kthMissing(self, arr, k):
        l=len(arr)
        le=0
        ri=l-1
        while le<=ri:
            mi=(le+ri)//2
            c=arr[mi]-mi-1
            
            if c<k:
                le=mi+1
            else:
                ri=mi-1
        return le+k