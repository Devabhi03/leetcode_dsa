class Solution:
    def findTwoElement(self, arr):
      
        n=len(arr)
        su=(n*(n+1))//2
        sq_su=(n*(n+1)*(2*n+1))//6
        s=0
        sq=0
        for i in arr:
            s+=i
            sq+=i*i
        amb=s-su
        asmbs=sq-sq_su
        apb=asmbs//amb
        a=(amb+apb)//2
        b=apb-a
        return [a,b]