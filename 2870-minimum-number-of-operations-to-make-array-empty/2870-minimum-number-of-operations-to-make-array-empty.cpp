class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]]++;
        }

        int ans = 0;
        for(auto it : mpp){
            int freq = it.second;
            if(freq == 1){
                return -1;
            }

            ans += ceil((double)freq/3);

        }

        return ans;
    }
};