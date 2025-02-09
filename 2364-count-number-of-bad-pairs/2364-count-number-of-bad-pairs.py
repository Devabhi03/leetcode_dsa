class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        freq = {}
        count = 0
        for i, num in enumerate(nums):
            key = num - i
            count += freq.get(key, 0)
            freq[key] = freq.get(key, 0) + 1

        return (n * (n - 1) // 2) - count