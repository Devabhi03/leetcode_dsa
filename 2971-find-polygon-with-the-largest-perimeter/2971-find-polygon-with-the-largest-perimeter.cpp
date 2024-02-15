class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long totalSum = 0;
        for(auto i : nums) totalSum += i;
        for(int i = n - 1; i >= 2; i--){
            totalSum -= nums[i];
            if(totalSum > nums[i]){
                return totalSum + nums[i];
            }
        }
        return -1;
    }
};