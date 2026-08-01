class Solution {
private:
    long long game(vector<int>& nums, int i , int j,vector<vector<int>> & dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        long long taken_i = nums[i]+ min(game(nums,i+1,j-1,dp),game(nums,i+2,j,dp));
        long long taken_j = nums[j] + min(game(nums,i+1,j-1,dp),game(nums,i,j-2,dp));
        return dp[i][j] = max(taken_i, taken_j);
    } 
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        long long sum = 0;
        for(auto i : nums) sum+=i;
        long long player_1 = game(nums,0,nums.size()-1,dp);
        return player_1 >= sum-player_1;
    }
};