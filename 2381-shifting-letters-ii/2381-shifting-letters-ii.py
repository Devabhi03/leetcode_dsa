class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        track = [0]*(n+1)

        for l, r, direc in shifts:
            move = 1 if direc == 1 else -1
            track[l] += move
            track[r+1] -= move

        res = []
        for i in range(n):
            if i >= 1:
                track[i] += track[i-1]
                
            new_char = (ord(s[i]) - ord('a') + track[i]) % 26
            if new_char < 0:
                new_char += 26

            res.append(chr(ord('a') + new_char))

        return ''.join(res)