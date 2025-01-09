class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        l=len(pref)
        cnt=0
        for i in words:
            if(i[0:l]==pref):
                cnt+=1
        return cnt