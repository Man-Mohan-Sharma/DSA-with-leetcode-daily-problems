class Solution {
private:
    int func(vector<int>& nums, int i,vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int rob = nums[i] + func(nums,i-2,dp);
        int nrob = func(nums,i-1,dp);
        return dp[i] = max(rob,nrob);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return func(nums,nums.size()-1,dp);
    }
};