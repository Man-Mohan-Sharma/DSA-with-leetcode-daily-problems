class Solution {
private:
    int func(vector<vector<int>>& grid, int n, int m,vector<vector<int>>& dp){
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        int up = func(grid,n-1,m,dp);
        if(up!=INT_MAX) up+=grid[n][m];
        int left = func(grid,n,m-1,dp);
        if(left!=INT_MAX) left+=grid[n][m];
        return dp[n][m] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return func(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};