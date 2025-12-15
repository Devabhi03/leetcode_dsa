class Solution:
   def cntWays(self, arr):
    n=len(arr)
    total_even,total_odd=0,0
    for i in range(n):
        if i&1:
            total_odd+=arr[i]
        else:
            total_even+=arr[i]
    ans=0
    pre_even,pre_odd=0,0
    for i in range(n):
        if i&1:
            total_odd-=arr[i]
        else:
            total_even-=arr[i]
        new_even=pre_even+total_odd
        new_odd=pre_odd+total_even
        if new_even==new_odd:
            ans+=1
        if i&1:
            pre_odd+=arr[i]
        else:
            pre_even+=arr[i]
    return ans