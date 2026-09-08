class Solution {
private:
    int func(vector<int>& nums,int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxii = INT_MIN;
        for(int k = i; k<=j; k++){
            int cost = nums[k]*nums[i-1]*nums[j+1] + func(nums,i,k-1,dp) + func(nums,k+1,j,dp);
            maxii = max(maxii, cost);
        }
        return dp[i][j] = maxii;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return func(nums,1,n,dp);
    }
};