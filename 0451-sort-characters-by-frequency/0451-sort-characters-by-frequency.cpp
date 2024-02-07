class Solution {
public:
    static bool cmp(const pair<char,int>& a, const pair<char,int>& b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(auto &i : s){
            mp[i]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);
        for(auto& p : v){
            while(p.second--){
                ans += p.first;
            }
        }
        return ans;
    }
};