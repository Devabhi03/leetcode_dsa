class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        return len(s) >= k and sum(s.count(i) % 2 for i in set(s)) <= k