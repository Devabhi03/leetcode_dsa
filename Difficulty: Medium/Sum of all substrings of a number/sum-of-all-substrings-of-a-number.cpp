class Solution {
    public:
    int calculate(string& s, int start, int end)
    {
        int val = 0;
        int res = 0;
        for(int i = start; i < end; i++)
        {
            val = val * 10 + s[i] - '0';
            res += val;
        }
        return res;
    }
    int sumSubstrings(string &s) {
        // code here
        int sum = 0;
        int startpos = 0;
        int n = s.size();
        while( startpos < n && s[startpos] == 0)
            startpos++;
        for(int i = startpos; i < n; i++)
        {
            sum += calculate(s, i, n);
        }
        if(s[0] == '-' || s[startpos] == '-')
            sum = -sum;
        return sum;
    }
};