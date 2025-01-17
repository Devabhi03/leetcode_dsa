class Solution:
    def doesValidArrayExist(self, d: List[int]) -> bool:
        n = len(d)
        o = [0] * (n + 1)  # Array to store the sequence
        
        # First case: Assume o[0] = 0 and compute the sequence
        o[0] = 0
        for i in range(n):
            o[i + 1] = d[i] ^ o[i]
        valid0 = (o[0] == o[n])  # Check if the first and last elements match

        # Second case: Assume o[0] = 1 and compute the sequence
        o[0] = 1
        for i in range(n):
            o[i + 1] = d[i] ^ o[i]
        valid1 = (o[0] == o[n])  # Check if the first and last elements match

        # Return true if either case produces a valid sequence
        return valid0 or valid1