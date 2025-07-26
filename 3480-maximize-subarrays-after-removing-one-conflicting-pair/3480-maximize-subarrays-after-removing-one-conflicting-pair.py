class Solution:
    def maxSubarrays(self, n: int, p: List[List[int]]) -> int:
        p = [*map(tuple,map(sorted,p)),(n+1,n+1)]
        sl1,sl2,res,z = SortedList(p),SortedList(p,itemgetter(1)),0,Counter()
        for i in range(1,n+1):
            while sl1 and sl1[0][0]<i: sl2.remove(sl1.pop(0))
            res += len(sl2) and sl2[0][1]-i
            z[sl2[0]] += len(sl2)>1 and sl2[1][1]-sl2[0][1]
        
        return res + max(z.values())