import bisect
class Solution:
    def cntInRange(self, arr, queries):
        arr.sort()
        ql=len(queries)
        ans=[0 for _ in range(ql)]
        for i in range(ql):
            a,b=queries[i]
            left=bisect.bisect_left(arr,a)
            right=bisect.bisect_right(arr,b)
            ans[i]=right-left
        return ans
        