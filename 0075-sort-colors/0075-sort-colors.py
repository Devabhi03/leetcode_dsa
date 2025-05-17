class Solution(object):
    def sortColors(self, nums):
        cz,co,ct=0,0,0
        for i in range(len(nums)):
            if nums[i]==0:
                cz+=1
            elif nums[i]==1:
                co+=1
            else:
                ct+=1
        index=0
        for _ in range(cz):
            nums[index]=0
            index+=1
        for _ in range(co):
            nums[index]=1
            index+=1
        for _ in range(ct):
            nums[index]=2
            index+=1
        return nums