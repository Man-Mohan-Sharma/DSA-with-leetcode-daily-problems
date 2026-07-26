class Solution {
    private:
    int func(vector<vector<int>>& obstacle, int m, int n,vector<vector<int>>& dp){
        if(n<0 || m<0) return 0;
        if(obstacle[m][n]==1) return 0;
        if(n==0 && m==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int left = func(obstacle,m,n-1,dp);
        int right = func(obstacle,m-1,n,dp);
        return dp[m][n] = left+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(obstacleGrid,m-1,n-1,dp);
    }
};