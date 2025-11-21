class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = 0
        l, r = {}, {}
        for idx, c in enumerate(s):
            if c not in l:
                l[c] = idx
            r[c] = idx
        
        for c_l, c_l_idx in l.items():
            c_r_idx = r[c_l]
            res += len(set(s[c_l_idx + 1 : c_r_idx]))
            
        return res