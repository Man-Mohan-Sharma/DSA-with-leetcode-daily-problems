class Solution {
private:
    bool func(vector<int>& nums, int ind, int target,vector<vector<int>> & dp){
        if(target==0) return true;
        if(target<0) return false;
        if(ind==0) return target == nums[0];
        if(ind<0) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool npick = func(nums,ind-1,target,dp);
        bool pick = func(nums,ind-1,target-nums[ind],dp);
        return dp[ind][target] = pick||npick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto & i : nums) sum+=i;
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>((sum/2) +1 ,-1));
        return func(nums,nums.size()-1,sum/2,dp);
    }
};