class Solution:
    digit = [0] * 64
    def palindrome(self, x: int , k : int) -> bool:
        digit = []
        while x > 0:
            digit.append(x % k)
            x //= k
        return digit == digit[::-1]

    def isPalindrome(self, mid: int, odd: bool) -> int:
        if odd:
            return mid * (10 ** (len(str(mid)) - 1)) + self.reverse(mid // 10)
        else:
            return mid * (10 ** len(str(mid))) + self.reverse(mid)

    def reverse(self, x: int) -> int:
        res = 0
        while x > 0:
            res = res * 10 + x % 10
            x //= 10
        return res

    def kMirror(self, k: int, n: int) -> int:
        total = 0
        length = 1
        while True:
            mid = (length + 1) // 2
            start = 10 ** (mid - 1)
            for i in range(start, 10 ** mid):
                pal = self.isPalindrome(i, length % 2 == 1)
                if self.palindrome(pal, k):
                    total += pal
                    n -= 1
                    if n == 0:
                        return total
            length += 1
