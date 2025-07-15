import sys
sys.set_int_max_str_digits(100000)
class Solution:
    def divby13(self, s):
        # code here 
        return int(s) % 13 == 0