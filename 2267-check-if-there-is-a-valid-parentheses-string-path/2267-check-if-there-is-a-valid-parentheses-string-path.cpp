class Solution {
private:
    bool func(vector<vector<char>>& grid, int i, int j, int count,vector<vector<vector<int>>>& dp){
        if(count<0) return false;
        if(i==0 && j==0) return count==0;
        if(dp[i][j][count]!=-1) return dp[i][j][count];
        bool up = false;
        if(i>0) up = func(grid,i-1,j,count+(grid[i-1][j]==')'?1:-1),dp);
        bool left = false;
        if(j>0) left = func(grid,i,j-1,count+(grid[i][j-1]==')'?1:-1),dp);
        return dp[i][j][count] = up||left;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size()-1, m = grid[0].size()-1;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+n+2,-1)));
        return func(grid,n,m,(grid[n][m]==')'?1:-1),dp);
    }
};