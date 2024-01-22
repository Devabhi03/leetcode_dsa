class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2);
        vector<int>ans(n+1,0);
        for(int i =0 ; i<n;i++){
            int val = nums[i];
            ans[val]++;
        }
        for(int i=1; i < n+1; i++){
            int occ = ans[i];
            if(occ == 2) res[0] = i;
            if(occ == 0) res[1] = i;

        }
        return res;

    }
};