class Solution {
private:
    int func(vector<int>& nums,int n,vector<int>& dp){
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int npick = func(nums,n-1,dp);
        int pick = nums[n]+func(nums,n-2,dp);
        return dp[n] = max(pick,npick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return func(nums,n-1,dp);
    }
};