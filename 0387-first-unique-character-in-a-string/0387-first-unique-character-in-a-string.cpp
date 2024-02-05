class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alphabets(26);
        for(auto i:s) alphabets[i - 'a']++;
        for(int i = 0;i<s.size();i++) {
            if(alphabets[s[i] - 'a'] == 1) return i;
        }
        return -1;

    }
};