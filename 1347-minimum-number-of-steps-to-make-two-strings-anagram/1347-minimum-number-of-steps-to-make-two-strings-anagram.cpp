class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>aman;
        int answer=0;
        for(auto i:s)aman[i]++;
        for(auto i:t)aman[i]--;
        for(auto i:aman)answer+=abs(i.second);
        return answer/2;
        
    }
};