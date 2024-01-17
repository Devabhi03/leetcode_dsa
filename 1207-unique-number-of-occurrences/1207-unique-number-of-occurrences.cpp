class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>occur;

        for(auto i :  arr){
            mpp[i]++;
        }
        for(auto it : mpp){
            if(occur[it.second]) return false;
            occur[it.second]++;
        }

        return true;
    }
};