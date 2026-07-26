class Solution {
private:
    int func(int m, int n,vector<vector<int>>& dp){
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int left = func(m,n-1,dp);
        int right = func(m-1,n,dp);
        return dp[m][n] = left+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }
};