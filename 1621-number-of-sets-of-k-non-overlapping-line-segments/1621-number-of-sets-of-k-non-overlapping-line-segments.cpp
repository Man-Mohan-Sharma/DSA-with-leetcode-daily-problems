class Solution {
    int mod = 1e9+7;
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        for(int i = 0; i<n; i++) dp[0][i] = 1;
        for(int i = 1; i<=k; i++){
            vector<int> pre(n+1,0);
            for(int j = n-1; j>=0; j--){
                pre[j] = (pre[j+1]+dp[i-1][j])%mod;
            }
            for(int j = n-1; j>=0; j--){
                int skip = dp[i][j+1]%mod;
                int total = pre[j+1]%mod;
                dp[i][j] = (skip+total)%mod;
            }
        }
        return dp[k][0];
    }
};